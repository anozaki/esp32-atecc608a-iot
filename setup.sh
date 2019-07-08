#!/usr/bin/env bash

DIR="$( git rev-parse --show-toplevel )"

pushd "$DIR"

if [ ! -e external/xtensa-esp32-elf ] ; then
    case "$OSTYPE" in
      darwin*)
        ESP_TOOLCHAIN_TAR_GZ=xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-macos.tar.gz
        ;;
      linux*)
        ESP_TOOLCHAIN_TAR_GZ=xtensa-esp32-elf-gcc8_2_0-esp32-2019r1-linux-amd64.tar.gz
        ;;
      windows*)
        ;;
      *)
        echo "Unknown OS type..."
        exit 1
        ;;
    esac

    curl -O https://dl.espressif.com/dl/$ESP_TOOLCHAIN_TAR_GZ
    tar xvzf $ESP_TOOLCHAIN_TAR_GZ -C external
    rm $ESP_TOOLCHAIN_TAR_GZ
fi

# git submodule update --init --recursive

popd