#include <Wire.h>
#include <SFE_BMP180.h>

#define LED 13

SFE_BMP180 bmp180;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  if (bmp180.begin()){
    Serial.println("Init Succesful");
  } else {
    Serial.println("Non Succesful Init");
  }
  

}

void loop() {

  char status;
  double T, P;
  bool success = false;

  double prevPres = 0;
  status = bmp180.startTemperature();

  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          //float comp = bmp180.sealevel(P, Altitude);
          digitalWrite(LED,HIGH);
          Serial.print("Pressure: ");
          Serial.print(P);
          Serial.println(" hPa");

          Serial.print("Temperature: ");
          Serial.print(T);
          Serial.println(" C");
        }
      }
    }
  }
}
