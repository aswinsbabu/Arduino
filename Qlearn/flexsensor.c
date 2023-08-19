//Code 2.0 
//Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Flex Sensor controlled Robo Hand
//new bend 714--778--781--711--780--

//new open 575--676--598--623--645--
//         571-577


/* Min  581  680   605    625            716 789    759     736
Max     585  682   608    628            738 811    779     769
Average 583  681.1 606.91 626.056        726 796.89 765.25  744.30
        Flex1 Flex2 Flex3 Flex4       Flex 1 Flex 2  Flex 3  Flex 4
  */
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int flex1 = A1;
int flex2 = A2;
int flex3 = A3;
int flex4 = A4;
int flex5 = A5;
;
void setup()  
{
  Serial.begin(9600);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
}


void loop()
{
  int flex1_pos;  
  int servo1_pos;  
  flex1_pos = analogRead(flex1); 
  servo1_pos = map(flex1_pos, 587, 716, 180, 0); 
  servo1_pos = constrain(servo1_pos, 180, 0);  
  servo1.write(servo1_pos);

  int flex2_pos;  
  int servo2_pos;  
  flex2_pos = analogRead(flex2); 
  servo2_pos = map(flex2_pos, 685, 811, 0, 180); 
  servo2_pos = constrain(servo2_pos, 0, 180);  
  servo2.write(servo2_pos);
  

  int flex3_pos;  
  int servo3_pos;  
  flex3_pos = analogRead(flex3); 
  servo3_pos = map(flex3_pos, 608, 759, 180, 0); 
  servo3_pos = constrain(servo3_pos, 180, 0);  
  servo3.write(servo3_pos);
  
  int flex4_pos;  
  int servo4_pos;  
  flex4_pos = analogRead(flex4); 
  servo4_pos = map(flex4_pos, 628, 736, 0, 180); 
  servo4_pos = constrain(servo4_pos, 0, 180);  
  servo4.write(servo4_pos);
  
  int flex5_pos;  
  int servo5_pos;  
  flex5_pos = analogRead(flex5); 
  servo5_pos = map(flex5_pos, 645, 780, 180, 0); 
  servo5_pos = constrain(servo5_pos, 180, 0);  
  servo5.write(servo5_pos);
  

  /*
Serial.print(servo1_pos);
Serial.print("--");
Serial.print(servo2_pos);
Serial.print("--");
Serial.print(servo3_pos);
Serial.print("--");
Serial.print(servo4_pos);
Serial.print("--");
Serial.print(servo5_pos);
Serial.println("--");
*/
Serial.print("\n");
//Serial.print(flex1_pos);
//Serial.print("--");
//Serial.print(flex2_pos);
//Serial.print("--");
//Serial.print(flex3_pos);
//Serial.print("--");
//Serial.print(flex4_pos);
//Serial.print("--");
//Serial.print(flex5_pos);
//Serial.println("--");

  delay(300);
 
 
}
