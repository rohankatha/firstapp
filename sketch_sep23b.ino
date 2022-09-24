const int sensorIn = 34;     
int mVperAmp = 185;           
float Watt = 0;
double Voltage = 0;
float VRMS = 0;
float AmpsRMS = 0;
 int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

unsigned long counterChannelNumber = 1579822;            // Channel ID
const char * myCounterReadAPIKey = "7QBL3BU91N258B48"; // Read API Key
const int FieldNumber1 = 1;  
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;
int sensor = 15;
unsigned long start_time = 0;
unsigned long end_time = 0;
int steps=0;
float steps_old=0;
float temp=0;
float rps=0;


#include <WiFi.h>
#include "ThingSpeak.h"
#include<HTTPClient.h>
const char* ssid = "OnePlus Nord";   // your network SSID (name) 
const char* password = "Rohan123";   // your network password

WiFiClient  client;
HTTPClient http;

unsigned long myChannelNumber = 1595621;
const char * myWriteAPIKey = "CZUAMVMDJXDLHDGT";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}
float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 4096;          // store min value here ESP32 ADC resolution
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       
       if (readValue > maxValue) 
       {
           
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           minValue = readValue;
       }
   }
   
  
   result = ((maxValue - minValue) * 5)/4096.0; 
      
   return result;
 }
void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(sensor,INPUT_PULLUP);
  
  ledcSetup(pwmChannel, freq, resolution);
  
  
  ledcAttachPin(enable1Pin, pwmChannel);
  Serial.begin(9600);  //Initialize serial
  
  
WiFi.begin(ssid,password);
  
  ThingSpeak.begin(client); 
 
}

void loop() {
   
    
  
    
      
  Voltage = getVPP();
  VRMS = (Voltage/2.0) *0.707;   //root 2 is 0.707
  AmpsRMS = ((VRMS * 1000)/mVperAmp)-0.3; //0.3 is the error I got for my sensor
 
   long temp = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  
  Watt = (AmpsRMS*temp);
  float dutyCycle = 255*temp/10.2;
 
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  ledcWrite(pwmChannel, dutyCycle);   
  start_time=millis();
 end_time=start_time+1000;
 while(millis()<end_time)
 {
   if(digitalRead(sensor))
   {
    steps=steps+1; 
    while(digitalRead(sensor));
   }
  
 }
    temp=steps-steps_old;
    steps_old=steps;
    rps=(temp/20);
    
  
    
    
    
   ThingSpeak.setField(1,AmpsRMS);
    ThingSpeak.setField(2, Watt);
    ThingSpeak.setField(3, rps);

     
    
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);


    
    
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
}
