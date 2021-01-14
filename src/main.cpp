#include "mbed.h"
#include "Shield.h"

Serial pc(USBTX, USBRX);

Shield shield;


int main()
{
  pc.printf("Started!\r\n");
  shield.init();

  /* button test */
  // while(1)
  // {
  //   pc.printf("A: %d | B: %d | 1: %d | 2: %d | 3: %d | 4: %d\r\n", shield.getSwA(),shield.getSwB(),shield.getSw1(),shield.getSw2(),shield.getSw3(),shield.getSw4());
  //   wait(0.5);
  // }



  /* motor test */
  // float position = 0.5;
  //   while(1) {                   
  //       switch(pc.getc()) {
  //           case '1': position = 100; break;
  //           case '2': position = 0; break;
  //           case '3': position = -100; break;
  //           case '8': position = position+5; break;
  //           case '9': position = position-5; break;
  //       }
  //       pc.printf("%g\r\n", position);
  //       shield.setMotors(position,position);
  //       // shield.setServo(position);
  //   }
}
