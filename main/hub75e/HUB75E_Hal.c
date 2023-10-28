/*
 * HUB75E_Hal.c
 *
 *  Created on: May 28, 2020
 *      Author: raeeskattali
 */
#include "HUB75E_Hal.h"
#include "driver/gpio.h"

// #define P2_LED_PWR_Pin 1
#define HUB75E_OE_Pin 21
#define HUB75E_LATCH_Pin 3
#define HUB75E_CLK_Pin 33
#define HUB75E_ADDR_D_Pin 23
#define HUB75E_ADDR_C_Pin 1
#define HUB75E_ADDR_B_Pin 32
#define HUB75E_ADDR_A_Pin 22
#define HUB75E_ADDR_E_Pin 19
#define HUB75E_G2_Pin 27
#define HUB75E_B2_Pin 25
#define HUB75E_R2_Pin 26
#define HUB75E_G1_Pin 12
#define HUB75E_B1_Pin 14
#define HUB75E_R1_Pin 13

void HUB75E_GPIO_Init(void)
{
	// esp_rom_gpio_pad_select_gpio(P2_LED_PWR_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_OE_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_LATCH_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_CLK_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_ADDR_D_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_ADDR_C_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_ADDR_B_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_ADDR_A_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_ADDR_E_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_G2_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_B2_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_R2_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_G1_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_B1_Pin);
	esp_rom_gpio_pad_select_gpio(HUB75E_R1_Pin);

	// gpio_set_direction(P2_LED_PWR_Pin, GPIO_MODE_OUTPUT);
	gpio_set_direction(HUB75E_OE_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_LATCH_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_CLK_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_ADDR_D_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_ADDR_C_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_ADDR_B_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_ADDR_A_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_ADDR_E_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_G2_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_B2_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_R2_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_G1_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_B1_Pin, GPIO_MODE_DEF_OUTPUT);
	gpio_set_direction(HUB75E_R1_Pin, GPIO_MODE_DEF_OUTPUT);
}

void HUB75E_DelayUs(int us)
{
	for (int i = 0; i < (us * 10); i++)
		;
	// DWT_Delay(us);
}

void HUB75E_setPin(HUB75EPin p, int state)
{

	switch (p)
	{
	case PinRed1:
		gpio_set_level(HUB75E_R1_Pin, state);
		break;
	case PinRed2:
		gpio_set_level(HUB75E_R2_Pin, state);
		break;
	case PinGreen1:
		gpio_set_level(HUB75E_G1_Pin, state);
		break;
	case PinGreen2:
		gpio_set_level(HUB75E_G2_Pin, state);
		break;
	case PinBlue1:
		gpio_set_level(HUB75E_B1_Pin, state);
		break;
	case PinBlue2:
		gpio_set_level(HUB75E_B2_Pin, state);
		break;
	case PinADDRA:
		gpio_set_level(HUB75E_ADDR_A_Pin, state);
		break;
	case PinADDRB:
		gpio_set_level(HUB75E_ADDR_B_Pin, state);
		break;
	case PinADDRC:
		gpio_set_level(HUB75E_ADDR_C_Pin, state);
		break;
	case PinADDRD:
		gpio_set_level(HUB75E_ADDR_D_Pin, state);
		break;
	case PinADDRE:
		gpio_set_level(HUB75E_ADDR_E_Pin, state);
		break;
	case PinCLK:
		gpio_set_level(HUB75E_CLK_Pin, state);
		break;
	case PinLATCH:
		gpio_set_level(HUB75E_LATCH_Pin, state);
		break;
	case PinOE:
		gpio_set_level(HUB75E_OE_Pin, state);
		break;
	default:
		break;
	}
}
