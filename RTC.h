#ifndef __RTC_H
#define __RTC_H

#include <Arduino.h>
#include <Wire.h>

// time_date time={12,59,59,7,

// struktura pre cas z RTC
struct time_date {
    uint8_t hour;       // hodiny
    uint8_t min;        // minuty
    uint8_t sec;        // sekundy

    uint8_t week_day;   // den v tyzdni
    uint8_t month_day;  // den v mesiaci
    uint8_t month;      // mesiac
    uint8_t year;       // rok
    
    uint8_t a_hour;     // adresa ulozenia v EEPROM
    uint8_t a_min;      // adresa ulozenia v EEPROM
};

const int DS1307 = 0x68; // Address of DS1307 see data sheets
// const char* days[] ={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
// const char* months[] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

byte decToBcd(byte val);
byte bcdToDec(byte val);
void setTime(time_date);
time_date setTimeUart();
time_date readTime();
void printTime(time_date);

#endif
