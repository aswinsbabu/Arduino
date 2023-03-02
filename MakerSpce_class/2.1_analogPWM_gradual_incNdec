//Arduino class
//2.1_analogPWM_gradual_incNdec
// the setup function runs once when you press reset or power the board
int ledpin=3;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(2, OUTPUT); //For PWM no need to specify pinmode
}

// the loop function runs over and over again forever
void loop() {
  int x;
    for(x=0; x<256; ){//loop to gradually increase brightness in steps
      analogWrite(ledpin, x);   // 
      delay(500);                       // wait for a second
      analogWrite(ledpin, x);    // 
      delay(500);                       // wait for a second
      x=x+50;
    }
  digitalWrite(ledpin,0);
  delay(500);
  digitalWrite(ledpin,255);
  delay(500);
    for(x=255; x>0; ){//loop to gradually decrease brightness in steps
      analogWrite(ledpin, x);   // 
      delay(500);                       // wait for a second
      analogWrite(ledpin, x);    // 
      delay(500);                       // wait for a second
      x=x-50;
    }
}
