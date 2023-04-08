// Written by Jean-Pierre Manapsal

#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int enablePin, int inPin1, int inPin2) 
  : m_enablePin{enablePin}, m_inPin1{inPin1}, m_inPin2{inPin2}
{
  pinMode(m_enablePin, OUTPUT);
  pinMode(m_inPin1, OUTPUT);
  pinMode(m_inPin2, OUTPUT);

  digitalWrite(m_inPin1, HIGH);
  digitalWrite(m_inPin2, LOW);
}

void Motor::SetSpinMode(SpinMode mode) {
  if (m_mode == mode)
    return;

  m_mode = mode;

  if (mode == Mode1)
  {
    digitalWrite(m_inPin1, HIGH);
    digitalWrite(m_inPin2, LOW);
    return;
  }

  digitalWrite(m_inPin1, LOW);
  digitalWrite(m_inPin2, HIGH);
}

void Motor::SetSpeed(int speed) {
  if (speed < 0)
    speed = 0;
  else if (speed > 255)
    speed = 255;

  analogWrite(m_enablePin, speed);
}