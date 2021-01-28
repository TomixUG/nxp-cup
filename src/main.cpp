#include "mbed.h"
#include "Shield.h"

#include <vector>
#include <list>

Serial pc(USBTX, USBRX);

Shield shield;

float speed = 22.5;

bool Contains(const list<int> &list, int x) //to check if list contains x
{
  return find(list.begin(), list.end(), x) != list.end();
}

int main()
{
  pc.printf("Started!\r\n");
  shield.init();
  
  while (1)
  {
    int *val = shield.getCamData();

    //find the differences
    int highest[127];
    for (int i = 1; i < 127; ++i)
    {
      highest[i] = abs(val[i] - val[i + 1]);
    }

    // //calculate avarage //not used
    // int avarage = 0;
    // for (int i = 1; i < 127; ++i)
    // {
    //   avarage = (avarage + highest[i]);
    // }
    // avarage = (avarage / 127);

    //find the biggest difference, indexA
    int highA = highest[1];
    int indexA = 0;
    for (int i = 1; i < 127; i++)
    {
      if (highest[i] > highA)
      {
        highA = highest[i];
        indexA = i;
      }
    }

    //find big difference near indexA
    list<int> ignore;
    for (int i = -10; i < 11; i++)
    {
      int ignoredIndex = indexA + i;
      // if (highest[ignoredIndex] > avarage)
      // {
        ignore.push_back(ignoredIndex);
      // }
    }

    //find the second biggest difference, indexB
    int highB = highest[1];
    int indexB = 0;
    for (int i = 1; i < 127; i++)
    {
      if (highest[i] > highB && Contains(ignore, i) == false) //TODO: make the Contains check smarter
      {
        highB = highest[i];
        indexB = i;
      }
    }

    int index = (indexA + indexB) / 2;

    // printf("%d | %d | %d\r\n", indexA, indexB, ignore.size());
    printf("%d\r\n", index);
    // wait(0.3);

    float resultM = -((index * 3.125) - 200); //TODO: fix this junk math
    shield.setServo(resultM);
    // printf("%g \r\n", resultM);

    //MOTORS
    if (shield.getSw1() == true)
    {
      //speed adjustment Works well
      float speedConst = 0.006;
      float speedSl = speed * (1 - (speedConst * abs(resultM)));
      //right, left speed adjustment
      float speedTurnConst = 0.004;
      float speedTurnSDR = speedSl * (1 - (speedTurnConst * resultM));
      float speedTurnSDL = speedSl * (1 + (speedTurnConst * resultM));

      shield.setMotors(speedTurnSDR, speedTurnSDL);
    }
    else 
    {
      shield.setMotors(0,0);
    }
    //EMERGENCY SHUTDOWN
    if(shield.getSwA() == true)
    {
      shield.setMotors(0,0);
      break;
    }
  }

  /*  ------------- tools -----------*/
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
}
