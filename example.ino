 
#include <Wire.h>
#include "RTC.h"

time_date test={23,57,00,3,3,9,14};
time_date time;

void setup() {

    Serial.begin(9600);
    Serial.println("Start");
    Wire.begin();
     //setTime(test);

}

void loop() {
  delay(2000);
  
  time = readTime();
  printTime(time);
}
