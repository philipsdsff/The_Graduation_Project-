

#include <NewPing.h>
NewPing sonar_1 (38,39);
NewPing sonar_2 (42,43);
NewPing sonar_4 (36,37);
NewPing sonar_7( 30,31);

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



int A_motor_speed = 2;
int A_motor_backward = 4;
int A_motor_forward = 3;

int B_motor_speed = 5;
int B_motor_backward = 7;
int B_motor_forward = 6;


int C_motor_speed = 8;
int C_motor_backward = 10;
int C_motor_forward = 9;


int D_motor_speed = 11;
int D_motor_backward = 13;
int D_motor_forward = 12;


int E_motor_speed = 14;
int E_motor_backward = 16;
int E_motor_forward = 15;


int F_motor_speed = 17;
int F_motor_backward = 19;
int F_motor_forward = 18;
int Speed=255;

void forward()
{
  
        analogWrite (A_motor_speed, Speed);
        digitalWrite(A_motor_forward, HIGH);
        digitalWrite(A_motor_backward, LOW);
               
        analogWrite (B_motor_speed,   Speed);
        digitalWrite(B_motor_forward,  HIGH);        
        digitalWrite(B_motor_backward,  LOW);

         analogWrite(C_motor_speed,  Speed);
        digitalWrite(C_motor_forward,  HIGH);        
        digitalWrite(C_motor_backward,  LOW);

        analogWrite (D_motor_speed,  Speed);
        digitalWrite(D_motor_forward, HIGH);
        digitalWrite(D_motor_backward, LOW);
               
        analogWrite (E_motor_speed, Speed);
        digitalWrite(E_motor_forward,  HIGH);        
        digitalWrite(E_motor_backward,  LOW);

         analogWrite (F_motor_speed,Speed);
        digitalWrite(F_motor_forward,  HIGH);        
        digitalWrite(F_motor_backward,  LOW);
}

void backward()
{
  
        analogWrite (A_motor_speed,Speed);
        digitalWrite(A_motor_forward, LOW);
        digitalWrite(A_motor_backward, HIGH);
               
        analogWrite (B_motor_speed,Speed);
        digitalWrite(B_motor_forward,  LOW);        
        digitalWrite(B_motor_backward,  HIGH);

         analogWrite(C_motor_speed,   Speed);
        digitalWrite(C_motor_forward,  LOW);        
        digitalWrite(C_motor_backward,  HIGH);

        analogWrite (D_motor_speed, Speed);
        digitalWrite(D_motor_forward, LOW);
        digitalWrite(D_motor_backward, HIGH);
               
        analogWrite (E_motor_speed, Speed);
        digitalWrite(E_motor_forward,  LOW);        
        digitalWrite(E_motor_backward,  HIGH);

         analogWrite (F_motor_speed, Speed);
        digitalWrite(F_motor_forward,  LOW);        
        digitalWrite(F_motor_backward,  HIGH);
}


void Left ()
{

      
        analogWrite (A_motor_speed, Speed);
        digitalWrite(A_motor_forward, HIGH);
        digitalWrite(A_motor_backward, LOW);
               
        analogWrite (B_motor_speed, Speed);
        digitalWrite(B_motor_forward,  LOW);        
        digitalWrite(B_motor_backward,  HIGH);

         analogWrite(C_motor_speed, Speed);
        digitalWrite(C_motor_forward,  HIGH);        
        digitalWrite(C_motor_backward,  LOW);

        analogWrite (D_motor_speed,Speed);
        digitalWrite(D_motor_forward, LOW);
        digitalWrite(D_motor_backward, HIGH);
               
        analogWrite (E_motor_speed,Speed);
        digitalWrite(E_motor_forward,  HIGH);        
        digitalWrite(E_motor_backward,  LOW);

        analogWrite (F_motor_speed,Speed);
        digitalWrite(F_motor_forward, LOW);        
        digitalWrite(F_motor_backward,  HIGH);
}

void Right ()
{
  
       analogWrite (B_motor_speed,Speed);
        digitalWrite(B_motor_forward, HIGH);
        digitalWrite(B_motor_backward, LOW);
               
        analogWrite (D_motor_speed,Speed);
        digitalWrite(D_motor_forward,  HIGH);        
        digitalWrite(D_motor_backward,  LOW);

         analogWrite(F_motor_speed,Speed);
        digitalWrite(F_motor_forward,  HIGH);        
        digitalWrite(F_motor_backward,  LOW);

        analogWrite (A_motor_speed,Speed);
        digitalWrite(A_motor_forward, LOW);
        digitalWrite(A_motor_backward, HIGH);
               
        analogWrite (C_motor_speed,Speed);
        digitalWrite(C_motor_forward,  LOW);        
        digitalWrite(C_motor_backward,  HIGH);

        analogWrite (E_motor_speed,  Speed);
        digitalWrite(E_motor_forward,  LOW);        
        digitalWrite(E_motor_backward,  HIGH);

}
void Stop()
{
        analogWrite (A_motor_speed,     0   ); 
        analogWrite (B_motor_speed,     0   );
        analogWrite (C_motor_speed,     0   ); 
        analogWrite (D_motor_speed,     0   );
        analogWrite (E_motor_speed,     0   ); 
        analogWrite (F_motor_speed,     0   );
        
} 

void setup() {
  Serial.begin(9600);
}


void loop() {

   if ((( sonar_1.ping_cm()==0) || (sonar_1.ping_cm()>d_critical)) && (( sonar_2.ping_cm()== 0) || (sonar_2.ping_cm()>d_critical))){
    forward();
   }
else if ((( sonar_1.ping_cm()>0) && (sonar_1.ping_cm()<d_critical)) || (( sonar_2.ping_cm()> 0) && (sonar_2.ping_cm()<d_critical))){
Stop();
  delay(500);
   if(((sonar_4.ping_cm()<sonar_7.ping_cm())&&sonar_4.ping_cm()>0)|| sonar_7.ping_cm()==0){
  
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


  Left();
    delay(t);
    Stop();
    delay(200);
    forward();
    delay(700);
    Stop();
   delay(200);
     Right();
  delay(t); 
  Stop();
  delay(100);}
   
 else if(((sonar_7.ping_cm()<sonar_4.ping_cm())&&(sonar_7.ping_cm()>0))|| (sonar_4.ping_cm()==0 )){


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


   Right();
    delay(t);
    Stop();
   delay(200);
   forward();
   delay(700);
   Stop();
   delay(200);
     Left();
    delay(t);
    Stop();
   delay(100);}
   }
   else{
    forward();
   }
}
    

 


 




