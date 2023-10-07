int trigpin = 2;
int echopin = 11;
int pingtraveltime;
int distance;

#include <Servo.h>
int servopin = 9;
int servopos = 180;
Servo myservo;


void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  myservo.attach(servopin);
  //Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  pingtraveltime = pulseIn(echopin, HIGH);
  delay(25);
  distance = (pingtraveltime * 0.034) / 2;
  //Serial.println(distance);

  if(distance <= 80){
    myservo.write(0);
    delay(3000);
  }
  
  else{
    myservo.write(180);
  }
  
  // put your main code here, to run repeatedly
}
