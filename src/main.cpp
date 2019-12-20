#include <Arduino.h>

volatile boolean flag;
volatile unsigned long myTimer;
void myInterrupt();

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    
    // Use D2 in pinmode and attach
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(0, myInterrupt, FALLING);
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (flag)
    {
        Serial.print("INTERRUPT!!!");
        Serial.println(myTimer);
        flag = 0;
    }
}
void myInterrupt()
{
    flag = 1;
    myTimer = millis() ;
}