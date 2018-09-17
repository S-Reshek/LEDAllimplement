#include <stdio.h>
#include "MK64F12.h"

int main(void) {
  SIM-> SCGC5 = 0x2400;


  PORTB -> PCR[22] = 0X00000100;
  PORTB -> PCR[21] = 0X00000100;
  PORTE -> PCR[26] = 0X00000100;


  GPIOB-> PDOR |= 0x00400000; //bit 22 para prender el led , con el gpio le decimos que es lo que queremos que haga ese puerto
  GPIOB-> PDOR = 0x00200000;
  GPIOE-> PDOR = 0x04000000;

  GPIOB-> PDDR = 0x00400000;
  GPIOB-> PDDR |= 0x00200000;
  GPIOE-> PDDR = 0x04000000;


  while(1){

	  	  	  	GPIOB->PDOR |= 0x00200000;
	  	  	    GPIOE->PDOR |= 0x4000000;

	  	  	    GPIOB->PDOR &= ~(0x00400000);
                printf("RED LED ON\n");

                GPIOB -> PDOR = 0x00400000;

                printf("RED LED OFF\n");

                GPIOB->PDOR &= ~(0x00200000);
                printf("BLUE LED ON\n");

                GPIOB -> PDOR |= 0x00200000;
                printf("BLUE LED OFF\n");


                GPIOE->PDOR &= ~(0x4000000);
              printf("GREEN LED ON\n");

              GPIOE -> PDOR = 0x04000000;
          printf("GREEN LED OFF\n");


  }
    return 0;

}
