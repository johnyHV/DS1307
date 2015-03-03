#include "RTC.h"

//------------------------------------------------------------------------------

/**
 *
 * @info Nastavi cas na RTC
 * @param time - struktura naplnena casom pre zapis
 * @return void
 */
time_date setTimeUart() {
    bool read_tmp = true;
    time_date tmp = {0, 0, 0, 0, 0, 0, 0};
    int a[13] = {0};

    int i = 0;
    while (read_tmp) {

        if (Serial.available() > 0) {
            a[i] = Serial.read() - 48;
            i++;
            Serial.println(a[i]);
            Serial.println(i);
        }
        if (i == 13)
            read_tmp = false;
    }
    tmp.hour = a[0];
    tmp.min = a[2];
    tmp.sec = a[4];
    Serial.print(tmp.hour);
    Serial.print(":");
    Serial.print(tmp.min);
    Serial.print(":");
    Serial.println(tmp.sec);
}




//------------------------------------------------------------------------------

/**
 *
 * @info Nastavi cas na RTC
 * @param time - struktura naplnena casom pre zapis
 * @return void
 */
void setTime(time_date times) {
    Wire.begin();
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.write(decToBcd(times.sec));
    Wire.write(decToBcd(times.min));
    Wire.write(decToBcd(times.hour));
    Wire.write(decToBcd(times.week_day));
    Wire.write(decToBcd(times.month_day));
    Wire.write(decToBcd(times.month));
    Wire.write(decToBcd(times.year));
    Wire.write(byte(0));
    Wire.endTransmission();
}

//------------------------------------------------------------------------------

/**
 *
 * @info Vycita cas z RTC
 * @param 
 * @return void
 */
time_date readTime() {
    Wire.begin();
    time_date times = {0, 0, 0, 0, 0, 0, 0};
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.endTransmission();
    Wire.requestFrom(DS1307, 7);
    times.sec = bcdToDec(Wire.read());
    times.min = bcdToDec(Wire.read());
    times.hour = bcdToDec(Wire.read());
    times.week_day = bcdToDec(Wire.read());
    times.month_day = bcdToDec(Wire.read());
    times.month = bcdToDec(Wire.read());
    times.year = bcdToDec(Wire.read());
    return times;
}


//------------------------------------------------------------------------------

/**
 *
 * @info Vypise cas na konzolu
 * @param none
 * @return void
 */
void printTime(time_date times) {
    Serial.print("Date & time: ");
    Serial.print(times.month_day);
    Serial.print(" ");
    Serial.print(times.month_day);
    Serial.print(".");
    Serial.print(times.month);
    Serial.print(".");
    Serial.print(times.year);
    Serial.print(" ");
    Serial.print(times.hour);
    Serial.print(":");
    Serial.print(times.min);
    Serial.print(":");
    Serial.print(times.sec);
    Serial.println();
}
//------------------------------------------------------------------------------

/**
 *
 * @info Dec to Bcd
 * @param hodnota
 * @return byte
 */
byte decToBcd(byte val) {
    return ((val / 10 * 16) + (val % 10));
}

//------------------------------------------------------------------------------

/**
 *
 * @info Bcd to Dec
 * @param hodnota
 * @return byte
 */
byte bcdToDec(byte val) {
    return ((val / 16 * 10) + (val % 16));
}


