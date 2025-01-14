//Tanzilur Rahman
//Student ID:200595789
//15/08/2024

#include <Wire.h>
#include <IRremote.h>
#define IR_RECEIVE_PIN 11

int led=12;

void setup()
{  
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(led,OUTPUT);
  
}
int IR = -1;
byte x = 0;

void loop()
{if (IrReceiver.decode()) {
	IrReceiver.resume();
  	IR = IrReceiver.decodedIRData.command;
  	showled();
 	x=IR;
	Wire.beginTransmission(4); // transmit to device #4      
    Serial.println(x);         // print the integer
 	Wire.write(x);              // sends one byte
 	Wire.endTransmission();    // stop transmitting
 	delay(500);
  }
 
}
void showled(){
digitalWrite(led,HIGH);
delay(200);
digitalWrite(led,LOW);
}