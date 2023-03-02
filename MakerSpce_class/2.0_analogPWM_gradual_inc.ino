//Arduino class

// the setup function runs once when you press reset or power the board
int ledpin=3;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(2, OUTPUT); //For PWM no need to specify pinmode
}

// the loop function runs over and over again forever
void loop() {
  int x=0;
  for(x=0; x<255; ){
    analogWrite(ledpin, x);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    analogWrite(ledpin, x);    // turn the LED off by making the voltage LOW
    delay(500);                       // wait for a second
    x=x+50;
  }
}
