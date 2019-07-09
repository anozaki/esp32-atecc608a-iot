/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <esp_log.h>

#include <esp_system.h>
#include <esp_task_wdt.h>
#include <esp_spi_flash.h>
#include <tcpip_adapter.h>

#include <atca_basic.h>


#define TAG "Main"

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

    ATCA_STATUS status;
    ATCAIfaceCfg cfg = cfg_ateccx08a_i2c_default;

    // default bus is 2 but ESP32 only has 2 interface so we need to choose 0/1
    cfg.atcai2c.bus = 1;

    // default address is 0xC0
    cfg.atcai2c.slave_address = 0xC0;

    // 1Mhz
    cfg.atcai2c.baud = 100000;

    // We are working with ATECC608A
    cfg.devtype = ATECC608A;

    if (ATCA_SUCCESS != (status = atcab_init(&cfg))) {
        ESP_LOGE(TAG, "Unable to initialize atecc608a: %x", status);
        return;
    }

    bool lock = false;
    if (ATCA_SUCCESS != atcab_is_locked(ATCA_ZONE_CONFIG, &lock)) {
        ESP_LOGE(TAG, "Unable to read lock status");
        return;
    }

    uint8_t revision;
    if (ATCA_SUCCESS != atcab_info(&revision)) {
        ESP_LOGE(TAG, "Unable to read revision");
        return;
    }

    uint8_t sn[9];
    if (ATCA_SUCCESS != atcab_read_serial_number(sn)) {
        ESP_LOGE(TAG, "Unable to read serial");
        return;
    }

    ESP_LOGI(TAG, "ATECC608A: lock[%s] revision[%d]", lock ? "true" : "false", revision);
    ESP_LOG_BUFFER_HEXDUMP(TAG, sn, 9, ESP_LOG_INFO);
}

