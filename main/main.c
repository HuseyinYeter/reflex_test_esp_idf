#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <time.h>
#include "esp_random.h"
#include <esp_timer.h>
// Kontrol edilecek pin
#define LED1_PIN GPIO_NUM_13
#define LED2_PIN GPIO_NUM_14

#define BUTTON1_PIN GPIO_NUM_26
#define BUTTON2_PIN GPIO_NUM_32
void app_main(void)
{
    gpio_config_t led_yapilandirma = {
        .pin_bit_mask = (1ULL << LED1_PIN) | (1ULL << LED2_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE};

    gpio_config_t button_yapilandirma = {
        .pin_bit_mask = (1ULL << BUTTON1_PIN) | (1ULL << BUTTON2_PIN),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE};

    gpio_config(&led_yapilandirma);
    gpio_config(&button_yapilandirma);

    srand(esp_random());

    while (1)
    {
        printf("Sistem Basladi!\n");
        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 0);

        vTaskDelay(pdMS_TO_TICKS(1500) + ((rand() % 3) + 1));
        int rastgele = (rand() % 2) + 1;
        int basildi = 0;
        if (rastgele == 1)
        {
            gpio_set_level(LED1_PIN, 1);
        }
        else
        {
            gpio_set_level(LED2_PIN, 1);
        }
        int64_t init = esp_timer_get_time();
        for (int sure = 0; sure < 500; sure++)
        {
            if (rastgele == 1)
            {

                if (gpio_get_level(BUTTON1_PIN) == 0)
                {
                    printf("Dogru Zamanlama!\n");
                    basildi = 1;
                    break;
                }
            }
            else // rastgele == 2
            {

                if (gpio_get_level(BUTTON2_PIN) == 0)
                {
                    printf("Dogru Zamanlama!\n");
                    basildi = 1;
                    break;
                }
            }
            vTaskDelay(pdMS_TO_TICKS(10));
        }

        if (basildi)
        {
            int64_t time = (esp_timer_get_time() - init) / 1000;
            printf("Skorun : %lld ms\n", time);
        }
        else
        {
            printf("Sure bitti! Yavassin.\n");
        }
        gpio_set_level(LED1_PIN, 0);
        gpio_set_level(LED2_PIN, 0);
    }
}