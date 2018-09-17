
#include <stdio.h>
#include "MK64F12.h"
#include "Bits.h"
#include "RGB.h"
#include "Delay.h"



int main(void) {


	Colors_t color = NO_COLOR;

	RGB_init();

	RGB_red_led_on_off(LED_ON);
	delay(DELAY);
	RGB_red_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_blue_led_on_off(LED_ON);
	delay(DELAY);
	RGB_blue_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_green_led_on_off(LED_ON);
	delay(DELAY);
	RGB_green_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_yellow_led_on_off(LED_ON);
	delay(DELAY);
	RGB_yellow_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_white_led_on_off(LED_ON);
	delay(DELAY);
	RGB_white_led_on_off(LED_OFF);
	delay(DELAY);
	RGB_purple_led_on_off(LED_ON);
	delay(DELAY);
	RGB_purple_led_on_off(LED_OFF);
	delay(DELAY);

    while(1) {

    	color = RGB_color_selector();

    	switch (color) {
    		case GREEN:
    			RGB_green();
    		break;
    		case BLUE:
    			RGB_blue();
    		break;
    		case PURPLE:
    			RGB_purple();
    		break;
			case RED:
				RGB_red();
			break;
			case YELLOW:
				RGB_red();
			default:
				RGB_yellow();
			break;
		}

    }
    return 0 ;
}
