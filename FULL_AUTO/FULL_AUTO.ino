#include <NewPing.h>
#include<Servo.h> 
NewPing sonar_1 (27,28);
NewPing sonar_2 (29,30);
NewPing sonar_3 (33,34);
NewPing sonar_4( 31,32);
Servo servo_1;
Servo servo_2;

#define ENCODEROUTPUT 333
 
const int HALLSEN_A = 3; // Hall sensor A connected to pin 3 (external interrupt)
volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
 
int A_motor_speed = 8;
int A_motor_backward = 10;
int A_motor_forward = 9;

int B_motor_speed = 11;
int B_motor_backward = 13;
int B_motor_forward = 12;


int C_motor_speed = 5;
int C_motor_backward = 7;
int C_motor_forward = 6;


int D_motor_speed = 14;
int D_motor_backward = 17;
int D_motor_forward = 15;


int E_motor_speed = 21;
int E_motor_backward = 23;
int E_motor_forward = 22;


int F_motor_speed = 24;
int F_motor_backward = 26;
int F_motor_forward = 25;
int Speed=255;
int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;
int d_c=60;
int i=90;
int k=90;
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
   encoderValue = 0;
   previousMillis = millis();
    EncoderInit();
servo_1.attach(35);
servo_2.attach(36);
servo_1.write(90);
servo_2.write(90);
}

void loop(){
servo_1.write(135);
servo_2.write(45);
servo_1.write(90);
servo_2.write(90); 
 if ((( sonar_1.ping_cm()==0) || (sonar_1.ping_cm()>d_c)) && (( sonar_2.ping_cm()== 0) || (sonar_2.ping_cm()>d_c))){
    forward();
   }
else if ((( sonar_1.ping_cm()>0) && (sonar_1.ping_cm()<d_c)) || (( sonar_2.ping_cm()> 0) && (sonar_2.ping_cm()<d_c))){
Stop();
  delay(500);
  
}  



  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

   

    // Revolutions per minute (RPM) =
    // (total encoder pulse in 1s / motor encoder output) x 60s
    rpm = (float)(encoderValue * 60 / ENCODEROUTPUT);

    // Only update display when there have readings
    if ( rpm > 0) {
      

      Serial.print(encoderValue);
      Serial.print(" pulse / ");
      Serial.print(ENCODEROUTPUT);
      Serial.print(" pulse per rotation x 60 seconds = ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }      
  

}


void EncoderInit(){
 
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);
}


void updateEncoder()
{
  
  encoderValue++;
}
 
