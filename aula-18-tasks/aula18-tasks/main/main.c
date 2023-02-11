#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void Task1(void * params) {
    while(1) {
        printf("Realizando leitura de temperatura %s \n", (char *) params);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void * params) {
    while(1) {
        printf("Realizando leitura de umidade %s \n", (char *) params);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    xTaskCreate(&Task1,"Temperatura",2048,"Tarefa 1",5,NULL);
    xTaskCreate(&Task2,"Umidade",2048,"Tarefa 2",2,NULL);
}