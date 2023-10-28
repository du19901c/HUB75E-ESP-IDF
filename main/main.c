/*
 * main.c
 *
 *  Created on: Jun 12, 2021
 *      Author: raeekattali
 */

#include <stdio.h>
#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "hub75e/HUB75ELib.h"
#include "sajdah_logo_bitmap.h"

#define STATUS_LED_Pin 2

void Matrix_Display_Task(void *params)
{
    HUB75E_Init();
    // printf("test\n");
    HUB75E_setDisplayBrightness(BrightnessLevel3);
    HUB75E_setDisplayColor(White);
    HUB75E_setDisplayBuffer(sajdah_logo_bitmap);
    while (1)
    {
        HUB75E_displayBufferPixels();
    }
}

void app_main(void)
{
    gpio_set_direction(STATUS_LED_Pin, GPIO_MODE_OUTPUT);
    gpio_set_level(STATUS_LED_Pin, 1);

    xTaskCreate(Matrix_Display_Task, "Matrix_Display_Task", 2048, NULL, 12, NULL);
}
