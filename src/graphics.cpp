// ============================================
// The Graphics class file
//==================================================================


#include "graphics.h"

#include "globals.h"

#define BLACK 0x000000
#define DGREEN 0x013220
#define BROWN 0xD2691E
#define YELLOW 0xFFFF00

void draw_nothing(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, BLACK);
}

void draw_img(int u, int v, const char* img)
{
    int colors[11*11];
    for (int i = 0; i < 11*11; i++)
    {
        if (img[i] == 'R') colors[i] = RED;
        else if (img[i] == 'Y') colors[i] = 0xFFFF00;   // Yellow
        else if (img[i] == 'G') colors[i] = GREEN;
        else if (img[i] == 'D') colors[i] = 0xD2691E;   // "Dirt"
        else if (img[i] == '5') colors[i] = LGREY;      // 50% grey
        else if (img[i] == '3') colors[i] = DGREY;
        else colors[i] = BLACK;
    }
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250); // Recovery time!
}

void draw_wall(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[11*11];
    for (int i = 0; i < 11*11; i++)
    {
        if(i % 2 == 0) {
            colors[i] = RED;
        } else {
            colors[i] = WHITE;
        }
    }
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}

void draw_plant(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    
        int img[121] = {
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BROWN, BROWN, BROWN, BLACK, BLACK, BLACK, BLACK
    };
    uLCD.BLIT(u, v, 11, 11, img);
    wait_us(250);
    
}

void draw_chest(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int img[121] = {
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
        BLACK, BLACK, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BLACK, BLACK,
        BLACK, BLACK, BROWN, BROWN, YELLOW, YELLOW, YELLOW, BROWN, BROWN, BLACK, BLACK,
        BLACK, BLACK, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, BLACK, BLACK,
        BLACK, BLACK, BROWN, BROWN, BROWN, YELLOW, BROWN, BROWN, BROWN, BLACK, BLACK, 
        BLACK, BLACK, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BROWN, BLACK, BLACK 
    };
    uLCD.BLIT(u, v, 11, 11, img);
    wait_us(250);
}

void draw_boostUp(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[121] = { BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       GREEN, GREEN, GREEN, GREEN, GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, 
                       GREEN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, GREEN, 
                       GREEN, GREEN, GREEN, GREEN, GREEN, WHITE, GREEN, GREEN, GREEN, GREEN, GREEN, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, GREEN, WHITE, GREEN, BLACK, BLACK, BLACK, BLACK
                       };
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}


void draw_boostDown(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[121] = {BLACK, BLACK, BLACK, BLACK, RED, WHITE, RED, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, RED, WHITE, RED, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, RED, WHITE, RED, BLACK, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, RED, WHITE, RED, BLACK, BLACK, BLACK, BLACK, 
                       RED, RED, RED, RED, RED, WHITE, RED, RED, RED, RED, RED, 
                       RED, RED, RED, RED, RED, WHITE, RED, RED, RED, RED, RED,  
                       RED, RED, RED, RED, RED, WHITE, RED, RED, RED, RED, RED,  
                       BLACK, RED, RED, RED, RED, WHITE, RED, RED, RED, RED, RED, 
                       BLACK, BLACK, RED, RED, RED, WHITE, RED, RED, RED, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, RED, RED, WHITE, RED, RED, BLACK, BLACK, BLACK, 
                       BLACK, BLACK, BLACK, BLACK, RED, WHITE, RED, BLACK, BLACK, BLACK, BLACK};
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}

void draw_slowSpeed(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[121] = {BLACK, BLACK, BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN,
                        BLACK, BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, 
                        BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK, 
                        BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK, BLACK,
                        RED, BLACK, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK, BLACK, BLACK,
                        RED, GREEN, GREEN, GREEN, GREEN, GREEN,BLACK, BLACK, BLACK, BLACK, BLACK,
                        BLACK, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK, BLACK, BLACK,
                        BLACK, BLACK, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK, BLACK,
                        BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK, BLACK,
                        BLACK, BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, BLACK,
                        BLACK, BLACK, BLACK, BLACK, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN
                        };
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}

void draw_speedUp(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[121] = {YELLOW, YELLOW, YELLOW, YELLOW,  RED, BLACK, RED, BLACK, BLACK, BLACK, BLACK,
                        BLACK, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED, BLACK, BLACK, BLACK, BLACK,
                        RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED, BLACK, BLACK, BLACK,
                        RED, RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED, BLACK, BLACK,
                        BLACK, BLACK, RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED, BLACK,
                        BLACK, BLACK, BLACK, RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED,
                        BLACK, BLACK, BLACK, RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED,
                        BLACK, BLACK, RED, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, RED, BLACK,
                        BLACK, BLACK, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, BLACK, BLACK, BLACK,
                        BLACK, RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, BLACK, BLACK, BLACK, BLACK,
                        RED, YELLOW, YELLOW, YELLOW, YELLOW,  RED, BLACK, BLACK, BLACK, BLACK, BLACK
                        };
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}

void draw_addLife(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int colors[121] = { RED, RED, RED, RED,  RED, RED, RED, RED, RED, RED, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
                        RED, RED, RED, RED,  RED, RED, RED, RED, RED, RED, RED,
                        RED, RED, RED, RED,  RED, RED, RED, RED, RED, RED, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, WHITE, WHITE, WHITE,  RED, RED, RED, WHITE, WHITE, WHITE, RED,
                        RED, RED, RED, RED,  RED, RED, RED, RED, RED, RED, RED
                        };
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250);
}


void draw_viper_body(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int img[121] = {
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN 
    };
    uLCD.BLIT(u, v, 11, 11, img);
    wait_us(250);
}

void draw_viper_head(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    int img[121] = {
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, RED, RED, RED, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, 
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN 
    };
    uLCD.BLIT(u, v, 11, 11, img);
    wait_us(250);
}

void draw_viper_tail(int u, int v)
{
    // TODO: Implement
    //May need to design a viper tail sprite
    //Tile still need to be designed on paper
    int img[121] = {
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, 
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, 
        RED, RED, RED, GREEN, GREEN, GREEN, GREEN, GREEN, RED, GREEN, RED, 
        RED, RED, RED, GREEN, GREEN, GREEN, GREEN, RED, GREEN, GREEN, RED,
        RED, RED, GREEN, RED, GREEN, GREEN, RED, GREEN, GREEN, GREEN, RED,
        RED, RED, GREEN, GREEN, RED, RED, GREEN, GREEN, GREEN, GREEN, RED,
        RED, RED, GREEN, GREEN, RED, RED, GREEN, GREEN, GREEN, GREEN, RED,
        RED, RED, GREEN, RED, GREEN, GREEN, RED, GREEN, GREEN, GREEN, RED, 
        RED, RED, RED, GREEN, GREEN, GREEN, GREEN, RED, GREEN, GREEN, RED, 
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, 
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED
    };
    uLCD.BLIT(u, v, 11, 11, img);
    wait_us(250);
}
