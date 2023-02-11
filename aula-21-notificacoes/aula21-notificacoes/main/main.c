#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static TaskHandle_t taskHandler = NULL;

void Task1(void * params) {
    while(1) {
        xTaskNotifyGive(taskHandler);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void Task2(void * params) {
    while(1) {
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        printf("Notificação Recebida\n");
        
    }
}

void app_main(void)
{
    xTaskCreate(&Task1,"Task1",2048,NULL,2,&taskHandler);
    xTaskCreate(&Task1,"Task1",2048,NULL,2,&taskHandler);
}