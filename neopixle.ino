#include<Adafruit_NeoPixel.h>

#define led_pin 6
#define led_count 18


Adafruit_NeoPixel strip(led_count,led_pin,NEO_GRB + NEO_KHZ800);

void setup(){

  Serial.begin(9600);
  

strip.begin();
 
}

void loop(){
  

  int random_generator  = random(0,150);
  Serial.println(random_generator);
  strip.fill(strip.Color(random_generator,random_generator,random_generator), 0, 18 );
  strip.show();
  delay(100);
  strip.fill(strip.Color(0,0,0), 0,18);
 

   





}
