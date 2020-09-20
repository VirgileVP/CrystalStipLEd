/*
 * Example sketch using FastLED for RGBW strips (SK6812). Includes
 * color wipes and rainbow pattern.
 *
 * Written by David Madison
 * http://partsnotincluded.com
*/
/*
#include "FastLED.h"
#include "FastLED_RGBW.h"
 
#define NUM_LEDS0 300
#define NUM_LEDS1 216
#define NUM_LEDS NUM_LEDS0 + NUM_LEDS1
#define DATA_PIN0 2
#define DATA_PIN1 3
 
CRGBW leds[NUM_LEDS];
CRGB *ledsRGB = (CRGB *) &leds[0];
 
const uint8_t brightness = 255;
 
void setup() { 
 FastLED.addLeds<WS2812B, DATA_PIN0, RGB>(ledsRGB, getRGBWsize(NUM_LEDS0));
 FastLED.addLeds<WS2812B, DATA_PIN1, RGB>(ledsRGB, getRGBWsize(NUM_LEDS1));
  FastLED.setBrightness(brightness);
  FastLED.show();
}
 
void loop(){
  colorFill(CRGB::Red);
  colorFill(CRGB::Green);
  colorFill(CRGB::Blue);
  fillWhite();
}
 
void colorFill(CRGB c){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = c;
    FastLED.show();
    delay(5);
  }
}
 
void fillWhite(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGBW(0, 0, 0, 255);
    FastLED.show();
    delay(5);
  }
}



*/


#include <Adafruit_NeoPixel.h>

#define LED_PIN0  2
#define LED_PIN1  3
#define LED_COUNT0  300
#define LED_COUNT1  214

Adafruit_NeoPixel pixels0 = Adafruit_NeoPixel(LED_COUNT0, LED_PIN0, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(LED_COUNT1, LED_PIN1, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels0.begin();
  pixels0.show(); // Initialize all pixels to 'off'
  pixels0.setBrightness(255);
  pixels1.begin();
  pixels1.show(); // Initialize all pixels to 'off'
  pixels1.setBrightness(255);
}

void loop() {
  //pixels1.setPixelColor(0, 0, 0, 0, 255);
  //pixels1.show();
  int i = 0;
  while (i < LED_COUNT0 + LED_COUNT1) {
    //if (i > 0)
    //  setPixel(i - 1, 0, 0, 0, 0);
    //else
    //  setPixel(LED_COUNT0 + LED_COUNT1 -1, 0, 0, 0, 0);
    setPixel(i, 0, 0, 255, 255);
    i++;
    pixels0.show();
    pixels1.show();
    delay(2);
  }
}

void  setPixel(int i, int r, int g, int b, int w) {
  if (i < 300)
    pixels0.setPixelColor(i, r, g, b, w);
  else
    pixels1.setPixelColor(i - 300, r, g, b, w);
}
