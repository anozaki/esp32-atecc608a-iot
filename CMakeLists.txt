# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

set(ENV{IDF_PATH} ${CMAKE_CURRENT_LIST_DIR}/external/esp-idf)

set(ATCA_HAL_I2C ON CACHE INTERNAL "")
set(ATCA_MBEDTLS ON CACHE INTERNAL "")
set(ATCA_PKCS11 OFF CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 17)
set(EXTRA_COMPONENT_DIRS
  "./external/esp-aws-iot")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32-atecc608-iot-demo)

