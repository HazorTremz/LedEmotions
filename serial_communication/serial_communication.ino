#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int start = 3;  
const int stops = 4;
const int pause = 5;
const int next = 6;
const int play = 7;     

String input;

int startState = 0; 
int stopState = 0;        
int pauseState = 0; 
int nextState = 0; 
int playState = 0; 

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(start, INPUT);
  pinMode(stops, INPUT);
  pinMode(pause, INPUT);
  pinMode(next, INPUT);
  pinMode(play, INPUT);
}

void loop() {
    if (Serial.available() > 0){
    input = Serial.readString();
    lcd.print(input);
  }

  startState = digitalRead(start);
  stopState = digitalRead(stops);
  pauseState = digitalRead(pause);
  nextState = digitalRead(next);
  playState = digitalRead(play);
  if (startState == HIGH){
    Serial.print("START");
    delay(2000);
  }if(stopState == HIGH){
    Serial.print("STOP");
    delay(2000);
  }if(pauseState == HIGH){
    Serial.print("PAUSE");
    delay(2000);
  }if(nextState == HIGH){
    Serial.print("NEXT");
    delay(2000);
  }if(playState == HIGH){
    Serial.print("PLAY");
    delay(2000);
  }

}
