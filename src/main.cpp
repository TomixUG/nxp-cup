#include "mbed.h"
#include "Shield.h"

Serial pc(USBTX, USBRX);

Shield shield;

int main()
{
  pc.printf("Started!\r\n");
  shield.init();
  shield.setMotors(15,15);

  while (1)
  {
    int *val = shield.getCamData();

    int result = val[0];
    int index;

    for (int i = 32; i < 96; ++i) //using only from 32nd to 96th pixel, makes less mistakes
    {
      if (result > val[i])
      {
        result = val[i];
        index = i;
      }
    }

    float resultM = (index*3.125)-200; //TODO: fix this junk math
    shield.setServo(-resultM);
    printf("%d | %d | %g \r\n", result, index, resultM);

    wait(0.01);
  }


}

/* browser viewer */
// while(1) {
//     switch(pc.getc()) {
//         case '1': break;
//     }

//     int * val = shield.getCamData();
//     //%d int
//     for (int i = 0; i < 127; i++) {
//       printf("%d;", val[i]);
//     }
//     // printf("\r\n");
// }

/* camera test */
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