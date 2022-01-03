#include <Arduino.h>
#define firstLedPin 16
#define secondLedPin 17
#define firstLedChannel 0
#define secondLedChannel  2
#define frequency 5000
#define resolution 8

void setup() {
  // put your setup code here, to run once:
  ledcSetup(firstLedChannel, frequency, resolution);
  ledcSetup(secondLedChannel, frequency, resolution);

  ledcAttachPin(firstLedPin, firstLedChannel);
  ledcAttachPin(secondLedPin, secondLedChannel);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int dutyCycle = 0, secondDutyCycle = 255; dutyCycle <= 255; dutyCycle++, secondDutyCycle--){   
    // changing the LED brightness with PWM
    ledcWrite(firstLedChannel, dutyCycle);
    ledcWrite(secondLedChannel, secondDutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255, secondDutyCycle = 0; dutyCycle >= 0; dutyCycle--, secondDutyCycle++){
    // changing the LED brightness with PWM
    ledcWrite(firstLedChannel, dutyCycle);   
    ledcWrite(secondLedChannel, secondDutyCycle);
    delay(15);
  }
}