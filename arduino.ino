#include <SoftwareSerial.h>
#include <math.h>
#include <SPI.h>


#define TEMP_PIN  A4

SoftwareSerial esp(4,5);


void setup() {
esp.begin(9600);
String check; 
String bot;

}

void loop() {
String check;  
while (check != "temp"){
  check = Serial.read();
  }
temp();
    


}
void temp(){
  float v_temp = 1023.0 / analogRead(TEMP_PIN)- 1.0;
  float temp = 1.0 / (-log(v_temp)/3977.0 + 1.0 / 295.0) - 273.0;
String  bot =  String (temp);
  delay (100);
  Serial.print(bot);
  
  }
