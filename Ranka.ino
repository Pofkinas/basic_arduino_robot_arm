#include  <Servo.h> 

Servo servo1;  
Servo servo2; 
Servo servo3;
Servo servo4;

int kaire = 0; 
int desine = 0;

int pos1 = 90;  
int pos2 = 90; 
int pos3 = 90;
int pos4 = 90;

const int maxk = 180;
const int mink = 15;
const int movement = 2;

const int switchpin = 2;
const int k = 3;   
const int d = 4;

const int outservo1= 5;
const int outservo2 = 6; 
const int outservo3 = 7;
const int outservo4 = 11;


const int led1 = 9;
const int led2 = 10;
const int led3 = 8;
const int led4 = 12;  

byte bpresses = 0;
byte pressc = 0;


void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(switchpin, INPUT);
  
  pinMode(outservo1, OUTPUT);
  pinMode(outservo2, OUTPUT);
  pinMode(outservo3, OUTPUT);
  pinMode(outservo4, OUTPUT);
  
  pinMode(kaire, INPUT);
  pinMode(desine, INPUT); 

  servo1.attach(outservo1);
  servo2.attach(outservo2);
  servo3.attach(outservo3);
  servo4.attach(outservo4);

  Serial.begin(9600);
}


void loop() {

  kaire = digitalRead(k);
  desine = digitalRead(d);

  if (digitalRead(switchpin) == HIGH){
    Serial.print ("Paspausta = ");   
    bpresses++;  
    Serial.println(bpresses, DEC);                          
    delay(250);
    }
    
  if (bpresses == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    if(kaire){
      if(pos1 < maxk){ 
        pos1 += movement;
        delay(30);
        servo1.write(pos1); 
        Serial.print ("Servo: ");
        Serial.println(pos1,DEC);
        }                   
      }
      
    if(desine){
      if(pos1 > mink){ 
        pos1 -= movement;
        delay(30);
        servo1.write(pos1); 
        Serial.print ("Servo: ");
        Serial.println(pos1,DEC);
        }                                
      } 
    }
  
  
  
  if (bpresses == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    if(kaire){
      if(pos2 < maxk){ 
        pos2 += movement;
        delay(30);
        servo2.write(pos2); 
        Serial.print ("Servo: ");
        Serial.println(pos2,DEC);
        }                   
      }
      
    if(desine){
      if(pos2 > mink){ 
        pos2 -= movement;
        delay(30);
        servo2.write(pos2); 
        Serial.print ("Servo: ");
        Serial.println(pos2,DEC);
        }                                
      } 
    }
    
if (bpresses == 3){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    
    if(kaire){      
      if(pos3 < maxk){ 
        pos3 += movement;
        delay(30);
        servo3.write(pos3); 
        Serial.print ("Servo: ");
        Serial.println(pos3,DEC);
        }                   
      }
      
    if(desine){     
      if(pos3 > mink){ 
        pos3 -= movement;
        delay(30);
        servo3.write(pos3); 
        Serial.print ("Servo: ");
        Serial.println(pos3,DEC);
        }                                
      }  
   }

if (bpresses == 4){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    
    if(kaire){   
      if(pos4 < maxk){ 
        pos4 += movement;
        delay(30);
        servo4.write(pos4); 
        Serial.print ("Servo: ");
        Serial.println(pos4,DEC);
        }                   
      }
      
    if(desine){
      
      if(pos4 > mink){ 
        pos4 -= movement;
        delay(30);
        servo4.write(pos4); 
        Serial.print ("Servo: ");
        Serial.println(pos4,DEC);
        }                                
      }  
   }
   
if (bpresses == 5) {
    bpresses = 1;
    }

if (pressc != bpresses){
  
    Serial.print ("Servo Selected = ");
    Serial.println(bpresses, DEC);
    Serial.print ("Servo1 position: ");
    Serial.println(pos1,DEC);
    Serial.print ("Servo2 position: ");
    Serial.println(pos2,DEC);
    Serial.print ("Servo3 position: ");
    Serial.println(pos3,DEC);
    Serial.print ("Servo4 position: ");
    Serial.println(pos4,DEC);
    pressc = bpresses; }


}

      
