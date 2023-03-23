//=================================================================
// The main program file.
//
// Copyright 2022 Georgia Tech. All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must NOT be made publicly available anywhere.
//==================================================================


// PROJECT INCLUDES
#include "globals.h"
#include "hardware.h"
#include "map.h"
#include "graphics.h"
#include "viper.h"
#include "Speaker.h"

#include <math.h>
#include <stdio.h>

// Important definitions


/////////////////////////////////////////////////////////////////////////////////////////

// GLOBAL VARS
Viper viper;

/////////////////////////////////////////////////////////////////////////////////////////

// FUNCTION PROTOTYPES
void playSound(char* wav);
int get_action(GameInputs inputs);
int update_game(int action);
void draw_upper_status();
void draw_lower_status();
void draw_border();
void draw_game(int draw_option);
void init_main_map();

/////////////////////////////////////////////////////////////////////////////////////////

// FUNCTION DEFINITIONS
/**
 * Program entry point! This is where it all begins.
 * This function is for all the parts of the game. Most of your
 * implementation should be elsewhere - this holds the game loop, and should
 * read like a road map for the rest of the code.
 */
 
int boostUpVal;
int boostDownVal;
int currentState;
int loop;
bool easyMode;
int last;
Speaker mySpeaker(p25);

int main()
{
    // First things first: initialize hardware
    ASSERT_P(hardware_init() == ERROR_NONE, "Hardware init failed!");
    
    viper_init(&viper);
    
    // 0. Initialize the maps
    // TODO: implement maps_init() and init_main_map() function in map.cpp:
    maps_init();
    init_main_map();

    // Initialize game state
    set_active_map(0);
    viper.head_x = viper.head_y = 5;
    last = NO_ACTION;

    char str[1024];
    uLCD.filled_rectangle(0, 0, 127, 127, 0xD2691E);
    snprintf(str,sizeof(str),"\n\n\n   Move to Start    \n\n\n\n\n\n                   \n    WELCOME TO          \n      SNAKE!       \n                    ");
    uLCD.text_string(str,0,0,FONT_7X8, WHITE);
    Timer T2;
    mySpeaker.PlayNote(200.0,0.22,0.1);
    wait(0.1);
    mySpeaker.PlayNote(200.0,0.15,0.1);
    wait(0.5);
    mySpeaker.PlayNote(700.0,0.2,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.4,0.1);
    wait(0.2);
    mySpeaker.PlayNote(740.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(740.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(740.0,0.1,0.1);
    wait(0.1);
    mySpeaker.PlayNote(700.0,0.2,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.075,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.075,0.1);
    wait(0.025);
    
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.1,0.1);
    wait(0.05);
    
    mySpeaker.PlayNote(587.0,0.1,0.1);
    wait(0.05);
    mySpeaker.PlayNote(622.0,0.1,0.1);
    wait(0.05);
    
    mySpeaker.PlayNote(700.0,0.2,0.1);
    wait(0.05);
    mySpeaker.PlayNote(700.0,0.075,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,0.075,0.1);
    wait(0.025);
    mySpeaker.PlayNote(700.0,1,0.1);
    wait(0.05);
    T2.start();

    while(1) {
        if(T2.read_ms() == 3000) {
            break;
        }
    }
    
    // Initial drawing
    draw_game(FULL_DRAW);
    
    //loop = 1;
    // Main game loop
    while(1) {
        // Timer to measure game update speed
        Timer t;
        t.start();

        // 1. Read inputs 
        //TODO: implement read_inputs() function in hardware.cpp:
        GameInputs inputs = read_inputs();
        
        // 2. Determine action (move, act, menu, etc.)
        //TODO: implement get_action() function:
        int action = get_action(inputs);
        
        // 3. Update game
        //TODO: implement update_game() function:
        int result;
        if(action == NO_ACTION) {
            result = update_game(last);
        } else {
            last = action;
            update_game(action);
        }


        uLCD.filled_rectangle(0, 0, 160, 7, BLACK);
        char str[1024];
        snprintf(str,sizeof(str),"Pos:%d,%d P:%d L:%d",viper.head_x,viper.head_y,viper.score, viper.lives);
        uLCD.text_string(str,0,0,FONT_7X8,RED);
        
        // 3b. Check for game over based on result
        // and if so, handle game over

        //TODO: implement this here or as a new function.
        
        //      3b1. if game is over, then
        //      3b2. draw and display tezt for game over sign
        if(result == GAME_OVER){
            if(viper.lives - 1 == 0) {
                uLCD.filled_rectangle(0, 0, 127, 127, BLACK);
                snprintf(str,sizeof(str),"Game Over,Score:%d",viper.score);
                uLCD.text_string(str,0,0,FONT_7X8,RED);
                while(1);
            } else {
                viper.lives--;
            }
                
        }

        if(action == MENU_BUTTON) {
            uLCD.filled_rectangle(0, 0, 127, 127, BLACK);
            snprintf(str,sizeof(str),"\n\n\n\n\n\n\nPAUSE GAME\nLives left:%d\nPress Again to \nResume", viper.lives);
            uLCD.text_string(str,0,0,FONT_7X8,RED);
            while(button2) {
            
            }
            draw_game(FULL_DRAW);
        }

        if(action == MENU_BUTTON) {
            uLCD.filled_rectangle(0, 0, 127, 127, BLACK);
            snprintf(str,sizeof(str),"\n\n\n\n\n\n\nPAUSE GAME\nLives left:%d\nPress Again to \nResume", viper.lives);
            uLCD.text_string(str,0,0,FONT_7X8,RED);
            while(button2) {
            
            }
            draw_game(FULL_DRAW);
        }

        if(action == DIFFICULTY_BUTTON) {
            char str[1024];
            uLCD.filled_rectangle(0, 0, 127, 127, 0x013220);
            snprintf(str,sizeof(str),"\n\n\n     Easy Mode      \n     ACTIVATED     ");
            uLCD.text_string(str,0,0,FONT_7X8, WHITE);
            Timer T2;
            T2.start();
            while(1) {
                if(T2.read_ms() == 3000) {
                    break;
                }
            }
            easyMode = true;
            viper.lives = 5;
            viper.speed = 1001;
            draw_game(FULL_DRAW);
        }

            
                
        // 4. Draw screen -- provided.
        draw_game(result);
        
        // Compute update time
        t.stop();
        int dt = t.read_ms();

        // Display and wait
        // NOTE: Text is 8 pixels tall
        if (dt < viper.speed) wait_ms(viper.speed - dt);
    }
}


/**
 * Plays a .wav file
 */
void playSound(char* wav)
{
    // OPTIONAL: Implement
    
}

/**
 * Given the game inputs, determine what kind of update needs to happen.
 * Possible return values are defined below.
 * Get Actions from User (pushbuttons, and nav_switch)
 * Based on push button and navigation switch inputs, determine which action
 * needs to be performed (may be no action).
 */
int get_action(GameInputs inputs)
{
    // TODO: Implement
    
    
    // 1. Check your action and menu button inputs and return the corresponding action value
    if(!button2){
        return MENU_BUTTON;
    } else if (!button1) {
        return ACTION_BUTTON;
    } else if (!button3) {
        return DIFFICULTY_BUTTON;
    } 
    
    // 2. Check for your navigation switch inputs and return the corresponding action value
    if(navs.right()) {
        return GO_RIGHT;
    }
    if(navs.left()) {
        return GO_LEFT;
    }
    if(navs.up()) {
        return GO_UP;
    }
    if(navs.down()) {
        return GO_DOWN;
    }

    // If no button is pressed, just return no action value
    return NO_ACTION;
}

/**
 * This function is called by update game to check when the snake 
 * gets an object (in other words, when a snake eats an object). We 
 * update the snake and game conditions as needed based on the object type
 */
int get_object(){
    
    //TODO: Implement
    
    //TODO: Implement
    
    // 1. Get item at current head location
    MapItem* currentItem = get_current(viper.head_x, viper.head_y);
    // 2. Initialize a return value variable to denote the item type we got
    int returnVal = 0;

    // 3. Check if item is valid and is a chest
    //    3a. if so, increment the score, extend the length of the viper
    //    3b. Remove the chest
    //    3c. set the return value variable to GOT_LENGTH
    if(currentItem != NULL && currentItem->type == CHEST) {
        viper.score ++;
        viper.length ++;
        remove_chest(viper.head_x, viper.head_y);
        returnVal = GOT_LENGTH;
    }
    
    // 4. Else, check if the item is valid a boost-up/boost-down
    //    4a. if so, set the ability for the viper based on the type of item
    //          for the right amount fo time
    //    4b. Remove the boost-up/down item
    //    4c. Set the return value variable to GOT_OBJ
    //    Hint: You have to do this check for all your boost-ups/downs. Might be 
    //          easier to use Switch statements.
    if(currentItem != NULL && currentItem->type == BOOSTDOWN) {
        if (easyMode) {
            remove_boostDown(viper.head_x, viper.head_y);
            returnVal = GOT_OBJ;   
        } else {
            viper.score = viper.score - 2;
            remove_boostDown(viper.head_x, viper.head_y);
            returnVal = GOT_OBJ;
        }
    }
    
    if(currentItem != NULL && currentItem->type == BOOSTUP) {
        if(viper.score == 0){
            viper.score += 2;
        }
        viper.score = abs(viper.score) * 2;
        remove_boostUp(viper.head_x, viper.head_y);
        returnVal = GOT_OBJ;
    }

    if(currentItem != NULL && currentItem->type == SLOWSPEED) {
        if(viper.speed == 1001) {
            viper.speed = 1001;
            remove_slowSpeed(viper.head_x, viper.head_y);
            mySpeaker.PlayNote(700.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(622.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(587.0,0.1,0.1);
            returnVal = GOT_OBJ;
        } else {
            viper.speed = 1000;
            remove_slowSpeed(viper.head_x, viper.head_y);
            mySpeaker.PlayNote(700.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(622.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(587.0,0.1,0.1);
            returnVal = GOT_OBJ;
            returnVal = GOT_OBJ;
        }
    }

    if(currentItem != NULL && currentItem->type == SPEEDUP) {
        if (viper.speed == 1000) {
            viper.speed = 100;
            remove_speedUp(viper.head_x, viper.head_y);
             mySpeaker.PlayNote(587.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(622.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(700.0,0.1,0.1);
            returnVal = GOT_OBJ;
        } else if (viper.speed == 1001) {
            remove_speedUp(viper.head_x, viper.head_y);
            mySpeaker.PlayNote(587.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(622.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(700.0,0.1,0.1);
            returnVal = GOT_OBJ;
        } else {
            viper.speed = 25;
            remove_speedUp(viper.head_x, viper.head_y);
            mySpeaker.PlayNote(587.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(622.0,0.1,0.1);
            wait(0.05);
            mySpeaker.PlayNote(700.0,0.1,0.1);
            returnVal = GOT_OBJ;
        }
    }

    if(currentItem != NULL && currentItem->type == ADDLIFE) {
        viper.lives++;
        remove_addLife(viper.head_x, viper.head_y);
        returnVal = GOT_OBJ;
    }
    
    // 5. Check if the return value variable is GOT_LENGTH
    //    5a. If so, then increase the snake length and update its locations as needed
    //        Hint: Refer to Step 6 below; the main difference is that you need 
    //        to lengthen the snake (what should we change the snake tail position to?)
    if(returnVal == GOT_LENGTH) {
        viper.length ++;
        int tail_x = viper.locations[viper.length - 1].x;
        int tail_y = viper.locations[viper.length - 1].y;
        
        for (int i = viper.length - 1; i > 0; i--) {
            viper.locations[i] = viper.locations[i - 1];
        }
        
        viper.locations[0].x = viper.head_x;
        viper.locations[0].y = viper.head_y;
        
        add_viper_head(viper.head_x, viper.head_y);
        
        for (int i = viper.length - 2; i > 0; i--) {
            add_viper_body(viper.locations[i].x, viper.locations[i].y);
        }
    
        add_viper_tail(tail_x, tail_y);
        
        return returnVal;
        
    }
    
    // 5. Check if the return value variable is GOT_LENGTH
    //    5a. If so, then increase the snake length and update its locations as needed
    //        Hint: Refer to Step 6 below; the main difference is that you need 
    //        to lengthen the snake (what should we change the snake tail position to?)
        int tail_x = viper.locations[viper.length - 1].x;
        int tail_y = viper.locations[viper.length - 1].y;
        
        for (int i = viper.length - 1; i > 0; i--) {
            viper.locations[i] = viper.locations[i - 1];
        }
        
        viper.locations[0].x = viper.head_x;
        viper.locations[0].y = viper.head_y;
        
        add_viper_head(viper.head_x, viper.head_y);
        
        for (int i = viper.length - 2; i > 0; i--) {
            add_viper_body(viper.locations[i].x, viper.locations[i].y);
        }
        
        add_viper_tail(viper.locations[viper.length - 1].x, viper.locations[viper.length - 1].y);
        
        //    6g. call a function to map erase the original location for the x and y tail
        map_erase(tail_x, tail_y);
        
        return returnVal;
        
    }
 
 
int update_game(int action)
{
    // TODO: Implement
    
    // 1. Check the viper speed and update viper speed status
    // 2. Update the previous viper head position to the current position
    viper.head_px = viper.head_x;
    viper.head_py = viper.head_y;
    // 3. Check if action is to go up
            
    //      3a. Get item north of the current viper head
    //      3b. Update the current viper head position upwards
    //      3c. Check if the item exist and item is walkable
    //          3c1. Check if the viper head does not collide with itself
    //          3c2. If so, return game over
    //          3c3. Otherwise, update viper head back to its original position
    //               and return no result.
    //      3d. Check if the viper gets an object (eats) by calling another function
    //          3d1. Check if viper length is more than the maximum length
    //          3d2. If so, return game over
    //  ````3e. Finally, return moved since the viper has moved
    if(action == ACTION_BUTTON) {
        if (viper.invincibility == 1) {
            viper.invincibility = 0;
        } else if (viper.invincibility == 0) {
            viper.invincibility = 1;
        }
    }


    
    if(action == GO_UP) {
        MapItem* northItem = get_north(viper.head_x, viper.head_y);
        viper.head_x = viper.head_x;
        viper.head_y = viper.head_y - 1;
        if(northItem != NULL && !northItem->walkable) {
            if(viper.locations[1].x == viper.head_x && viper.locations[1].y == viper.head_y) {
                viper.head_x = viper.head_x;
                viper.head_y = viper.head_y + 1;
                return NO_RESULT;
            }
            if(viper.invincibility == 1) {
                return NO_RESULT;
            }
            return GAME_OVER;
        }
        if(get_object() == GOT_LENGTH){
            if(viper.length > VIPER_MAX_LENGTH) {
                if(viper.invincibility == 1) {
                return NO_RESULT;
                } 
                return GAME_OVER;
            }  
        }
        return MOVED;
            
    }

    if(action == GO_DOWN) {
        MapItem* northItem = get_south(viper.head_x, viper.head_y);
        viper.head_x = viper.head_x;
        viper.head_y = viper.head_y + 1;
        if(northItem != NULL && !northItem->walkable) {
            if(viper.locations[1].x == viper.head_x && viper.locations[1].y == viper.head_y) {
                viper.head_x = viper.head_x;
                viper.head_y = viper.head_y - 1;
                return NO_RESULT;
            }
            if(viper.invincibility == 1) {
                return NO_RESULT;
            }
            return GAME_OVER;
        }
        if(get_object() == GOT_LENGTH){
            if(viper.length > VIPER_MAX_LENGTH) {
                if(viper.invincibility == 1) {
                    return NO_RESULT;
                }   
                return GAME_OVER;
            }  
        }
        return MOVED;
            
    }
    
    if(action == GO_RIGHT) {
        MapItem* northItem = get_east(viper.head_x, viper.head_y);
        viper.head_x = viper.head_x + 1;
        viper.head_y = viper.head_y;
        if(northItem != NULL && !northItem->walkable) {
            if(viper.locations[1].x == viper.head_x && viper.locations[1].y == viper.head_y) {
                viper.head_x = viper.head_x - 1;
                viper.head_y = viper.head_y;
                return NO_RESULT;
            }
            if(viper.invincibility == 1) {
                return NO_RESULT;
            } 
            return GAME_OVER;
        }
        if(get_object() == GOT_LENGTH){
            if(viper.length > VIPER_MAX_LENGTH) {
                if(viper.invincibility == 1) {
                    return NO_RESULT;
                } 
                return GAME_OVER;
            }  
        }
        return MOVED;
    }
    
    if(action == GO_LEFT) {
        MapItem* northItem = get_west(viper.head_x, viper.head_y);
        viper.head_x = viper.head_x - 1;
        viper.head_y = viper.head_y;
        if(northItem != NULL && !northItem->walkable) {
            if(viper.locations[1].x == viper.head_x && viper.locations[1].y == viper.head_y) {
                viper.head_x = viper.head_x + 1;
                viper.head_y = viper.head_y;
                return NO_RESULT;
            }
            if(viper.invincibility == 1) {
                return NO_RESULT;
            }
            return GAME_OVER;
        }
        if(get_object() == GOT_LENGTH){
            if(viper.length > VIPER_MAX_LENGTH) {
                if(viper.invincibility == 1) {
                    return NO_RESULT;
                }
                return GAME_OVER;
            }  
        }
        return MOVED;
    }
   
}
/**
 * Draw the upper status bar.
 */
void draw_upper_status()
{
    uLCD.line(0, 9, 127, 9, GREEN);
}

/**
 * Draw the lower status bar.
 */
void draw_lower_status()
{
    uLCD.line(0, 118, 127, 118, GREEN);
}

/**
 * Draw the border for the map.
 */
void draw_border()
{
    uLCD.filled_rectangle(  0,   9, 127,  14, WHITE);   // Top
    uLCD.filled_rectangle(  0,  13,   2, 114, WHITE);   // Left
    uLCD.filled_rectangle(  0, 114, 127, 117, WHITE);   // Bottom
    uLCD.filled_rectangle(124,  14, 127, 117, WHITE);   // Right
}

/**
 * Entry point for frame drawing. This should be called once per iteration of
 * the game loop. This draws all tiles on the screen, followed by the status
 * bars. Unless init is nonzero, this function will optimize drawing by only
 * drawing tiles that have changed from the previous frame.
 */
void draw_game(int draw_option)
{
    // Draw game border first
    if(draw_option == FULL_DRAW) 
    {
        draw_border();
        int u = 58;
        int v = 56;
        draw_viper_head(u, v);
        draw_viper_body(u-11, v);
        draw_viper_tail(u-22, v);
        return;
    }

    // Iterate over all visible map tiles
    for (int i = -5; i <= 5; i++) { // Iterate over columns of tiles
        for (int j = -4; j <= 4; j++) { // Iterate over one column of tiles
            // Here, we have a given (i,j)

            // Compute the current map (x,y) of this tile
            int x = i + viper.head_x;
            int y = j + viper.head_y;

            // Compute the previous map (px, py) of this tile
            int px = i + viper.head_px;
            int py = j + viper.head_py;

            // Compute u,v coordinates for drawing
            int u = (i+5)*11 + 3;
            int v = (j+4)*11 + 15;

            // Figure out what to draw
            DrawFunc draw = NULL;
            if (x >= 0 && y >= 0 && x < map_width() && y < map_height()) { // Current (i,j) in the map
                MapItem* curr_item = get_here(x, y);
                MapItem* prev_item = get_here(px, py);
                if (draw_option || curr_item != prev_item) { // Only draw if they're different
                    if (curr_item) { // There's something here! Draw it
                        draw = curr_item->draw;
                    } else { // There used to be something, but now there isn't
                        draw = draw_nothing;
                    }
                } else if (curr_item && curr_item->type == CLEAR) {
                    // This is a special case for erasing things like doors.
                    draw = curr_item->draw; // i.e. draw_nothing
                }
            } else if (draw_option) { // If doing a full draw, but we're out of bounds, draw the walls.
                draw = draw_wall;
            }

            // Actually draw the tile
            if (draw) draw(u, v);
        }
    }

    // Draw status bars
    draw_upper_status();
    draw_lower_status();
}

/**
 * Initialize the main world map. Add walls around the edges, interior chambers,
 * and plants in the background so you can see motion.
 */
void init_main_map()
{
    // "Random" plants
    Map* map = set_active_map(0);
    for(int i = map_width() + 3; i < map_area(); i += 39) {
        add_chest(i % map_width(), i / map_width());
    }
    pc.printf("plants\r\n");
    for(int i = map_width() + 5; i < map_area(); i += 61) {
        add_plant(i % map_width(), i / map_width());
    }
    
    pc.printf("boostUps\r\n");
    for(int i = map_width() + 7; i < map_area(); i += 91) {
        add_boostUp(i % map_width(), i / map_width());
    }
    
    pc.printf("boostDowns\r\n");
    for(int i = map_width() + 6; i < map_area(); i += 78) {
        add_boostDown(i % map_width(), i / map_width());
    }

    pc.printf("slowSpeeds\r\n");
    for(int i = map_width() + 10; i < map_area(); i += 141) {
        add_slowSpeed(i % map_width(), i / map_width());
    }

    pc.printf("speedUps\r\n");
    for(int i = map_width() + 8; i < map_area(); i += 121) {
        add_speedUp(i % map_width(), i / map_width());
    }

    pc.printf("addLives\r\n");
    for(int i = map_width() + 9; i < map_area(); i += 165) {
        add_addLife(i % map_width(), i / map_width());
    }

    pc.printf("Adding walls!\r\n");
    add_wall(            0,              0, HORIZONTAL, map_width());
    add_wall(            0, map_height()-1, HORIZONTAL, map_width());
    add_wall(            0,              0,   VERTICAL, map_height());
    add_wall(map_width()-1,              0,   VERTICAL, map_height());
    pc.printf("Walls done!\r\n");
    
    add_viper_head(viper.locations[0].x, viper.locations[0].y);
    add_viper_body(viper.locations[1].x, viper.locations[1].y);
    add_viper_tail(viper.locations[2].x, viper.locations[2].y);
    
    pc.printf("Add extra chamber\r\n");
    add_wall(30,  0,   VERTICAL, 10);
    add_wall(30, 10, HORIZONTAL, 10);
    add_wall(39,  0,   VERTICAL, 10);
    pc.printf("Added!\r\n");
    
    print_map();

}