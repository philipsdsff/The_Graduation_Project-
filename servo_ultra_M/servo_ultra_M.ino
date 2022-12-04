#include <NewPing.h> 
NewPing sonar_2 (2,4);
#include<Servo.h> 
Servo servo;
int i=90;
float alpha=3.8152;
float theta=3.8152;
int d_critical=120;
int phi=0;
float t=0;
float t_r=10;
void setup() {
  servo.attach(8);
Serial.begin(9600);
servo.write(i);


}

void loop() {

  if (( sonar_2.ping_cm()> 0) && (sonar_2.ping_cm()<d_critical)){
     
     while ( (i<=170) && ( ( sonar_2.ping_cm()>0) && (sonar_2.ping_cm()<d_critical))){
       servo.write (i); 
       delay(2000);
       Serial.println(i);
       phi=i;
       i=i+20 ;
      }
  servo.write (90);
  i=90 ;
  
  theta=alpha+phi;
  t=theta*t_r/360;

  }
 
  }

