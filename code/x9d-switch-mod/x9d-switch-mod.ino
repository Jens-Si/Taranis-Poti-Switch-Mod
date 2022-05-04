int dc = 0;       //this variable holds the current duty cycle;
#include "timer.h"

/* DEFINE YOUR STUFF HERE *********************************************/
#define pin_SW1_1 16  //3-Pos Switch 1 Position 1
#define pin_SW1_2 14  //3-Pos Switch 1 Pull-Up
#define pin_SW1_3 15  //3-Pos Switch 1 Position 3

#define pin_SW2_1 19  //3-Pos Switch 2 Position 1
#define pin_SW2_2 20  //3-Pos Switch 2 Pull-Up
#define pin_SW2_3 21  //3-Pos Switch 2 Position 3

#define pin_SW3_1 3   //Button pressed
#define pin_SW3_2 4   //Button Pull-Up

bool SW1_1; bool SW1_2; bool SW1_3;
bool SW2_1; bool SW2_2; bool SW2_3;
bool SW3_1; bool SW3_2;
int swcase;
/**********************************************************************/

void setup() {
  timersetup();   //Setup the timer

  //SETUP ALL YOUR STUFF HERE:
  
    //Switch_1 setup
  pinMode(pin_SW1_1, INPUT);
  pinMode(pin_SW1_2, OUTPUT);
  pinMode(pin_SW1_3, INPUT);
  digitalWrite(pin_SW1_2, HIGH);  //set HIGH for pull up
    //Switch_2 setup
  pinMode(pin_SW2_1, INPUT);
  pinMode(pin_SW2_2, OUTPUT);
  pinMode(pin_SW2_3, INPUT);
  digitalWrite(pin_SW2_2, HIGH);  //set HIGH for pull up
    //Switch_2 setup
  pinMode(pin_SW3_1, INPUT);
  pinMode(pin_SW3_2, OUTPUT);
  digitalWrite(pin_SW3_2, HIGH);  //set HIGH for pull up
}

void loop() {
/* WRITE YOUR CODE TO DEFINE "dc" HERE ********************************/
  
  SW1_1 = !digitalRead(pin_SW1_1);                                //Switch 1 is in position 1
  SW1_3 = !digitalRead(pin_SW1_3);                                //Switch 1 is in position 3
  if(!SW1_1 && !SW1_3){    SW1_2=true;  }else{    SW1_2=false;  } //Switch 1 is in position 2, because not in pos 1 or pos 3

  SW2_1 = !digitalRead(pin_SW2_1);                                //Switch 2 is in position 1
  SW2_3 = !digitalRead(pin_SW2_3);                                //Switch 2 is in position 3
  if(!SW2_1 && !SW2_3){    SW2_2=true;  }else{    SW2_2=false;  } //Switch 2 is in position 2, because not in pos 1 or pos 3

  SW3_1 = !digitalRead(pin_SW3_1);                                //Button is pressed
  if(!SW3_1){    SW3_2=true;  }else{    SW3_2=false;  }           //Button is not pressed, because it is not pressed

  swcase = switchcase();

  switch (swcase) {
    case 0:        dc = 0;       break;  //~0,0V  //Toggle pressed
    case 1:        dc = 35;      break;  //~0,5V
    case 2:        dc = 55;      break;  //~1,0V
    case 3:        dc = 75;      break;  //~1,5V
    case 4:        dc = 90;      break;  //~2,2V  //Vario AUS
    case 5:        dc = 100;     break;  //~3,0V  //Button pressed
    default:                     break;
  } 
/**********************************************************************/ 
  timersetDC(dc); //Set new duty cycle to output
  delay(100);     //easy debounce...
}

int switchcase(){
  if(SW3_1){return 5;}      //Button pressed
  if(SW1_3){return 0;}      //Toggle pressed
  if(SW1_1){return 4;}      //Vario AUS

  if(SW2_1){return 3;}
  if(SW2_2){return 2;}
  if(SW2_3){return 1;}
}
