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
#include "freertos/queue.h"

#include "hub75e/HUB75ELib.h"
#include "sajdah_logo_bitmap.h"

#define STATUS_LED_Pin 2
#define BUTTON_INPUT 0

QueueHandle_t interputQueue;

void IRAM_ATTR gpio_interrupt_handler(void *args)
{
    xQueueSendFromISR(interputQueue, &args, NULL);
}

void gpio_interrupt_init(gpio_num_t gpio_num, gpio_int_type_t edge) // custom fucntion
{
    gpio_config_t io_conf;
    io_conf.intr_type = edge;
    io_conf.pin_bit_mask = (1ULL << gpio_num);
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = 1;
    io_conf.pull_down_en = 0;
    gpio_config(&io_conf);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(gpio_num, gpio_interrupt_handler, (void *)gpio_num);
}

void Matrix_Display_Task(void *params)
{
    int pinNumber, s_ledstage = 1;
    while (true)
    {
        if (xQueueReceive(interputQueue, &pinNumber, portMAX_DELAY))
        {
            gpio_set_direction(STATUS_LED_Pin, GPIO_MODE_OUTPUT);
            gpio_set_level(STATUS_LED_Pin, s_ledstage);
            s_ledstage = !s_ledstage;
            HUB75E_Init();
            // printf("test\n");
            HUB75E_setDisplayBrightness(BrightnessLevel3);
            HUB75E_setDisplayColor(White);
            HUB75E_setDisplayBuffer(sajdah_logo_bitmap);
            HUB75E_displayBufferPixels();
        }
    }
}

void app_main(void)
{
    gpio_interrupt_init(BUTTON_INPUT, GPIO_INTR_POSEDGE);
    interputQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(Matrix_Display_Task, "Matrix_Display_Task", 2048, NULL, 12, NULL);
}
