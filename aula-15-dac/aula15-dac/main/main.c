#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/dac.h"

void app_main(void)
{
    dac_output_enable(DAC_CHANNEL_1);
    dac_output_voltage(DAC_CHANNEL_1, 255); // 3.3V (0-255 DAC de 8 bits)
    vTaskDelay(10 / portTICK_PERIOD_MS);
}