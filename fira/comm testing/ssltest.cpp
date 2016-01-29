#include <stdio.h>
#include "serial.h"
#include <sys/time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <iostream>


const int TEAM_ID = 'z';  // yellow

int main(int argc, char const *argv[])
{
	HAL::Serial serial;
	if(!serial.Open("/dev/ttyACM0", 38400)) {
		printf("Could not open port.\n");
		exit(0);
	}
	
	while (1) {
    int s[6];
    scanf("%d %d %d %d", &s[1], &s[2], &s[3], &s[4]);
    char buf[6];
    for (int i = 1; i <= 4; ++i)
    {
      buf[i] = s[i];
    }
    buf[0] = TEAM_ID;
    buf[5] = 0;
    printf("sending: %d %d %d %d\n", buf[1], buf[2], buf[3], buf[4]);
    serial.Write(buf, 6);
  }
	
	return 0;
}