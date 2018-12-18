#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h> 
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/gpio.h>
#include <linux/cdev.h>

static dev_t first; // Global variable for the first device number
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class

static char command[256];
static char response[256];
int have_command = 0;

static ssize_t my_write(struct file *file1,const char *buffer,size_t count,loff_t *offset1){
    int ret;

    if( count > sizeof(command)-1 )
        count = sizeof(command)-1;

    ret = raw_copy_from_user( command, buffer, count );
    if( ret != 0 )
        return -EINVAL;
    
    command[count] = '\0';

    // parse command here and execute it
    switch( command[0] )
    {
        case 's': 
            // TODO: set led
            strcpy( response, "OKd\n" );
            break;
        case 'c': 
            // TODO: clear led
            strcpy( response, "OK\n" );
            break;
        default: 
            strcpy( response, "ERROR: unknown command\n" ); 
    }

    have_command = 1;
    return count;
}

static ssize_t my_read(struct file *file1, char *buffer,size_t count,loff_t *offset1){
    int ret;

    if( 0==have_command )
        return 0; // we already have sent a response and wait for a "write command" operation

    if( count > strlen(response) )
        count = strlen(response);

    ret = raw_copy_to_user( buffer, response, strlen(response) );
    if( ret != 0 )
        return -EINVAL;

    have_command = 0;
    return count;
}

static struct file_operations my_fops=
{
    .owner = THIS_MODULE,
    .read = my_read,
    .write = my_write
};

static int __init my_init(void)
{
    if(alloc_chrdev_region (&first,0,1,"my_device") < 0)
    {
        printk("can't register...\n");
        return -1;
    }

    printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));

    if ((cl = class_create(THIS_MODULE, "my_class")) == NULL)
    {
        unregister_chrdev_region(first, 1);
        return -1;
    }

    if (device_create(cl, NULL, first, NULL, "my_dvfile") == NULL)
    {
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return -1;
    }

    cdev_init(&c_dev, &my_fops);

    if (cdev_add(&c_dev, first, 1) == -1)
    {
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return -1;
    }

    return 0;
}

static void __exit my_exit(void)
{
    cdev_del(&c_dev);
    device_destroy(cl, first);

    class_destroy(cl);
    unregister_chrdev_region(first, 1);

    printk(KERN_INFO "driver unregistered");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
