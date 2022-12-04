#include <NewPing.h> 
NewPing sonar_2 (2,4);
#include<Servo.h> 
Servo servo;
int i=90;
void setup() {
  servo.attach(8);
Serial.begin(9600);
servo.write(i);
}

void loop() {

  if (( sonar_2.ping_cm()> 0) && (sonar_2.ping_cm()<60)){
     
     while ( (i<=170) && ( ( sonar_2.ping_cm()>0) && (sonar_2.ping_cm()<60))){
     servo.write (i); 
    
    
     
    delay(2000);
      Serial.println(i);
       i=i+20 ;
  }
  
  servo.write (90);
  i=90 ;
  
  }
 
  }

