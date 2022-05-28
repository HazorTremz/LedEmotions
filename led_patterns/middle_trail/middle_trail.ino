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
bool value = true;


CRGB leds[num_led];


CRGB led[num_led] = {0};
CRGB transfer_value[num_led] = {0};


void setup() {

  FastLED.addLeds<LED_TYPE,data_pin,COLOR_ORDER>(leds, num_led).setCorrection(TypicalLEDStrip);
  Serial.begin(9600);
}


void loop() {
  
  
    for(int i=0;i<num_led/2;i++){
      transfer_value[num_led/2 + i] = led[num_led/2 + i];
      transfer_value[num_led/2 - i] = led[num_led/2 - i];
      
    }

    for(int i=1;i<=num_led/2;i++){
      led[num_led/2 + i] = transfer_value[num_led/2 + i-1];
      led[num_led/2 - i] = transfer_value[num_led/2 - i+1];
    }

    if(random(1,180)%10 == 0){
      led[num_led/2] = CHSV(hue,255,255);
      if(value){
      hue += 1;
      if (value==299){value = false;}
      Serial.print(hue);}
      else{
      hue -= 1;
      if (value==0){value = true;}
      Serial.print(2);
      }
      
    }
    else {
      led[num_led/2] = 0;
    }


     for(int i=0;i<=num_led/2;i++){
      leds[num_led/2 + i] = led[num_led/2 + i];
      leds[num_led/2 - i] = led[num_led/2 - i];
      
    }
    FastLED.show();
    delay(40);
    
    for(int i=0;i<=num_led/2;i++){
      leds[num_led/2 + i] = 0;
      leds[num_led/2 - i] = 0;
      
    }
    FastLED.show();
    delay(10);
    
     
}
