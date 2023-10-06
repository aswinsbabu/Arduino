//3.5 Vaccum Cleaner project
/*Author Aswin
 * Robot moving
 * Added motor motion Function
 * Need to add proper obstacle avoiding algorithmn
Displayed all ultrasonic sensor values

*/
 
//Ultrasonic Sensor Pins
#define R_TRIG_PIN   2 // Trig pin of Right sensor 
#define R_ECHO_PIN   3    // Echo pin of Right sensor 
#define F_TRIG_PIN   4 // Trig pin of Front sensor 
#define F_ECHO_PIN   5    // Echo pin of Front sensor 
#define L_TRIG_PIN   6 // Trig pin of left sensor 
#define L_ECHO_PIN   7    // Echo pin of left sensor 

//Robot wheels; motor pin definition
#define LeftMtrInput1  8 //IN1
#define LeftMtrInput2  9 //IN2
#define RightMtrInput1 10 //IN3
#define RightMtrInput2 11 //IN4
//#define LeftMtrEnable  //Used jumber: no speed control
//#define RightMtrEnable

//Ultrasonic distance variables
int Dist2ObstacleFront;
int Dist2ObstacleRight;
int Dist2ObstacleLeft;

void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);
  pinMode(LeftMtrInput1, OUTPUT);
  pinMode(LeftMtrInput2 , OUTPUT);
  
  pinMode(RightMtrInput1, OUTPUT);
  pinMode(RightMtrInput2, OUTPUT);
  
  
  //pinMode(LeftMtrEnable, OUTPUT);
  //pinMode(RightMtrEnable, OUTPUT);
  
  }

/////////////////////////////     MAIN    /////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  //display_ObstaceleDistance();// To display all ultrasonic sensor values
  Dist2ObstacleFront = calculate_distance(F_TRIG_PIN, F_ECHO_PIN);
  Dist2ObstacleRight = calculate_distance(R_TRIG_PIN, R_ECHO_PIN);
  Dist2ObstacleLeft = calculate_distance(L_TRIG_PIN, L_ECHO_PIN);
  
  if(Dist2ObstacleFront>20){ // Move forward
    move_robotFrwd();
    delay(500);
  }
  else if (Dist2ObstacleFront<20 &&  Dist2ObstacleRight>20 ){ // Move right
    move_robotRight();
    delay(500);
  
  }
  else if (Dist2ObstacleFront<20 &&  Dist2ObstacleLeft>20 ){ // Move Left
    move_robotLeft();
	}
}
//////////////////////////////////  Main End Here ///////////////////////////


// Function to calculated distance to obstacle
int calculate_distance(int trigPin, int echoPin) {
  //int trigPin =
  long duration, distance; //long integer
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;//2: up and down travel
  return distance;
}

//void display_distance(int distance, char myArray[]){
void display_distance(int distance){
  //Serial.print(myArray);
  //Serial.print(myArray);
  Serial.print(distance);
  Serial.println("CM:");
  delay(10);
}

void display_ObstaceleDistance(){ // Displays all ultrasonic sensor values
  
  Dist2ObstacleFront=calculate_distance(F_TRIG_PIN,F_ECHO_PIN);
    display_distance(Dist2ObstacleFront);Serial.print("Front \n");
  
  Dist2ObstacleRight=calculate_distance(R_TRIG_PIN,R_ECHO_PIN);
    display_distance(Dist2ObstacleRight);Serial.print("Right \n ");
    
  Dist2ObstacleLeft=calculate_distance(L_TRIG_PIN,L_ECHO_PIN);
    display_distance(Dist2ObstacleLeft);Serial.print("Left \n ");
  
}
////////////// Functions For Robot motion
void move_robotFrwd(){
  Serial.print("Motor moving ---------Forward");
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);
  
  digitalWrite(RightMtrInput1, HIGH);
  digitalWrite(RightMtrInput2, LOW);
//  analogWrite(LeftMtrEnable, 150);
//  analogWrite(RightMtrEnable,150);
  }

void move_robotRight(){
  Serial.print("Motor moving ---------Right");
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);

  digitalWrite(RightMtrInput1, LOW); //Right motor off
  digitalWrite(RightMtrInput2, LOW);
  
  }
void move_robotLeft(){
  Serial.print("Motor moving ---------Left");
  digitalWrite(LeftMtrInput1, LOW);
  digitalWrite(LeftMtrInput2, LOW);

  digitalWrite(RightMtrInput1, HIGH); //Right motor off
  digitalWrite(RightMtrInput2, LOW);
}
