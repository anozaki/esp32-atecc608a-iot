#!/usr/bin/env bash

# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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