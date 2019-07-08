#!/usr/bin/env bash

DIR="$( git rev-parse --show-toplevel )"

export IDF_PATH=$DIR/external/esp-idf
export PATH=$IDF_PATH/tools:$DIR/external/xtensa-esp32-elf/bin:$PATH
export ESPPORT=$1

# Just in case something is setting this.
unset LDFLAGS

pipenv shell