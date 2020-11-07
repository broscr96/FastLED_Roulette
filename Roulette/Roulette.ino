#include <FastLED.h>

#define NUM_LEDS 12
#define DATA_PIN 3
#define BUTTON_PIN 5

CRGB leds[NUM_LEDS];

int speed = 50;
bool buttonReady;

void setup() {
  Serial.begin(9600);
  Serial.println("Resetting");
  LEDS.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
  LEDS.setBrightness(10);
  FastLED.clear();
  FastLED.show();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(speed);
    if (digitalRead(BUTTON_PIN) == LOW && buttonReady) {
      buttonReady = false;
      if (i == 1) for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Green;
      else for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Red;
      FastLED.show();
      delay(500);
      break;
    }
    leds[i] = CRGB::Black;
    if (i == 1) leds[i] = CRGB::MediumVioletRed;
    FastLED.show();
    if (i == NUM_LEDS - 1) buttonReady = true;
  }
}
