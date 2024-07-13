#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <FastLED.h>
#define LED_PIN1 7 // pin neonflex
#define LED_PIN2  8 //pin neonflex
#define NUM_LEDS 40 // Cantidad de leds en la tira

CRGB leds [NUM_LEDS];

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

int pos0=102;
int pos180=512;
int puerta;

int LUZ1 = 5;
int LUZ2 = 6;


void setup() {
Serial.begin(38400);
  servos.begin ();
  servos.setPWMFreq(50);
  FastLED.addLeds<WS2812, LED_PIN1, RGB> (leds, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN2, RGB> (leds, NUM_LEDS);
PINS();
}
  void loop(){

  if (Serial.available()){
char signal = Serial.read();
Serial.println(signal);
    switch(signal) {
      case 'H':
      ONLIGHT();
      PUERTASARRIBA();
      LLANTASABAJO();
      OFFLIGHT();
        break;
      case 'I':
      NEONON();
      PUERTASABAJO();
      NEONOFF();
      LLANTASARRIBA();
        break;
      case 'J':
      RAPIDLIGHT();
      LLANTASDERABAJO();
        break;
      case 'K':
      NEONON();
      LLANTASDERABAJO();
      NEONOFF();
        break;
      case 'L':
      LLANTASIZQABAJO();
      LIGHTONOFF();
        break;
      case 'M':
      PUERTASARRIBA();
      RAPIDLIGHT();
      PUERTASABAJO();
        break;
      case 'N':
      LLANTASIZQABAJO();
      LIGHTONOFF();
        break;
      case 'O':
      NEONON();
      LLANTASDERABAJO();
        break;
      case 'P':
      ONLIGHT();
      PUERTASARRIBA();
      LLANTASARRIBA();
      PUERTASABAJO();
      LLANTASABAJO();
      OFFLIGHT();
        break;
      case 'Q':
      PUERTASARRIBA();
        NEONON();
        NEONOFF();
        PUERTASABAJO();
        break;

      default:
        break;
    }
}
  }
// NEONON();
// NEONOFF();
// PUERTASABAJO();
// PUERTASARRIBA();
// LLANTASDERABAJO();
// LLANTASIZQABAJO();
// LLANTASABAJO();
// LLANTASARRIBA();


void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map (angulo,0,180,pos0, pos180);
  servos.setPWM (n_servo, 0, duty);
}

void PINS(){
  pinMode(LUZ1,OUTPUT);
  pinMode(LUZ2,OUTPUT);
}
void ONLIGHT(){
   digitalWrite(LUZ1,HIGH);
   digitalWrite(LUZ2,HIGH);
}

void OFFLIGHT(){
   digitalWrite(LUZ1,LOW);
   digitalWrite(LUZ2,LOW);
}

void LLANTASABAJO()
{

  setServo(0,0);
  setServo(1,0);
  setServo(2,0);
  setServo(3,0);

}

void LLANTASARRIBA()
{

  setServo(0,90);
  setServo(1,90);
  setServo(2,90);
  setServo(3,90);

}

void LLANTASIZQABAJO()
{

  setServo(0,0);
  setServo(1,0);
  setServo(2,90);
  setServo(3,90);

}

void LLANTASDERABAJO()
{

  setServo(0,90);
  setServo(1,90);
  setServo(2,0);
  setServo(3,0);


}

void PUERTASARRIBA()
{

  setServo(4,160);
  setServo(5,160);
  delay(70);
  setServo(4,150);
  setServo(5,150);
  delay(70);
  setServo(4,140);
  setServo(5,140);
  delay(70);
  setServo(4,130);
  setServo(5,130);
  delay(70);
  setServo(4,120);
  setServo(5,120);
  delay(70);
  setServo(4,110);
  setServo(5,110);
  delay(70);
  setServo(4,100);
  setServo(5,100);
  delay(70);
  setServo(4,90);
  setServo(5,90);
  delay(70);
  setServo(4,80);
  setServo(5,80);
  delay(70);
  setServo(4,70);
  setServo(5,70);
  delay(70);
  setServo(4,60);
  setServo(5,60);
  delay(70);
  setServo(4,50);
  setServo(5,50);
  delay(70);
  setServo(4,40);
  setServo(5,40);
  delay(70);
  setServo(4,30);
  setServo(5,30);
  delay(70);
  setServo(4,20);
  setServo(5,20);
  delay(70);
  setServo(4,10);
  setServo(5,10);
  delay(70);
  setServo(4,0);
  setServo(5,0);
  delay(70);
  }



void PUERTASABAJO()
{

  setServo(4,0);
  setServo(5,0);
  delay(70);
  setServo(4,10);
  setServo(5,10);
  delay(70);
  setServo(4,20);
  setServo(5,20);
  delay(70);
  setServo(4,30);
  setServo(5,30);
  delay(70);
  setServo(4,40);
  setServo(5,40);
  delay(70);
  setServo(4,50);
  setServo(5,50);
  delay(70);
  setServo(4,60);
  setServo(5,60);
  delay(70);
  setServo(4,70);
  setServo(5,70);
  delay(70);
  setServo(4,80);
  setServo(5,80);
  delay(70);
  setServo(4,90);
  setServo(5,90);
  delay(70);
  setServo(4,100);
  setServo(5,100);
  delay(70);
  setServo(4,110);
  setServo(5,110);
  delay(70);
  setServo(4,120);
  setServo(5,120);
  delay(70);
  setServo(4,130);
  setServo(5,130);
  delay(70);
  setServo(4,140);
  setServo(5,140);
  delay(70);
  setServo(4,150);
  setServo(5,150);
  delay(70);
  setServo(4,160);
  setServo(5,160);
  delay(70);
  
}

void NEONON()
{

  for(int i=0; i<NUM_LEDS; i++){
  // Blue Red Green
  leds[i]= CRGB(255,255,255);
  //FastLED.setBrightness(60-2*i);
  FastLED.show();
  delay(20);
}

  delay(500);

  for(int i=NUM_LEDS; i>0; i--){
  // Blue Red Green
  leds[i]= CRGB(255,0,0);
  //FastLED.setBrightness(60-2*i);
  FastLED.show();
  delay(10);
}

  delay(500);

  for(int i=0; i<NUM_LEDS; i++){
  // Blue Red Green
  leds[i]= CRGB(0,0,255);
  //FastLED.setBrightness(60-2*i);
  FastLED.show();
  delay(10);
}

  delay(500);

  for(int i=NUM_LEDS; i>0; i--){
  // Blue Red Green
  leds[i]= CRGB(0,255,0);
  //FastLED.setBrightness(60-2*i);
  FastLED.show();
  delay(10);
}
}

void NEONOFF()
{
  for(int i=0; i<NUM_LEDS; i++)
  leds[i]=CRGB(0,0,0);
  FastLED.show();
  delay(10);
}

void LIGHTONOFF(){
    ONLIGHT();
  delay(1000);
    OFFLIGHT();
  delay(1000);
    ONLIGHT();
  delay(1000);
    OFFLIGHT();
  delay(1000);
}

void RAPIDLIGHT(){
        ONLIGHT();
      delay(400);
      OFFLIGHT();
      delay(400);
      ONLIGHT();
      delay(400);
      OFFLIGHT();
      delay(400);
}

