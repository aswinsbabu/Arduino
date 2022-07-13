int led1=10, led2=11, pin, led_pin;

// function declaration
void turn_on_led (int pin)  {
  led_pin=pin;
  digitalWrite(led_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);
}

// function declaration
void turn_off_led (int pin)  {
  led_pin=pin;
 digitalWrite(led_pin, LOW);    // turn the LED off by making the voltage LOW
 //delay(1000);                       // wait for a second
}

void setup () {
// initialize digital pin 11 as an output.
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop () {
//Blinking
  
  Write code for blinking both leds



//00
  Write code for Turning off both leds


  
//01
   Write code for Turning on Led2



//10
  
 Write code for Turning on Led1



//11 pattern
  Write code for Turning on both LEDs

 

//Blinking
  Write code for blinking both leds

  
}