
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library



//the definiens of 16bit mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV mylcd(ILI9486,40,38,39,-1,41); //model,cs,cd,wr,rd,reset

//define some colour values
#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define ORANGE      0xFF8C
#define BROWN       0x79E0
#define LIGHT_GREY  0xBDF7
#define DARK_GREY   0x7BEF
#define GREEN       0x07E0
#define LIGHT_GRAY  0xBDF7
#define DARK_GRAY   0x7BEF


/*analog pin assignments go as follow: 0 - used for getting kindof random input for randomseed()  
                                       1-6 - used for input buttons  
*/


int fps = 5;

int slowness = 1000/fps;

int left = analogRead(1);
int right = analogRead(5);
int up = analogRead(2);
int down = analogRead(4);
int start = analogRead(3);
int super = analogRead(6);

int rock_x = 150;

//define variables outside of setup so they are GLOBAL
int x1spr1 = 0;
int y1spr1 = 0;
int x2spr1 = 0;
int y2spr1 = 0;

int x1spr2 = 0;
int y1spr2 = 0;
int x2spr2 = 0;
int y2spr2 = 0;


//set the sprite heights
int spr1height = 0;
int spr2height = 0;
int spr3height = 0;
int spr4height = 0;
int spr5height = 0;
int spr6height = 0;

void setup() {
  mylcd.Init_LCD();
  mylcd.Fill_Screen(CYAN);
  
  //get sprites 1 through 6 on the screen
  
  //generate sprite 1 variables
  randomSeed(analogRead(A0));
  int side = random(2);
  randomSeed(analogRead(A0));
  int length = random(50, 170);
  
  if (side == 1) {
    x1spr1 = mylcd.Get_Display_Width()-length;
    y1spr1 = mylcd.Get_Display_Height()-10; //-i
    x2spr1 = mylcd.Get_Display_Width();
    y2spr1 = mylcd.Get_Display_Height(); //-i
  }
  else {
    x1spr1 = 0;
    y1spr1 = mylcd.Get_Display_Height()-10; //-i
    x2spr1 = length;
    y2spr1 = mylcd.Get_Display_Height(); //-i
  }
  
  //generate sprite 2 variables
  randomSeed(analogRead(A0));
  side = random(2);
  randomSeed(analogRead(A0));
  length = random(50, 170);
  
  if (side == 1) {
    x1spr2 = mylcd.Get_Display_Width()-length;
    y1spr2 = mylcd.Get_Display_Height()-10; //-i
    x2spr2 = mylcd.Get_Display_Width();
    y2spr2 = mylcd.Get_Display_Height(); //-i
  }
  else {
    x1spr2 = 0;
    y1spr2 = mylcd.Get_Display_Height()-10; //-i
    x2spr2 = length;
    y2spr2 = mylcd.Get_Display_Height(); //-i
  }
  
  //actually generate sprite 1
  mylcd.Set_Draw_color(DARK_GREY);
  mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
  delay(slowness);
  
  for(int i = 1; i < 25; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    spr1height += 10;
    mylcd.Set_Draw_color(DARK_GREY);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    delay(slowness);
  }
  
  //add sprite 2
  for(int i = 1; i < 25; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    spr1height += 10;
    spr2height += 10;
    mylcd.Set_Draw_color(DARK_GREY);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    delay(slowness);
  }
  
}

int side = 0;
int length = 0;

void loop() {
  
  //re-randomize sprite 1 size
  randomSeed(analogRead(A0));
  side = random(2);
  randomSeed(analogRead(A0));
  length = random(50, 170);
  
  if (side == 1) {
    x1spr1 = mylcd.Get_Display_Width()-length;
    y1spr1 = mylcd.Get_Display_Height()-10; //-i
    x2spr1 = mylcd.Get_Display_Width();
    y2spr1 = mylcd.Get_Display_Height(); //-i
  }
  else {
    x1spr1 = 0;
    y1spr1 = mylcd.Get_Display_Height()-10; //-i
    x2spr1 = length;
    y2spr1 = mylcd.Get_Display_Height(); //-i
  }
  
  mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
  mylcd.Set_Draw_color(CYAN);
  mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
  mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
  spr1height = 0;
  spr2height += 10;
  mylcd.Set_Draw_color(DARK_GREY);
  mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
  mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
  delay(slowness);
    
  for(int i = 1; i < 24; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    spr1height += 10;
    spr2height += 10;
    mylcd.Set_Draw_color(DARK_GREY);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    delay(slowness);
  }
  
  //re-randomize sprite 2 size
  randomSeed(analogRead(A0));
  side = random(2);
  randomSeed(analogRead(A0));
  length = random(50, 170);
  
  if (side == 1) {
    x1spr2 = mylcd.Get_Display_Width()-length;
    y1spr2 = mylcd.Get_Display_Height()-10; //-i
    x2spr2 = mylcd.Get_Display_Width();
    y2spr2 = mylcd.Get_Display_Height(); //-i
  }
  else {
    x1spr2 = 0;
    y1spr2 = mylcd.Get_Display_Height()-10; //-i
    x2spr2 = length;
    y2spr2 = mylcd.Get_Display_Height(); //-i
  }
  
  mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
  mylcd.Set_Draw_color(CYAN);
  mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
  mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
  spr1height += 10;
  spr2height = 0;
  mylcd.Set_Draw_color(DARK_GREY);
  mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
  mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
  delay(slowness);
  
  for(int i = 1; i < 24; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    if (analogRead(1) > 1000) {
      if (rock_x > 0) {
        rock_x -= 10;
      }
    }
    if (analogRead(5) > 1000) {
      if (rock_x < 300) {
        rock_x += 10;
      }
    }
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    spr1height += 10;
    spr2height += 10;
    mylcd.Set_Draw_color(DARK_GREY);
    mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
    mylcd.Fill_Rectangle(x1spr2, y1spr2-spr2height, x2spr2, y2spr2-spr2height);
    delay(slowness);
  }
}
