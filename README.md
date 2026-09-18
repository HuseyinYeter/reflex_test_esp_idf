# ESP32 ESP-IDF Refleks Test Oyunu

Bu proje, **ESP32** mikrodenetleyicisi üzerinde **ESP-IDF** ve **FreeRTOS** kullanılarak geliştirilmiş, milisaniye hassasiyetinde donanımsal süre ölçümü yapan gömülü bir refleks test uygulamasıdır.

## 🚀 Özellikler
* **ESP-IDF Mimarisi:** Arduino altyapısı kullanılmadan, doğrudan sürücü konfigürasyon yapılarıyla (`gpio_config_t`) geliştirilmiştir.
* **FreeRTOS Entegrasyonu:** Görev gecikmeleri ve zamanlama yönetimi FreeRTOS API'leri (`vTaskDelay`, `pdMS_TO_TICKS`) ile sağlanmıştır.
* **Yüksek Hassasiyetli Zaman Ölçümü:** `esp_timer_get_time()` kullanılarak milisaniyelik ($ms$) refleks skoru hesaplanır.
* **Rastgele Donanımsal Gecikme:** `esp_random()` ile her turda dinamik ve tahmin edilemeyen bekleme süreleri üretilir.
* **Parazit Koruması:** Dahili pull-up dirençleri aktif edilerek buton okuma kararlılığı artırılmıştır.

---

## 🛠️ Donanım Bağlantıları (Pinout)

| Bileşen | ESP32 GPIO Pini | Açıklama |
| :--- | :--- | :--- |
| **LED 1** | GPIO 13 | 1. Hedef Işık Çıkışı |
| **LED 2** | GPIO 14 | 2. Hedef Işık Çıkışı |
| **Button 1** | GPIO 26 | 1. Oyuncu Butonu (Pull-up / GND) |
| **Button 2** | GPIO 32 | 2. Oyuncu Butonu (Pull-up / GND) |

---


Hüseyin Yeter - Computer Engineering Student @ Çukurova University
