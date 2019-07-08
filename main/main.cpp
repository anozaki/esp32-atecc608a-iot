
#include <esp_log.h>

#include <esp_system.h>
#include <esp_task_wdt.h>
#include <esp_spi_flash.h>
#include <tcpip_adapter.h>

#define TAG "Main"

extern "C" {
  void app_main() {
    ESP_LOGI(TAG, "FirmwareVersion: %s", "0.0.1-SNAPSHOT");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    ESP_LOGI(TAG, "This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
	     chip_info.cores,
	     (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
	     (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    ESP_LOGI(TAG, "silicon revision %d, ", chip_info.revision);

    ESP_LOGI(TAG, "%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

        

    // give 10 sec to do work.
    esp_task_wdt_init(20, true);

    tcpip_adapter_init();
  }
};
