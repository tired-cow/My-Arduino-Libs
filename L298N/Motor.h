// Written by Jean-Pierre Manapsal

#ifndef _MOTOR_H_
#define _MOTOR_H_

class Motor {
  public:
    enum SpinMode {
      Mode1, Mode2
    };

  protected:
    int m_enablePin;
    int m_inPin1;
    int m_inPin2;
    SpinMode m_mode;

  public:
    Motor(int, int ,int);
    void SetSpinMode(SpinMode);
    void SetSpeed(int);
};

#endif