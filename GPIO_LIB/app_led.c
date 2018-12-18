#include <stdio.h>
#include "SimpleGPIO.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int init();
int main(void)
{
	if(init() != 0){
	printf("can't init pin102\n");
	return -1;
	}
	while(1){
		gpio_set_value(102,HIGH);
		usleep(500000);
		gpio_set_value(102,LOW);
		usleep(500000);
	}
}
int init()
{
	
	if(gpio_unexport(102) != 0){
		printf("102 khong co san\n");
		return -1;
	}
	if(gpio_export(102) != 0){
		printf("Can't export for pin 102\n");
		return -1;
	}
	if(gpio_set_dir(102,OUTPUT_PIN) != 0){
		printf("can't set pin102 as output\n");
		return -1;
	}
	return 0;
}
