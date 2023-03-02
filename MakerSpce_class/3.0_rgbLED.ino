//Arduino class
//3.0_rgbLED 
// the setup function runs once when you press reset or power the board
int red=3, blue=5, green=6;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(ledpin, OUTPUT); //For PWM no need to specify pinmode
}

// the loop function runs over and over again forever
void loop() {
  int x=0,y=0,z=0;

  //RED led
    while(x<256 ){//loop to gradually increase brightness in steps
      analogWrite(red, x);   // 
      delay(500);                       // wait for a second
      analogWrite(red, x);    // 
      delay(500);                       // wait for a second
      x=x+50;
    }
    digitalWrite(red, 0);
     //Blue Led
     while(y<256 ){//loop to gradually increase brightness in steps
      analogWrite(blue, y);   // 
      delay(500);                       // wait for a second
      analogWrite(blue, y);    // 
      delay(500);                       // wait for a second
      y=y+50;
    }

    digitalWrite(blue, 0);// stop blue led
   
     //Green Led 
     y=0;//reset y to zero
     while(y<256 ){//loop to gradually increase brightness in steps
      analogWrite(green, y);   // 
      delay(500);                       // wait for a second
      analogWrite(green, y);    // 
      delay(500);                       // wait for a second
      y=y+50;
    }
}
