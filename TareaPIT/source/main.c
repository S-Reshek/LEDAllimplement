
#include "MK64f12.h"
#include "PIT.h"
#include "NVIC.h"
#include "GPIO.h"
#define SYSTEM_CLOCK 21000000
#define DELAY 0.25F


int main(void) {

	uint8 pitIntrStatus = FALSE; /**------------------------------------ Variable que se utiliza como bandera de la interrupción*/
	GPIO_pinControlRegisterType pinControlRegisterPORTD = GPIO_MUX1; /** Configuracion del GPIO puerto D*/

	PIT_clockGating(); /**-----------------------------------------------Funcion para activar el PIT */
	GPIO_clockGating(GPIO_D); /** ---------------------------------------Activacion del ClockGating del puerto D*/
	GPIO_pinControlRegister(GPIO_D,BIT0,&pinControlRegisterPORTD); /** --Activador del BIT 0 del puerto D*/
	GPIO_dataDirectionPIN(GPIO_D,GPIO_OUTPUT,BIT0); /** -----------------Dirección del Bit 0 del puerto D como salida */
	GPIO_setPIN(GPIO_D,BIT0); /** ---------------------------------------Establece el bit 0 el puerto D */

	NVIC_enableInterruptAndPriotity(PIT_CH0_IRQ, PRIORITY_10); /** ------Habilita la prioridad de las interrupciones */
	EnableInterrupts;/** ------------------------------------------------Habilitar interrupciones */

    while(1) {

    	GPIO_tooglePIN(GPIO_D,BIT0);/**----------------------------------Se hace un toogle al valor del bit 0 del puerto D con la finalidad de invertir el valor y lograr hacer la señal cuadrada*/
		PIT_clear(); /** ------------------------------------------------Se limpia la bandera de la interrupcion del PIT.c para la siguiente iteración */
    	pitIntrStatus = PIT_getIntrStatus(); /**-------------------------Se obtiene el valor actual de la bandera de interrupcion, en este punto debe ser falsa */
		PIT_delay(PIT_0,SYSTEM_CLOCK,DELAY); /**-------------------------Se mandan los valores de systemclock, tiempo y el puerto para que se calcule cuantos ciclos se requieren para actiar la interrupción*/
		while(FALSE == pitIntrStatus) /**--------------------------------Mientras la bandera de interrupcion sea falsa estará dentro del ciclo, esto para esperar a que el tiempo de la interrupión se cumpla*/
			pitIntrStatus = PIT_getIntrStatus();/**----------------------Se pregunta contantemente si la interrupción ya ocurrio o no */

    }
    return 0 ;
}
