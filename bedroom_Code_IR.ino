/*email-mukulwadhokar@gmail.com*/

#include <IRremote.h>

int IRpin = 9;  // pin for the IR sensor
int led = 13;
int relay1=3; //relay pin 3 
int dt=50; //delay time to blink an led
int relay2=4;// Relay 2 pin 4  
IRrecv irrecv(IRpin);      
decode_results results;  //store the recieved signal in results
void setup()
{
   pinMode(led, OUTPUT);
   pinMode(relay1,OUTPUT);
   pinMode(relay2,OUTPUT);
   digitalWrite(relay1,HIGH);   // pinmode for relay is initially set to high coz of its active low config
   digitalWrite(relay2,HIGH);
   Serial.begin(9600);
  irrecv.enableIRIn();                      // Start the receiver
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);       
    irrecv.resume();
        
  if(results.value== 1886388479) // turn ON relay1 (relay is active low)                                        
  {
             digitalWrite(relay1,LOW);
             blinkLed();
             
  }
  else if(results.value == 1886437439) // Your OFF button value 
  {
             
             digitalWrite(relay1,HIGH);
             blinkLed();
             }
    else if(results.value == 1886396639 ) // turn off relay 2 
  {
             
             digitalWrite(relay2,HIGH);
             blinkLed();
  }
      else if(results.value ==  1886421119) // turn on relay 2 
  {
             
             digitalWrite(relay2,LOW);
             blinkLed();
  }
                              }
 }
 void blinkLed(){                  // this function is optional, it is for the purpose of trouble shooting 
  digitalWrite(led,HIGH);
    delay(dt);
    digitalWrite(led,LOW);
    delay(dt);
    digitalWrite(led,HIGH);
    delay(dt);
    digitalWrite(led,LOW);
    delay(dt);
    digitalWrite(led,HIGH);
    delay(dt);
    digitalWrite(led,LOW);
    delay(dt);
 }
 
 
