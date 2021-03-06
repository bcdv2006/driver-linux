﻿#define DELETE 0
#define MIRROR 1
#define NO_MIRROR 0
#define CLEAR 0
#define BLACK 1
#define WHITE 0
#define black 1
#define  white 0
#define LCDWIDTH 84
#define LCDHEIGHT 48
#define X_MAX 83
#define Y_MAX 47

#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF


#define PCD8544_POWERDOWN 0x04
#define PCD8544_ENTRYMODE 0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01

#define PCD8544_DISPLAYBLANK 0x0
#define PCD8544_DISPLAYNORMAL 0x4
#define PCD8544_DISPLAYALLON 0x1
#define PCD8544_DISPLAYINVERTED 0x5

#define CMD_SET_DISP_NORMAL 0xC

#define MASK_Y_ADDRESS 0x40
#define MASK_X_ADDRESS 0x80

#define CMD_SET_DISP_REVERSE 0xD

#define CMD_SET_DISP_REVERSE 0xD

// H = 0
#define PCD8544_FUNCTIONSET 0x20
#define PCD8544_DISPLAYCONTROL 0x08
#define PCD8544_SETYADDR 0x40
#define PCD8544_SETXADDR 0x80

// H = 1
#define PCD8544_SETTEMP 0x04
#define PCD8544_SETBIAS 0x10
#define PCD8544_SETVOP 0x80
#define PCD8544_SPI_CLOCK_DIV SPI_CLOCK_DIV4

#define _cs   3
#define _dc   4
#define _din  5
#define _clk  6 
char buffer_PCD8544[504] = {};
char clear[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bird_high[]={112,136,776,1292,1290,2194,2145,2049,2333,2723,1345,1345,1370,1348,1400,832,128};
char bird[] = { 112, 136, 8, 12, 10, 146, 97, 1, 29, 163, 65, 65, 90, 68, 120, 64, 128, 0, 0, 3,  5,  5,   8,  8, 8,  9,  10,  5,  5,  5,  5,   5,  3,   0}; 


unsigned char backgroud [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0x60, 0x38, 0x0C, 0x04, 0x06, 0x02, 0x02,
0x03, 0x01, 0x01, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x80, 0x80, 0x80, 0x60, 0x30, 0x18,
0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x0C, 0x18, 0x30,
0x60, 0x40, 0x40, 0x60, 0x30, 0x10, 0x18, 0x08, 0x08, 0x04, 0x04, 0x06, 0x03, 0x01, 0x01, 0x01,
0x03, 0x06, 0x0C, 0x18, 0x10, 0x30, 0x20, 0x60, 0x40, 0x40, 0x40, 0x40, 0x20, 0x30, 0x10, 0x08,
0x0C, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x18, 0x60, 
};


////////////////////////////////////////////////////////
char i=0;char j = 0;

////////////////////////////////////////////////////////
void send_DATA(char DATA);
void send_COMMAND(char COMMAND);
void LCD_init();
void draw_pixel(char col, char row, char data);
void picture(char _xsize, char _xpos, char _ypos, char _ysize, char *pic);
void gotoXY_pixel(char x, char y);
void show_bird(char _xsize, char _ysize, char _xpos, char _ypos, char num, int *object);
void show_backgroud();


void setup()
{
  Serial.begin(9600);
  LCD_init();
  show_bird(17,2,0,0,2,bird_high);

  
}
void loop()
{
  show_backgroud();
}
void send_DATA(char DATA)
{
  char i = 0;
  digitalWrite(_cs,LOW);
  digitalWrite(_dc,HIGH);
  for(i=0;i<8;i++){
    if((DATA&(0x80>>i)) == (0x80>>i))digitalWrite(_din,HIGH);
    else digitalWrite(_din,LOW);
  digitalWrite(_clk,HIGH);
    delayMicroseconds(1);
    digitalWrite(_clk,LOW);
    delayMicroseconds(1);
  }
  digitalWrite(_cs,HIGH);

}
void send_COMMAND(char COMMAND)
{
  
  digitalWrite(_cs,LOW);
  digitalWrite(_dc,LOW);
  for(i = 0;i<8;i++){
    if((COMMAND&(0x80>>i)) == (0x80>>i))digitalWrite(_din,HIGH);
    else digitalWrite(_din,LOW);
  digitalWrite(_clk,HIGH);
    delayMicroseconds(1);
    digitalWrite(_clk,LOW);
    delayMicroseconds(1);
  }
  digitalWrite(_cs,HIGH);
}
void LCD_init() 
{
  pinMode(_cs, OUTPUT);
  pinMode(_din,OUTPUT);
  pinMode(_clk,OUTPUT);
  pinMode(_dc, OUTPUT);
  digitalWrite(_cs,LOW);
  send_COMMAND(PCD8544_FUNCTIONSET|PCD8544_EXTENDEDINSTRUCTION);
  send_COMMAND(PCD8544_SETVOP|16);
  send_COMMAND(PCD8544_FUNCTIONSET);
  send_COMMAND(PCD8544_DISPLAYCONTROL|PCD8544_DISPLAYNORMAL);
  digitalWrite(_cs,HIGH);
}
void draw_pixel(char col, char row, char data)
{
  int i = 0;
  if(col > 83)col = 83;
  if(row >5)row = 5;

  buffer_PCD8544[(row*84)+col] = data;

  for(i = 0; i<504;i++){
    send_DATA(buffer_PCD8544[i]);
  }  
}
void picture(char _xsize, char _ysize, char _xpos, char _ypos, char *pic  )
{
  char x = 0, y= 0;
  for(y = 0; y<_ysize; y++){
    for(x = 0; x <_xsize; x++){
      gotoXY_pixel(x+_xpos,y+_ypos);
      send_DATA(*(pic + x + (y*_xsize)));
    }
  }
}
void gotoXY_pixel(char x, char y)
{
  /////////////////////SET Y-ADDRESS OF RAM/////////////////
  digitalWrite(_cs,LOW);
  digitalWrite(_dc,LOW);
  if(y<0)y=0;
  if(y>5)y=5;
  send_COMMAND(MASK_Y_ADDRESS|y);
  digitalWrite(_cs,HIGH);
  /////////////////////SET X-ADDRESS OF RAM/////////////////
  digitalWrite(_cs,LOW);
  digitalWrite(_dc,LOW);
  if(x<0)x=0;
  if(x>83)x=83;
  send_COMMAND(MASK_X_ADDRESS|x);
  digitalWrite(_cs,HIGH);
}
void show_bird(char _xsize, char _ysize, char _xpos, char _ypos,char num, int *object)
{
  char pos = 0;
  int temp = 0;
  for(pos = 0; pos<_xsize; pos++){
  temp = *(object+pos);
  temp = temp<<num;
  gotoXY_pixel(_xpos+pos,0+_ypos);
  send_DATA((char)(temp));
  gotoXY_pixel(_xpos+pos, 1+_ypos);
  send_DATA((char)(((temp)& 0xff00)>>8));
  }
}
void show_backgroud()
{   
  int i = 0;
   gotoXY_pixel(0,5);
   for(i = 419;i<504;i++){ 
     send_DATA(backgroud[i]);
   }
   for(i=419;i<503;i++){
    backgroud[i]= backgroud[i+1];
   }
   backgroud[503]=backgroud[419];
   delay(100);
  
}