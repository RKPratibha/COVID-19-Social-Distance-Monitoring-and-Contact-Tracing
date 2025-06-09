#include <TinyGPS++.h>
#include <SoftwareSerial.h>
/* Create object named bt of the class SoftwareSerial */
SoftwareSerial GPS_SoftSerial(6, 5);/* (Rx, Tx) */
/* Create an object named gps of the class TinyGPSPlus */
TinyGPSPlus gps;      
long duration;
int distance;


#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
 
#define REPORTING_PERIOD_MS     2000
// unsigned long temp=0;

int triPin = 8; 
int echoPin = 9;
//long microsecondsToCentimeters(long microseconds);


PulseOximeter pox;
 
uint32_t tsLastReport = 0;
float tempc;
float vout;
const int sensor = A3;
const int SW=4;
int pins=12;
int buzz=11;
// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
    Serial.println("Beat!");
}
 
void setup()
{
  //Serial.begin(9600); /* Define baud rate for serial communication */
  GPS_SoftSerial.begin(9600);
    Serial.begin(9600);
 pinMode(SW,INPUT_PULLUP);
 pinMode(pins,INPUT); 
 pinMode(buzz,OUTPUT); 
 pinMode(triPin,OUTPUT);
pinMode(echoPin,INPUT);

 digitalWrite(buzz,LOW);
 Serial.print("Initializing pulse oximeter..");

    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
        Serial.println("COVID TESTING");
    }
 
    
    pox.setOnBeatDetectedCallback(onBeatDetected);

 
}

void loop()
{

//if(digitalRead(pins)==LOW)
//{
//  Serial.println("$Band Removed#");
//  delay(1000);
//  
//}
////else
////{
////
////Serial.print("Initializing pulse oximeter..");
////
////    if (!pox.begin()) {
////        Serial.println("FAILED");
////        for(;;);
////    } else {
////        Serial.println("SUCCESS");
////        Serial.println("COVID TESTING");
////    }
//// 
////    
////    pox.setOnBeatDetectedCallback(onBeatDetected);
  int i=0;
  while(i<20000)
  {
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("$ HEARTRATE: ");
        Serial.print(pox.getHeartRate());
        //Serial.println("mm Hg");
        Serial.println("#");
       Serial.print("$ SPO2:"); 
        Serial.print(pox.getSpO2());
        Serial.println("#");

        if(pox.getHeartRate()>120)
        {
          Serial.println("$ HEARTBEAT IS HIGH #");
         // delay(2000);
        }
        if(pox.getSpO2()<90)
        {
          Serial.println("$ OXIDE_LEVEL IS LOW #");
         // delay(2000);
        }
        tsLastReport = millis();
    }
    i++;
}
//HEART_BEAT_MONITOR();
uv_reading1();
TEMP_MONITOR();

serialEvent();

}
void TEMP_MONITOR()
{
 // serialEvent();
   // tempc=vout;
    vout=analogRead(sensor);
    vout=(vout*500)/1023;
    tempc=vout;
   
    Serial.print("$TEMP:");
    Serial.print(tempc);
    Serial.println("C#");
    delay(2000);

    if(tempc>40)
    {
      Serial.println("$MORE TEMPERATURE#");
    }
    else if (tempc<35)
    {
      Serial.println("$LESS TEMPERATURE#");
    }
    else
    {
      Serial.println("$NORMAL TEMPERATURE#");
    }
    setup();
}

void serialEvent()
{


  if(digitalRead(SW)==LOW)
  {
    Serial.println("EMERGENCY...");
    Serial.println("$EMERGENCY...#");
    delay(2000);
//    Manual();
    GPS();

   } 
   


  }
void GPS()
{
  smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val, alt_m_val;
       // uint8_t hr_val, min_val, sec_val;
        bool loc_valid, alt_valid, time_valid;
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
        alt_m_val = gps.altitude.meters();  /* Get altitude data in meters */
        alt_valid = gps.altitude.isValid(); /* Check if valid altitude data is available */
//        hr_val = gps.time.hour(); /* Get hour */
//        min_val = gps.time.minute();  /* Get minutes */
//        sec_val = gps.time.second();  /* Get seconds */
        time_valid = gps.time.isValid();  /* Check if valid time data is available */
        if (!loc_valid)
        {          
          Serial.print("Latitude : ");
          Serial.println("*****");
          Serial.print("Longitude : ");
          Serial.println("*****");
        }
        else
        {
        //  DegMinSec(lat_val);
          Serial.print("Latitude in Decimal Degrees : ");
          Serial.println(lat_val, 8);
        
        //  DegMinSec(lng_val); /* Convert the decimal degree value into degrees minutes seconds form */
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 8);
         


String one = "PERSON LOCATION AT:https://www.google.com/maps/?q=";
    String two = "," ;   
    String message = one +lat_val +two + lng_val;
    
    int str_len = message.length() + 1;
    char textmessage[str_len];
    message.toCharArray(textmessage,str_len);
    Serial.println(textmessage);
    delay(3000); // wait for 3 seconds
      Serial.println(textmessage);
        Serial.print("$T");
        Serial.print(textmessage);
        Serial.println("#");
        }
        if (!alt_valid)
        {
        //  Serial.print("Altitude : ");
          Serial.println("*****");
        }
        else
        {
       //   Serial.print("Altitude : ");
          Serial.println(alt_m_val, 6);    
        }
        if (!time_valid)
        {
        //  Serial.print("Time : ");
          Serial.println("*****");
        }
        else
        {
//          char time_string[32];
//          sprintf(time_string, "Time : %02d/%02d/%02d \n", hr_val, min_val, sec_val);
//         // Serial.print(time_string);    
        }

        
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (GPS_SoftSerial.available())  /* Encode data read from GPS while data is available on serial port */
      gps.encode(GPS_SoftSerial.read());
/* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);
}

//void DegMinSec( double tot_val)   /* Convert data in decimal degrees into degrees minutes seconds form */
//{  
//  degree = (int)tot_val;
//  minutes = tot_val - degree;
//  seconds = 60 * minutes;
//  minutes = (int)seconds;
//  mins = (int)minutes;
//  seconds = seconds - minutes;
//  seconds = 60 * seconds;
//  secs = (int)seconds;
//}

void uv_reading1()
{
  digitalWrite(triPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triPin,LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  Serial.print("Distances:");
  Serial.println(distance);
  delay(1000);
if(distance<20)
{
  Serial.println("object detected..");
  digitalWrite(buzz,HIGH);
  delay(2000);
  digitalWrite(buzz,LOW);
  delay(1000);
}
}