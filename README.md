# ESP32 ATECC608A Demo

ESP32 demo using ATECC608A to authenticate with the AWS IoT Core.

## Building

```bash
# Checkout this repository 
git clone --recurse-submodules git@github.com:anozaki/esp32-atecc608a-iot.git

# Download build tools in external folder
./setup.sh

# Setup idf shell environment (This uses pipenv and pyenv to setup the environment)
# Specifying the serial here will allow you to set the port you want to flash/monitor on.
./idf-shell /dev/tty.usbserial-xxxxxx

# flash and monitor the idf
idf.py flash monitor
```


## TODO

* Provisioning process (integrated with esp32)
    * Generate private key on ATECC608A
    * Generate CSR
        * pull from ESP32
        * generate certificate
    * Load certificate on ATECC608A
* Provisioning process (preloaded)
    * Maybe with FT2232H?    
* Custom boot loader using ATECC608A (maybe)?
