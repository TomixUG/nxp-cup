#include "mbed.h"
#include "Shield.h"

Serial pc(USBTX, USBRX);

Shield shield;

int main()
{
  pc.printf("Started!\r\n");
  shield.init();

  /* camera test /*
  // while(true) {       
  //   int * val = shield.getCamData();            
  //   printf("Val: %zu\r\n", val[50]);
  //   wait(0.2);
  // }

  /* motor test */
  // float position = 10;
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
  //       // printf("%g \r\n", VBAT.read());
  //       // shield.setServo(position);
  //   }
}
