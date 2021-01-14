#ifndef SHIELD_H_
#define SHIELD_H_

class Shield
{
public:
    Shield();
    void init();
    void setServo(float input);
    void setMotors(float pwrL, float pwrR);

    float getPot1();
    float getPot2();

    bool getSwA();
    bool getSwB();
    bool getSw1();
    bool getSw2();
    bool getSw3();
    bool getSw4();
}; 

#endif