//////////////////////////
// Ultrasonic Sensor Test
// 10/2/2013
/////////////
#include <SoftwareSerial.h>
int TP = 12;
int EP = 13;

void setup() {
  Serial.begin(9600);
  pinMode(TP,OUTPUT);
  pinMode(EP,INPUT);
}

unsigned long timing()
{
  digitalWrite(TP, LOW);
  delayMicroseconds(2);
  digitalWrite(TP, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP, LOW);
  unsigned long duration = pulseIn(EP,HIGH);
  return duration;
}

void ranging()
{
  unsigned long duration = timing();
  float distance_cm = (float)duration /29 / 2;
  Serial.print(distance_cm);
  Serial.println("cm");
}

void loop()
{
  ranging();
  delay(100);
}




