/*
 * RGB.c
 *
 *  Created on: 04/09/2018
 *      Author: jlpe
 */


#include "RGB.h"
#include "GPIO.h"


void RGB_init(void)
{
	GPIO_pinControlRegisterType led_config = GPIO_MUX1;
	GPIO_pinControlRegisterType sw_config = GPIO_MUX1 | GPIO_PE | GPIO_PS;

	GPIO_clockGating(BLUE_LED_PORT);
	GPIO_clockGating(RED_LED_PORT);
	GPIO_clockGating(GREEN_LED_PORT);

	GPIO_clockGating(SW2_PORT);
	GPIO_clockGating(SW3_PORT);


	GPIO_setPIN(RED_LED_PORT, RED_LED_PIN);
	GPIO_setPIN(BLUE_LED_PORT, BLUE_LED_PIN);
	GPIO_setPIN(GREEN_LED_PORT, GREEN_LED_PIN);

	GPIO_pinControlRegister(BLUE_LED_PORT, BLUE_LED_PIN, &led_config);
	GPIO_pinControlRegister(RED_LED_PORT, RED_LED_PIN, &led_config);
	GPIO_pinControlRegister(GREEN_LED_PORT, GREEN_LED_PIN, &led_config);

	GPIO_pinControlRegister(SW2_PORT, SW2_PIN, &sw_config);
	GPIO_pinControlRegister(SW3_PORT, SW3_PIN, &sw_config);

	GPIO_dataDirectionPIN(BLUE_LED_PORT, GPIO_OUTPUT, BLUE_LED_PIN);
	GPIO_dataDirectionPIN(RED_LED_PORT, GPIO_OUTPUT, RED_LED_PIN);
	GPIO_dataDirectionPIN(GREEN_LED_PORT, GPIO_OUTPUT, GREEN_LED_PIN);




}


Colors_t RGB_color_selector(void)
{
	uint8_t input_a = 0;
	uint8_t input_c = 0;
	uint8_t total_color = 0;
	static Colors_t color = RED;

	input_a = GPIO_readPIN(SW2_PORT, SW2_PIN);
	input_c = GPIO_readPIN(SW3_PORT, SW3_PIN);

	total_color = (input_a << 1) | input_c;

	if (SW2 == total_color)
	{
		if(color < YELLOW)
		{
			color++;
		}
		else
		{
			color = GREEN;
		}

	}
	else if(SW3 == total_color)
	{
		if(color == (0x00u))
		{
			color = YELLOW;
		}
		else
		{
			color--;
		}
	}

	do
	{
		input_a = GPIO_readPIN(SW2_PORT, SW2_PIN);
		input_c = GPIO_readPIN(SW3_PORT, SW3_PIN);
		total_color = (input_a << 1) | input_c;
		total_color &= SW_MASK;

	}
	while(SW_MASK != total_color);

	return(color);

}


void RGB_red_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_setPIN(RED_LED_PORT, RED_LED_PIN);
	}

}

void RGB_blue_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(BLUE_LED_PORT, BLUE_LED_PIN);
	}
	else
	{
		GPIO_setPIN(BLUE_LED_PORT, BLUE_LED_PIN);
	}
}

void RGB_green_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(GREEN_LED_PORT, GREEN_LED_PIN);
	}
	else
	{
		GPIO_setPIN(GREEN_LED_PORT, GREEN_LED_PIN);
	}
}

void RGB_yellow_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_clearPIN(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_setPIN(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_setPIN(RED_LED_PORT, RED_LED_PIN);
	}
}
void RGB_white_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_clearPIN(RED_LED_PORT, RED_LED_PIN);
		GPIO_clearPIN(BLUE_LED_PORT, BLUE_LED_PIN);
	}
	else
	{
		GPIO_setPIN(GREEN_LED_PORT, GREEN_LED_PIN);
		GPIO_setPIN(RED_LED_PORT, RED_LED_PIN);
		GPIO_setPIN(BLUE_LED_PORT, BLUE_LED_PIN);
	}
}
void RGB_purple_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clearPIN(BLUE_LED_PORT, BLUE_LED_PIN);
		GPIO_clearPIN(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_setPIN(BLUE_LED_PORT, BLUE_LED_PIN);
		GPIO_setPIN(RED_LED_PORT, RED_LED_PIN);
	}
}



void RGB_red(void)
{
	RGB_purple_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_ON);
}
void RGB_blue(void)
{
	RGB_purple_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_blue_led_on_off(LED_ON);
}
void RGB_green(void)
{
	RGB_yellow_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_ON);
	RGB_blue_led_on_off(LED_OFF);
}
void RGB_purple(void)
{
	RGB_blue_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_OFF);
	RGB_purple_led_on_off(LED_ON);
}
void RGB_yellow(void)
{
	RGB_red_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_yellow_led_on_off(LED_ON);
}

void no_color(void)
{
	RGB_green_led_on_off(LED_OFF);
	RGB_blue_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_OFF);
}
