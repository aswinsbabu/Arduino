//2.0 Fire Fight
//Parent 3.5 Vaccum Cleaner project
/*Author Aswin
 * Added motor motion Function

Pending
Display all sensor values
Set ambient Value for IR

*/
 
//IR Sensor Pins;analog read
#define RightIRsensor    A5  
#define FrontIRsensor    A4    
#define LeftIRsensor     A3   
 

//Robot wheels; motor pin definition
#define LeftMtrInput1  2 //IN1
#define LeftMtrInput2  3 //IN2
#define RightMtrInput1 4 //IN3
#define RightMtrInput2 5 //IN4

//Motor PWM speed control pins; analogWrite
#define EnableLeftMtr 10 //EN1
#define EnableRightMtr 11 //EN2

//Fire Pump
#define EnableWaterPump 6 //PWM;Enable of Motor driver2(IN1&IN2==>VCC&GND)
#define ServoMtr  9// PWM

//Variables
int Dist2FireFront ;
int Dist2FireRight ; 
int Dist2FireLeft  ;
  
void setup() {
   
  Serial.begin(9600);
  
  //Pinmode Setup
    //Output
  pinMode(LeftMtrInput1, OUTPUT);
  pinMode(LeftMtrInput2, OUTPUT);
  pinMode(RightMtrInput1, OUTPUT);
  pinMode(RightMtrInput2, OUTPUT);
      //motor Driver
  pinMode(EnableLeftMtr, OUTPUT);
  pinMode(EnableRightMtr, OUTPUT);
  pinMode(EnableWaterPump, OUTPUT); 
    //Input IR Sensors
  pinMode(RightIRsensor, INPUT);
  pinMode(FrontIRsensor, INPUT);
  pinMode(LeftIRsensor, INPUT);
    
  }

/////////////////////////////     MAIN    /////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  
  Dist2FireFront =  analogRead(FrontIRsensor );
  Dist2FireRight =  analogRead(RightIRsensor );
  Dist2FireLeft  =  analogRead(LeftIRsensor );

//Display IR sensor values
  serialPrint_distance( Dist2FireFront);Serial.print(" Dist2FireFront");//28 to 990
  serialPrint_distance( Dist2FireRight);Serial.print(" Dist2FireRight");//27 to 964
  serialPrint_distance( Dist2FireLeft);Serial.print("Dist2FireLeft");//40 to 995 

//  while
//  move_robotFrwd();
//  analogWrite(EnableWaterPump, 255);
  
  //display_ObstaceleDistance();
    if (Dist2FireFront>200){
    
    move_robotFrwd();
    }
    else if(Dist2FireFront<200){
        if ( Dist2FireRight>200 ){ // Move right
          stop_robot();
          delay(500);
          move_robotRight();
          //delay(500);
          //Display IR sensor values
          serialPrint_distance( Dist2FireFront);Serial.print(" Dist2FireFront");//28 to 990
          serialPrint_distance( Dist2FireRight);Serial.print(" Dist2FireRight");//27 to 964
          serialPrint_distance( Dist2FireLeft);Serial.print("Dist2FireLeft");//40 to 995 
          //break;
          }
        else if (Dist2FireLeft>200 ){ // Move Left
          stop_robot();
          move_robotLeft();
          //break;
        }
        else{
          stop_robot();
          move_robotBack();
          //delay(500);
          stop_robot();
          //break;
          }
      }
     
  
      
  //while
}

//////////////////////////////////  Main End Here ///////////////////////////


//void serialPrint_distance(int distance, char myArray[]){
void serialPrint_distance(int distance){
  Serial.println("           ");
  Serial.println("           ");
  Serial.print(distance);
  Serial.println("CM:");
  
  delay(1000);
}


////////////// Functions For Robot motion
void move_robotFrwd(){
  serialPrint_distance( Dist2FireFront);Serial.print(" Dist2FireFront");
  Serial.println("Motor moving ---------Forward");
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);
  
  digitalWrite(RightMtrInput1, HIGH);
  digitalWrite(RightMtrInput2, LOW);
  analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr,255);
  delay(1000);
  stop_robot();
  }

void move_robotRight(){
  serialPrint_distance( Dist2FireRight);Serial.print(" Dist2FireRight");//27 to 964
  Serial.println("Motor moving ---------Right");
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);

  digitalWrite(RightMtrInput1, LOW); //Right motor off
  digitalWrite(RightMtrInput2, LOW);
  analogWrite(EnableLeftMtr, 255);
  //analogWrite(EnableRightMtr,255);
  delay(500);
  stop_robot();
  }
void move_robotLeft(){
  serialPrint_distance( Dist2FireLeft);Serial.print("Dist2FireLeft");//40 to 995
  Serial.println("Motor moving ---------Left");
  digitalWrite(LeftMtrInput1, LOW);//Left motor off
  digitalWrite(LeftMtrInput2, LOW);

  digitalWrite(RightMtrInput1, HIGH); 
  digitalWrite(RightMtrInput2, LOW);

  //analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr,255);
  delay(500);
  stop_robot();
  }

void move_robotBack(){
  Serial.println("Motor moving ---------Backward");
  digitalWrite(LeftMtrInput1, LOW);
  digitalWrite(LeftMtrInput2, HIGH);
  
  digitalWrite(RightMtrInput1, LOW);
  digitalWrite(RightMtrInput2, HIGH);
  
  analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr,255);
  delay(500);
  stop_robot();
  }

void stop_robot(){
  Serial.println("Stopping the robot --------- ");
  digitalWrite(LeftMtrInput1, LOW);
  digitalWrite(LeftMtrInput2, LOW);
  
  digitalWrite(RightMtrInput1, LOW);
  digitalWrite(RightMtrInput2, LOW);
  
  analogWrite(EnableLeftMtr, 0);
  analogWrite(EnableRightMtr,0);
  delay(500);
  }
