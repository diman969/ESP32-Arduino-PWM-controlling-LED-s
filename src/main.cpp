#include <Arduino.h>
#define FIRST_LED 16
#define PWM_CHANNEL 0
#define FREQUENCY 5000
#define RESOLUTION 8

void setup() {
  // put your setup code here, to run once:
  ledcSetup(PWM_CHANNEL, FREQUENCY, RESOLUTION);
  ledcAttachPin(FIRST_LED, PWM_CHANNEL);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle+=2){   
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, dutyCycle);
    delay(5);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle-=2){
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, dutyCycle);   
    delay(5);
  }
}