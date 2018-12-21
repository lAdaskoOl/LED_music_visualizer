#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 8
#define Mic A0

CRGB leds[NUM_LEDS];

int val = 0;
int pause = 100;

struct color {
  int r;
  int g;
  int b;
};
typedef struct color Color;

void setup() {
  Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    pinMode(Mic, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(Mic);

  updateLEDs();
  
  FastLED.show();

  Serial.println(val);
  delay(pause);
}

void updateLEDs() {

  if(val > 320) {
    leds[0] = CRGB(0, 0, 0);
    pause = 100;
  }
  else if(val < 320) {
    leds[0] = CRGB(7, 0, 7);
    pause = val * (200/345);
  }
  else { 
    leds[0] = CRGB(0, 0, 0);
  }

  for(int i = NUM_LEDS; i > 0; i--) {
    leds[i] = leds[i-1];
  }
}
