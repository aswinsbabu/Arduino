//Interface Ultrasonic, read distance, led blink if close proximitty
//https://docs.google.com/document/d/1JWNRUiD_racqGxvGGi5lnQidfX7YnwMcpfdAG1xAAtY/edit#heading=h.5d84nozaucbe 
int trigPin = 9;
int echoPin = 10;
int led = 13;//on board led


void setup() {
  Serial.begin(9600); 
   pinMode(led, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance; //long integer
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;//2: up and down travel
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
 if((distance<=10)) //To Additionally turn on led depnd on distance
  {
    digitalWrite(led, HIGH);
}
   else if(distance>10)
 {
     digitalWrite(led, LOW);
   }
}

//https://www.youtube.com/watch?v=WslzsHDYuF0
