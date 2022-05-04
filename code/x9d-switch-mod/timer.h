#define maximum_timercount 49   //how high the timer can count aka frequncy
#define maximum_dutycycle  20   //maximum duty cycle in referenz to maximum_timercount

void timersetup(){

  //TODO: Change timer1 to timer4 to get a higher frequency!!!
  
  pinMode(9, OUTPUT);                               // Set digital pin 9 (D9) to an output
  pinMode(10, OUTPUT);                              // Set digital pin 10 (D10) to an output
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);  // Enable PWM outputs for OC1A and OC1B on digital pins 9, 10
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11);     // Set fast PWM and prescaler of 8 on timer 1
  ICR1 = maximum_timercount;                        // Set the PWM frequency
  OCR1A = 0;                                        // Set duty-cycle to 0% on D9
}

void timersetDC(int dutycicle){
  OCR1A = (dc*maximum_dutycycle) / 100;;            //set timer on time
}
