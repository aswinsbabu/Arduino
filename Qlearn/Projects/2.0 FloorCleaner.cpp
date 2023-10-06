//Vaccum Cleaner project
//#include <NewPing.h> //for ultrasonic sensor
#define R_TRIG_PIN   2 // Trig pin of Right sensor 
#define R_ECHO_PIN   3    // Echo pin of Right sensor 
#define F_TRIG_PIN   4 // Trig pin of Front sensor 
#define F_ECHO_PIN   5    // Echo pin of Front sensor 
#define L_TRIG_PIN   6 // Trig pin of left sensor 
#define L_ECHO_PIN   7    // Echo pin of left sensor 

#define MAX_DISTANCE 200 // Maximum distance to consider (in cm)
#define OBSTACLE_DISTANCE 20 // Distance to consider an obstacle (in cm)


NewPing sonar1(R_TRIG_PIN, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Dist2ObstacleFront=calculate_distance();
Dist2ObstacleRight=calculate_distance();
Dist2ObstacleLeft=calculate_distance();
}

int calculate_distance(int trigPin, int echoPin) {
  //int trigPin =
  long duration, distance; //long integer
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;//2: up and down travel
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
return(distance);
}
