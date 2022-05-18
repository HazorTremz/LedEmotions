#include<FastLED.h>
#define data_pin 2
#define num_led 18
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB


const int OUT_PIN = 8;
const int SAMPLE_TIME = 50;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;


int hue = 290;
int huedelta = 3; 
CRGB leds[num_led];


CRGB led[num_led] = {0};
CRGB transfer_value[num_led - 1 ] = {0};



void setup() {

  FastLED.addLeds<LED_TYPE,data_pin,COLOR_ORDER>(leds, num_led).setCorrection(TypicalLEDStrip);
  Serial.begin(9600);
}


void loop() {

   



   millisCurrent = millis();
   millisElapsed = millisCurrent - millisLast;
 
   if (digitalRead(OUT_PIN) == LOW) {
     sampleBufferValue++;
   }
  
    int sensorValue = analogRead(A0);

     if (millisElapsed > SAMPLE_TIME) {
    
     Serial.println(sampleBufferValue);
 
    for(int i=0;i<num_led;i++){
      transfer_value[i] = led[i];
    }

    for(int i=1;i<=num_led;i++){
      led[i] = transfer_value[i-1];
    }

    if(sampleBufferValue >= 5){
      led[0] = CHSV(hue,255,255);
      hue += 1 ;
      hue = hue%360;
    }
    else {
      led[0] = 0;
    }
    

     for(int i=0;i<=num_led;i++){
      leds[i] = led[i];
    }
    FastLED.show();
    delay(30);
    
    for(int i=0;i<=num_led;i++){
      leds[i] = 0;
    }
    FastLED.show();
    delay(10);

     sampleBufferValue = 0;
     millisLast = millisCurrent;
    
     
}}
