#include <Arduino.h>
#include <ESP32Servo.h>

//int pinPot=26;
int pinVerde = 27;
int pinAmarillo = 25;
int pinRojo = 33;

int boton=15; // ESP32 GPIO16 pin connected to button's pin
int sonido=21; // ESP32 GPIO21 pin connected to Buzzer's pin

int lastState = HIGH;

#define SERVO_PIN 26
Servo servoMotor;


void setup()
{
  Serial.begin(115200);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinRojo, OUTPUT);

  pinMode(boton, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(sonido, OUTPUT);  

  servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
 

}

void loop()
{
  digitalWrite(pinVerde, HIGH);
  delay(1500);
  digitalWrite(pinVerde, LOW);
  delay(500);

  servoMotor.write(0);
  digitalWrite(pinAmarillo, HIGH);
  delay(1500);

  digitalWrite(pinAmarillo, LOW);
  delay(500);
  servoMotor.write(90);
  Serial.println("enciende motor");

  digitalWrite(pinRojo, HIGH);
  delay(1500);

  digitalWrite(pinRojo, LOW);
  delay(500);

  int buttonState = digitalRead(boton); // read new state
  digitalWrite(sonido, lastState);
  delay(500);
  Serial.println(buttonState);

  if (buttonState == LOW) {
    Serial.println("The button is being pressed");
    lastState = LOW;
    digitalWrite(sonido, lastState); // turn off
  }
  int currentState = digitalRead(sonido); //estado actual
  lastState = currentState;//cambia a apagado
  digitalWrite(sonido, lastState);

  servoMotor.write(0);
  Serial.println("final");
  
}
