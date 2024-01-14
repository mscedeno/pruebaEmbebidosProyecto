// Incluye la librería para la ESP32
#include <Arduino.h>
const int motor1 = 19;
const int motor2 = 16;

int gas=36;
int Signal=0;

const int freq = 30000;
const int canalPWM1 = 0;
const int canalPWM2 = 1;
const int resolucion = 8;

void setup()
{

  Serial.begin(115200);

  // Configurar la señal PWM
  ledcSetup(canalPWM1, freq, resolucion);
  ledcSetup(canalPWM2, freq, resolucion);
  // Asignar el pin al canal PWM
  ledcAttachPin(motor1, canalPWM1);
  ledcAttachPin(motor2, canalPWM2);
}

void loop()
{
  Signal = analogRead(gas);
  //Mostramos la señal del sensor de gas
  Serial.println(Signal); //muestra el valor del sensor de gas
  delay(1000);
  int pwm_value = map(Signal, 450, 900, 90, 190);

  ledcWrite(canalPWM1, pwm_value);
  ledcWrite(canalPWM2, 150);

}
