#include <stdio.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"
#include "DataTypeDefinitions.h"


int main(void) {

	GPIO_clockGating(GPIO_A); /*Habilitamos los clocks de los puertos A,B,C y E*/
	GPIO_clockGating(GPIO_B);
	GPIO_clockGating(GPIO_C);
	GPIO_clockGating(GPIO_E);

	GPIO_pinControlRegisterType pinControlRegisterGPIO = GPIO_MUX1; /*establecemos que vamos a utilizarlos como GPIO*/
	GPIO_pinControlRegister(GPIO_B,BIT21,&pinControlRegisterGPIO);
	GPIO_pinControlRegister(GPIO_B,BIT22,&pinControlRegisterGPIO);
	GPIO_pinControlRegister(GPIO_E,BIT26,&pinControlRegisterGPIO);

	GPIO_dataDirectionPIN(GPIO_B,GPIO_OUTPUT, BIT21);/*Declaramos que los pines referentes a los LEDS van a ser OUTPUTS*/
	GPIO_dataDirectionPIN(GPIO_B,GPIO_OUTPUT,BIT22);
	GPIO_dataDirectionPIN(GPIO_E,GPIO_OUTPUT,BIT26);

	PORTC->PCR[6]  = 0x00000103;/* GPIO + PE + PS para los switches*/
	PORTA->PCR[4]  = 0x00000103;


uint8 color;
uint8 color2;
uint32 inputValueSW2;
uint32 inputValueSW3;

while(1){

	       inputValueSW2 = GPIOC->PDIR;
		   inputValueSW2 = inputValueSW2 & 0x40; /*obtenemos direccion y monemos mascara para agarrar el pin del SW2 y SW3*/
		   inputValueSW3 = GPIOA->PDIR;
		   inputValueSW3 = inputValueSW3 & 0x10;

		   inputValueSW2 = inputValueSW2 >> 6;
		   inputValueSW3 = inputValueSW3 >> 3;

	if(FALSE == inputValueSW2){ /*al presionar SW2 restamos 1 al contador */
		if(color > 0){
			color2 = color2 - 1;
			color = color2;
		}
	}

	if(FALSE == inputValueSW3){/*al presionar SW3 sumamos 1 al contador */
		if(color < 4){
			color2 = color2 + 1;
			color = color2;
			}
		}

if(FALSE == inputValueSW3 && FALSE == inputValueSW2 ){ /*Al presionar ambos establecemos el valor del contador a 5 para que nos mande al blanco*/
	color = 5 ;
}
	switch (color){ /*Switch case para cada uno de los colores en el orden que deben verse*/
	case 0:
		green();
		delay(650000);
		break;
	case 1:
		blue();
		delay(650000);
		break;
	case 2:
		purple();
		delay(650000);
		break;
	case 3:
		red();
		delay(650000);
		break;
	case 4:
		yellow();
		delay(650000);
		break;
	case 5:
		white();
		delay(650000);
		break;
	default:
		break;

	}

}
return 0;
}
