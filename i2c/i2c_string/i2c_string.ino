
#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int sendnumber = 0;
int state = 0;
String mystring;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); // start serial for output
// initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Ready!");
}

void loop() {
  delay(100);
}

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
  //Wire.write(mystring.length());
 // Wire.write(9);
  Wire.write("nonesense");
  /*for(int i=mystring.length(); i; i--)
    Wire.write(mystring[i]); */
//  Wire.write(sendnumber);*/
  Serial.println("sent");
}

