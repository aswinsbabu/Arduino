int m11= 3;
int m00= 5;
int Enable= 7;
void setup() {
  // put your setup code here, to run once:


pinMode(m11, OUTPUT);
pinMode(m00, OUTPUT);
pinMode(Enable, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(m11, HIGH);
digitalWrite(m00, LOW);
analogWrite(Enable,250);
delay(3000);

analogWrite(Enable,0);// stop

delay(3000);
digitalWrite(m11, LOW);
digitalWrite(m00, HIGH);
analogWrite(Enable, 250);
delay(3000);

analogWrite(Enable,0);// stop
delay(3000);
}
