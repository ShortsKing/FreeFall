
#include "src\LCDWIKI_GUI\LCDWIKI_GUI.h" //Core graphics library
#include "src\LCDWIKI_KBV\LCDWIKI_KBV.h" //Hardware-specific library
#include "src\EEPROM\src\EEPROM.h" //Memory library for storing the high score

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

int lives = 3;

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

int spr1side = 0;
int spr1length = 0;
int spr2side = 0;
int spr2length = 0;

void load_lives(int lives) {
  if (lives == 3) {
    //heart1
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9, mylcd.Get_Display_Height()-4, 11, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8, mylcd.Get_Display_Height()-5, 12, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7, mylcd.Get_Display_Height()-6, 13, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6, mylcd.Get_Display_Height()-7, 14, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-8, 15, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-9, 16, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-10, 17, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-11, 17, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-12, 9, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11, mylcd.Get_Display_Height()-12, 17, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-13, 8, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12, mylcd.Get_Display_Height()-13, 17, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-14, 7, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13, mylcd.Get_Display_Height()-14, 16, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-11, 5, mylcd.Get_Display_Height()-10);
    
    //heart2
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18, mylcd.Get_Display_Height()-4, 11+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18, mylcd.Get_Display_Height()-5, 12+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18, mylcd.Get_Display_Height()-6, 13+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18, mylcd.Get_Display_Height()-7, 14+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-8, 15+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-9, 16+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-10, 17+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-11, 17+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-12, 9+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18, mylcd.Get_Display_Height()-12, 17+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-13, 8+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18, mylcd.Get_Display_Height()-13, 17+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-14, 7+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18, mylcd.Get_Display_Height()-14, 16+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-11, 5+18, mylcd.Get_Display_Height()-10);
    
    //heart3
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18+18, mylcd.Get_Display_Height()-4, 11+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18+18, mylcd.Get_Display_Height()-5, 12+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18+18, mylcd.Get_Display_Height()-6, 13+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18+18, mylcd.Get_Display_Height()-7, 14+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-8, 15+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-9, 16+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-10, 17+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-11, 17+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-12, 9+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18+18, mylcd.Get_Display_Height()-12, 17+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-13, 8+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18+18, mylcd.Get_Display_Height()-13, 17+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-14, 7+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18+18, mylcd.Get_Display_Height()-14, 16+18+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-11, 5+18+18, mylcd.Get_Display_Height()-10);
    
  }
  else if (lives == 2) {
    //heart1
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9, mylcd.Get_Display_Height()-4, 11, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8, mylcd.Get_Display_Height()-5, 12, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7, mylcd.Get_Display_Height()-6, 13, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6, mylcd.Get_Display_Height()-7, 14, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-8, 15, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-9, 16, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-10, 17, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-11, 17, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-12, 9, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11, mylcd.Get_Display_Height()-12, 17, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-13, 8, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12, mylcd.Get_Display_Height()-13, 17, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-14, 7, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13, mylcd.Get_Display_Height()-14, 16, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-11, 5, mylcd.Get_Display_Height()-10);
    
    //heart2
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18, mylcd.Get_Display_Height()-4, 11+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18, mylcd.Get_Display_Height()-5, 12+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18, mylcd.Get_Display_Height()-6, 13+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18, mylcd.Get_Display_Height()-7, 14+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-8, 15+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-9, 16+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-10, 17+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-11, 17+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-12, 9+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18, mylcd.Get_Display_Height()-12, 17+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-13, 8+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18, mylcd.Get_Display_Height()-13, 17+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-14, 7+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18, mylcd.Get_Display_Height()-14, 16+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-11, 5+18, mylcd.Get_Display_Height()-10);
    
    //heart3
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(LIGHT_GRAY);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18+18, mylcd.Get_Display_Height()-4, 11+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18+18, mylcd.Get_Display_Height()-5, 12+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18+18, mylcd.Get_Display_Height()-6, 13+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18+18, mylcd.Get_Display_Height()-7, 14+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-8, 15+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-9, 16+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-10, 17+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-11, 17+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-12, 9+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18+18, mylcd.Get_Display_Height()-12, 17+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-13, 8+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18+18, mylcd.Get_Display_Height()-13, 17+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-14, 7+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18+18, mylcd.Get_Display_Height()-14, 16+18+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-11, 5+18+18, mylcd.Get_Display_Height()-10);
    
  }
  else if (lives == 1) {
    //heart1
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(RED);
    mylcd.Draw_Pixel(10, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9, mylcd.Get_Display_Height()-4, 11, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8, mylcd.Get_Display_Height()-5, 12, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7, mylcd.Get_Display_Height()-6, 13, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6, mylcd.Get_Display_Height()-7, 14, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-8, 15, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-9, 16, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-10, 17, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-11, 17, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-12, 9, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11, mylcd.Get_Display_Height()-12, 17, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3, mylcd.Get_Display_Height()-13, 8, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12, mylcd.Get_Display_Height()-13, 17, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4, mylcd.Get_Display_Height()-14, 7, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13, mylcd.Get_Display_Height()-14, 16, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5, mylcd.Get_Display_Height()-11, 5, mylcd.Get_Display_Height()-10);
    
    //heart2
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Draw_Pixel(10+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18, mylcd.Get_Display_Height()-4, 11+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18, mylcd.Get_Display_Height()-5, 12+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18, mylcd.Get_Display_Height()-6, 13+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18, mylcd.Get_Display_Height()-7, 14+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-8, 15+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-9, 16+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-10, 17+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-11, 17+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-12, 9+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18, mylcd.Get_Display_Height()-12, 17+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18, mylcd.Get_Display_Height()-13, 8+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18, mylcd.Get_Display_Height()-13, 17+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18, mylcd.Get_Display_Height()-14, 7+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18, mylcd.Get_Display_Height()-14, 16+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18, mylcd.Get_Display_Height()-11, 5+18, mylcd.Get_Display_Height()-10);
    
    //heart3
    mylcd.Set_Draw_color(BLACK);
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-2);//1st layer
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-3);//2nd layer
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-4);//3rd layer
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-5);//4th layer
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-6);//5th layer
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-7);//6th layer
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-8);//7th layer
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-9);//8th layer
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-10);//9th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-11);//10th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-12);//11th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Draw_Pixel(2+18+18, mylcd.Get_Display_Height()-13);//12th layer
    mylcd.Draw_Pixel(18+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(11+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(9+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Draw_Pixel(17+18+18, mylcd.Get_Display_Height()-14);//13th layer
    mylcd.Draw_Pixel(3+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(8+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(12+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Draw_Pixel(4+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(5+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(7+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(13+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(14+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(15+18+18, mylcd.Get_Display_Height()-15);
    mylcd.Draw_Pixel(16+18+18, mylcd.Get_Display_Height()-15);
    
    mylcd.Set_Draw_color(LIGHT_GREY);
    mylcd.Draw_Pixel(10+18+18, mylcd.Get_Display_Height()-3);
    mylcd.Fill_Rectangle(9+18+18, mylcd.Get_Display_Height()-4, 11+18+18, mylcd.Get_Display_Height()-4);
    mylcd.Fill_Rectangle(8+18+18, mylcd.Get_Display_Height()-5, 12+18+18, mylcd.Get_Display_Height()-5);
    mylcd.Fill_Rectangle(7+18+18, mylcd.Get_Display_Height()-6, 13+18+18, mylcd.Get_Display_Height()-6);
    mylcd.Fill_Rectangle(6+18+18, mylcd.Get_Display_Height()-7, 14+18+18, mylcd.Get_Display_Height()-7);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-8, 15+18+18, mylcd.Get_Display_Height()-8);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-9, 16+18+18, mylcd.Get_Display_Height()-9);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-10, 17+18+18, mylcd.Get_Display_Height()-10);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-11, 17+18+18, mylcd.Get_Display_Height()-11);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-12, 9+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(11+18+18, mylcd.Get_Display_Height()-12, 17+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(3+18+18, mylcd.Get_Display_Height()-13, 8+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(12+18+18, mylcd.Get_Display_Height()-13, 17+18+18, mylcd.Get_Display_Height()-13);
    mylcd.Fill_Rectangle(4+18+18, mylcd.Get_Display_Height()-14, 7+18+18, mylcd.Get_Display_Height()-14);
    mylcd.Fill_Rectangle(13+18+18, mylcd.Get_Display_Height()-14, 16+18+18, mylcd.Get_Display_Height()-14);
    
    mylcd.Set_Draw_color(WHITE);
    mylcd.Draw_Pixel(6+18+18, mylcd.Get_Display_Height()-12);
    mylcd.Fill_Rectangle(5+18+18, mylcd.Get_Display_Height()-11, 5+18+18, mylcd.Get_Display_Height()-10);
    
  }
}

unsigned long high_score;


unsigned long score;

long timerstart;
bool pressed1 = false;
bool pressed2 = false;
bool pressed3 = false;
bool pressed4 = false;
bool pressed5 = false;
bool pressed6 = false;

void setup() {
  mylcd.Init_LCD();
}

long gameplay(byte difficulty) {
   //generate sprite 1 variables
    randomSeed(analogRead(A0));
    int side = random(2);
    randomSeed(analogRead(A0));
    int length = random(50, 170);
  
    spr1side = side;
    spr1length = length;
  
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
  
    spr2side = side;
    spr2length = length;
  
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
    
  
    for(int i = 1; i < 25; ++i) {
      //new frame
      mylcd.Set_Draw_color(LIGHT_GREY);
      mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
      timerstart = millis();
      while(timerstart - millis() <= 200) {
        if(pressed1 == false) {
          if (analogRead(1) > 1000) {
            if (rock_x > 0) {
              rock_x -= 10;
              pressed1 = true;
            }
          }
        }
        if(pressed5 == false) {
          if (analogRead(5) > 1000) {
            if (rock_x < 300) {
              rock_x += 10;
              pressed5 = true;
            }
          }
        }
      }
      mylcd.Set_Draw_color(CYAN);
      mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
      mylcd.Set_Draw_color(CYAN);
      mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
      spr1height += 10;
      mylcd.Set_Draw_color(DARK_GREY);
      mylcd.Fill_Rectangle(x1spr1, y1spr1-spr1height, x2spr1, y2spr1-spr1height);
      if (spr1height == 230) {
        if (spr1side == 0) {
          if (rock_x < spr1length) {
            --lives;
          }
        }
        else {
          if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
            --lives;
          }
        }
      }
      if (lives == 0) {
        lives = 3;
        //TERMINATE
        return score;
        //TERMINATE
      }
      load_lives(lives);
    }
    //add sprite 2
    for(int i = 1; i < 25; ++i) {
      //new frame
      mylcd.Set_Draw_color(CYAN);
      mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
      timerstart = millis();
      while(timerstart - millis() <= 200) {
        if(pressed1 == false) {
          if (analogRead(1) > 1000) {
            if (rock_x > 0) {
              rock_x -= 10;
              pressed1 = true;
            }
          }
        }
        if(pressed5 == false) {
          if (analogRead(5) > 1000) {
            if (rock_x < 300) {
              rock_x += 10;
              pressed5 = true;
            }
          }
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
      if (spr1height == 230) {
        if (spr1side == 0) {
          if (rock_x < spr1length) {
            --lives;
          }
        }
        else {
          if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
            --lives;
          }
        }
      }
      if (spr2height == 230) {
        if (spr2side == 0) {
          if (rock_x < spr2length) {
            --lives;
          }
        }
        else {
          if ((rock_x+20) > (mylcd.Get_Display_Width() - spr2length)) {
            --lives;
          }
        }
      }
      if (lives == 0) {
        lives = 3;
        //TERMINATE
        return score;
        //TERMINATE
      }
      load_lives(lives);
    }
  
  
  
  side = 0;
  length = 0;
  
  //begin automated section of game
  while(true) {
    //re-randomize sprite 1 size
    randomSeed(analogRead(A0));
    side = random(2);
    randomSeed(analogRead(A0));
    length = random(50, 170);
    
    spr1side = side;
    spr1length = length;
    
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
    timerstart = millis();
    while(timerstart - millis() <= 200) {
      if(pressed1 == false) {
        if (analogRead(1) > 1000) {
          if (rock_x > 0) {
            rock_x -= 10;
            pressed1 = true;
          }
        }
      }
      if(pressed5 == false) {
        if (analogRead(5) > 1000) {
          if (rock_x < 300) {
            rock_x += 10;
            pressed5 = true;
          }
        }
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
  if (spr1height == 230 ) {
      if (spr1side == 0) {
        if (rock_x < spr1length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
          --lives;
        }
      }
    }
    if (spr2height == 230) {
      if (spr2side == 0) {
        if (rock_x < spr2length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr2length)) {
          --lives;
        }
      }
    }
    if (lives == 0) {
      lives = 3;
      //TERMINATE
      return score;
      //TERMINATE
    }
  load_lives(lives);
    
  for(int i = 1; i < 24; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    timerstart = millis();
      while(timerstart - millis() <= 200) {
        if(pressed1 == false) {
          if (analogRead(1) > 1000) {
            if (rock_x > 0) {
              rock_x -= 10;
              pressed1 = true;
            }
          }
        }
        if(pressed5 == false) {
          if (analogRead(5) > 1000) {
            if (rock_x < 300) {
              rock_x += 10;
              pressed5 = true;
            }
          }
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
    if (spr1height == 230) {
      if (spr1side == 0) {
        if (rock_x < spr1length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
          --lives;
        }
      }
    }
    if (spr2height == 230) {
      if (spr2side == 0) {
        if (rock_x < spr2length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr2length)) {
          --lives;
        }
      }
    }
    if (lives == 0) {
      lives = 3;
      //TERMINATE
      return score;
      //TERMINATE
    }
    load_lives(lives);
  }
  
  //re-randomize sprite 2 size
  randomSeed(analogRead(A0));
  side = random(2);
  randomSeed(analogRead(A0));
  length = random(50, 170);
  
  spr2side = side;
  spr2length = length;
  
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
    timerstart = millis();
      while(timerstart - millis() <= 200) {
        if(pressed1 == false) {
          if (analogRead(1) > 1000) {
            if (rock_x > 0) {
              rock_x -= 10;
              pressed1 = true;
            }
          }
        }
        if(pressed5 == false) {
          if (analogRead(5) > 1000) {
            if (rock_x < 300) {
              rock_x += 10;
              pressed5 = true;
            }
          }
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
  if (spr1height == 230) {
      if (spr1side == 0) {
        if (rock_x < spr1length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
          --lives;
        }
      }
    }
    if (spr2height == 230) {
      if (spr2side == 0) {
        if (rock_x < spr2length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr2length)) {
          --lives;
        }
      }
    }
    if (lives == 0) {
      lives = 3;
      //TERMINATE
      return score;
      //TERMINATE
    }
  load_lives(lives);
  
  for(int i = 1; i < 24; ++i) {
    //new frame
    mylcd.Set_Draw_color(CYAN);
    mylcd.Fill_Rectangle(rock_x, 230, rock_x+20, 250);
    timerstart = millis();
      while(timerstart - millis() <= 200) {
        if(pressed1 == false) {
          if (analogRead(1) > 1000) {
            if (rock_x > 0) {
              rock_x -= 10;
              pressed1 = true;
            }
          }
        }
        if(pressed5 == false) {
          if (analogRead(5) > 1000) {
            if (rock_x < 300) {
              rock_x += 10;
              pressed5 = true;
            }
          }
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
    if (spr1height == 230) {
      if (spr1side == 0) {
        if (rock_x < spr1length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr1length)) {
          --lives;
        }
      }
    }
    if (spr2height == 230) {
      if (spr2side == 0) {
        if (rock_x < spr2length) {
          --lives;
        }
      }
      else {
        if ((rock_x+20) > (mylcd.Get_Display_Width() - spr2length)) {
          --lives;
        }
      }
    }
    if (lives == 0) {
      lives = 3;
      //TERMINATE
      return score;
      //TERMINATE
    }
    load_lives(lives);
  }
}
}


byte startscreen() {
  byte difficulty = 1;
  
    while(true) {
      //start screen
      mylcd.Set_Text_Back_colour(CYAN);
      mylcd.Fill_Screen(CYAN);
      mylcd.Set_Text_colour(MAGENTA);
      mylcd.Set_Text_Size(14);
      mylcd.Print_String("NOSE", 0, 0);
      mylcd.Print_String("DIVE", 0, 100);
      mylcd.Set_Draw_color(MAGENTA);
      mylcd.Draw_Fast_HLine(0, 430, 320);
      mylcd.Draw_Fast_HLine(0, 431, 320);
      mylcd.Draw_Fast_HLine(0, 432, 320);
      mylcd.Draw_Fast_HLine(0, 433, 320);
      mylcd.Draw_Fast_HLine(0, 434, 320);
      mylcd.Set_Text_Size(4);
      mylcd.Print_String("Difficulty:", 5, 439);
      mylcd.Print_String("High Score:", 5, 390);
      timerstart = millis();
      while(true) {
        if(millis() - timerstart == 1023) {
          break;
        }
        if(analogRead(3) == 1023) {
          return difficulty;
        }
      }
    }
}

long game_over() {
  EEPROM.get(0, high_score);
  while(true) {
    //start screen
    mylcd.Set_Text_Back_colour(CYAN);
    mylcd.Fill_Screen(CYAN);
    mylcd.Set_Text_colour(MAGENTA);
    mylcd.Set_Text_Size(14);
    mylcd.Print_String("GAME", 0, 0);
    mylcd.Print_String("OVER", 0, 100);
    mylcd.Set_Draw_color(MAGENTA);
    mylcd.Draw_Fast_HLine(0, 430, 320);
    mylcd.Draw_Fast_HLine(0, 431, 320);
    mylcd.Draw_Fast_HLine(0, 432, 320);
    mylcd.Draw_Fast_HLine(0, 433, 320);
    mylcd.Draw_Fast_HLine(0, 434, 320);
    mylcd.Set_Text_Size(4);
    mylcd.Print_String("Difficulty:", 5, 439);
    mylcd.Print_String("High Score:", 5, 390);
    timerstart = millis();
    while(true) {
      if(millis() - timerstart == 1023) {
        break;
      }
      if(analogRead(3) == 1023) {
        return high_score;
      }
    }
  }
}

void loop() {
  byte difficulty;
  difficulty = startscreen();
  score = gameplay(difficulty);
  game_over();
  
  
}
