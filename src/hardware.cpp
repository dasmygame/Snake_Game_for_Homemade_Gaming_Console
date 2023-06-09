// ============================================
// The Hardware class file
//==================================================================


#include "globals.h"
#include "hardware.h"

// We need to actually instantiate some of the globals for hardwares 
// (i.e. declare them once without the extern keyword).
// That's what this file does!

// Hardware initialization: Instantiate all the things!
uLCD_4DGL uLCD(p9,p10,p11);                 // LCD Screen (tx, rx, reset)
Serial pc(USBTX,USBRX);                     // USB Console (tx, rx)
DigitalIn button1(p21);                     // Pushbuttons (pin)
DigitalIn button2(p22);                     // ...
DigitalIn button3(p23);                     // ...
DigitalIn button4(p24);
AnalogOut DACout(p18);                      // Speaker (pin)
PwmOut speaker(p26);                        // ...
wave_player waver(&DACout);                 // Wave player
Nav_Switch navs(p12,p15,p14,p16,p13);       // Nav Switch

/*
 * This initializes the hardware by calling some functions to set them up.
 */
int hardware_init()
{
    // Crank up the speed
    uLCD.baudrate(3000000);
    pc.baud(115200);
        
    //Initialize action pushbuttons
    button1.mode(PullUp); 
    button2.mode(PullUp);
    button3.mode(PullUp);
    button4.mode(PullUp);
    
    return ERROR_NONE;
}

/*
 * This handles reading inputs from all possible devices - pushbuttons, nav_switch
 */
GameInputs read_inputs() 
{
    GameInputs in;
    wait(0.02);
    in.b1 = !button1;
    wait(0.02);
    in.b2 = !button2;
    wait(0.02);
    in.b3 = !button3;
    wait(0.02);
    in.b4 = !button4;
    wait(0.02);

    //2. Read navigation switch buttons from in
    
    in.ns_center = navs.center();
    in.ns_down = navs.down();
    in.ns_up = navs.up();
    in.ns_right = navs.right();
    in.ns_left = navs.left();

    
    wait(0.02); //For simple debouncing
    return in;
}
