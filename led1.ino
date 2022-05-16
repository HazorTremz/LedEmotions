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



CRGB leds[num_led];

int led0 = 0;
int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;
int led5 = 0;
int led6 = 0;
int led7 = 0;
int led8 = 0;
int led9 = 0;
int led10 = 0;
int led11 = 0;
int led12 = 0;
int led13 = 0;
int led14 = 0;
int led15 = 0;
int led16 = 0;
int led17 = 0;
int led18 = 0;
int transfer1 = 0;
int transfer2 = 0;
int transfer3 = 0;
int transfer4 = 0;
int transfer5 = 0;
int transfer6 = 0;
int transfer7 = 0;
int transfer8 = 0;
int transfer9 = 0;
int transfer10 = 0;
int transfer11 = 0;
int transfer12 = 0;
int transfer13 = 0;
int transfer14 = 0;
int transfer15 = 0;
int transfer16 = 0;
int transfer17 = 0;
int h = 0;
 


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
 
   if (millisElapsed > SAMPLE_TIME) {
    
     Serial.println(sampleBufferValue);


     transfer1 = led1;
    transfer2 = led2;
    transfer3 = led3;
    transfer4 = led4;
    transfer5 = led5;
    transfer6 = led6;
    transfer7 = led7;
    transfer8 = led8;
    transfer9 = led9;
    transfer10 = led10;
    transfer11 = led11;
    transfer12 = led12;
    transfer13 = led13;
    transfer14 = led14;
    transfer15 = led15;
    transfer16 = led16;
    transfer17 = led17;
    led2 = transfer1;
    led3 = transfer2;
    led4 = transfer3;
    led5 = transfer4;
    led6 = transfer5;
    led7 = transfer6;
    led8 = transfer7;
    led9 = transfer8;
    led10 = transfer9;
    led11 = transfer10;
    led12 = transfer11;
    led13 = transfer12;
    led14 = transfer13;
    led15 = transfer14;
    led16 = transfer15;
    led17 = transfer16;
    led18 = transfer17;


     

    led1 = sampleBufferValue;

    if (led1 <= 30){
      led1 = 0 ;
    }
    //Serial.println(led1);
   
    leds[1].red = led1 ;
    leds[2].red = led2  ;
    leds[3].red = led3  ;
    leds[4].red = led4  ;
    leds[5].red = led5  ;
    leds[6].red = led6  ;
    leds[7].red = led7  ;
    leds[8].red = led8  ;
    leds[9].red = led9 ;
    leds[10].red = led10  ;
    leds[11].red = led11  ;
    leds[12].red = led12  ;
    leds[13].red = led13  ;
    leds[14].red = led14  ;
    leds[15].red = led15  ;
    leds[16].red = led16  ;
    leds[17].red = led17  ;
    leds[18].red = led18 ;
    FastLED.show();
    delay(30);
    leds[1].red = 0 ;
    leds[2].red = 0 ;
    leds[3].red = 0  ;
    leds[4].red = 0  ;
    leds[5].red = 0  ;
    leds[6].red = 0  ;
    leds[7].red = 0  ;
    leds[8].red = 0  ;
    leds[9].red = 0 ;
    leds[10].red = 0  ;
    leds[11].red = 0  ;
    leds[12].red = 0  ;
    leds[13].red = 0  ;
    leds[14].red = 0  ;
    leds[15].red = 0  ;
    leds[16].red = 0  ;
    leds[17].red = 0  ;
    leds[18].red = 0 ;
    FastLED.show();
    delay(10);
//  ||-------------------------------------||
   

// ||--------------------------------||
    sampleBufferValue = 0;
     millisLast = millisCurrent;
     
}}
