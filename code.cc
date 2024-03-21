#include <Servo.h>

#define temperaturePin A1 
#define microphonePin A0
#define cryThreshold 500 
#define comfortThreshold 20 

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  
  int rawTemperature = analogRead(temperaturePin);
  float voltage = rawTemperature * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100; 

  
  int soundLevel = analogRead(microphonePin);

  
  if (soundLevel > cryThreshold) {
    Serial.println("Baby is crying!");
   
    servo.write(90); 
    delay(1000); 
    servo.write(0); 
  } else {
    if (temperatureC > comfortThreshold) {
      Serial.println("Baby is not comfortable with the temperature. Adjusting...");
      
      Serial.print("Temperature: ");
      Serial.print(temperatureC);
      Serial.println(" °C");
    } else {
      Serial.println("Baby is not crying. Temperature is comfortable.");
      
      Serial.print("Temperature: ");
      Serial.print(temperatureC);
      Serial.println(" °C");
    }
  }

  delay(2000); 
}
