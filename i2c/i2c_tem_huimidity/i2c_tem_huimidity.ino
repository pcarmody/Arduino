#include <Wire.h>
#include "dht.h"

//
// sensor connections
//

#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;

// i2c connections
//

#define SLAVE_ADDRESS 0x04
int number = 0;
int sendnumber = 0;
int state = 0;
String mystring;
unsigned long time;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600); // start serial for output
// initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  time = millis();

  Serial.println("Ready!");
}

void restart_windu()
{
  digitalWrite(4, LOW);
  delay(1000);
  time = millis();
  digitalWrite(4, HIGH);
}

void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);

digitalWrite(4, HIGH);
    if(millis() - time > 60000)
        restart_windu();
/*    if(state)
        digitalWrite(4, HIGH);
    else
      digitalWrite(4, LOW);*/

//    state = !state;
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.print("C,  ");
    Serial.print(DHT.temperature * 9.0/5.0 + 32); 
    Serial.println("F  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 

// callback for received data
void receiveData(int byteCount){
  Serial.println("In receiveData");

  mystring = "";
  while(Wire.available()) {
    char in = Wire.read();

    mystring += in;
  }

  Serial.print("Received: ");
  Serial.println(mystring);
}

// callback for sending data
void sendData(){
  Serial.println("sendData");
  String out;
  out = " H: ";
  out += DHT.humidity;
  out += ";C: ";
  out += DHT.temperature;
  int length = out.length();
  Wire.write(length);
  Wire.write(out.c_str());
  Serial.println("sent");
}

 
