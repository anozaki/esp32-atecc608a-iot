# FIXME: Hacky hacky... need to research how esp-idf cmake works.
set(CRYPTOAUTHLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../external/cryptoauthlib/lib")

set(CRPYTOAUTHLIB_SRC
        ${CRYPTOAUTHLIB_DIR}/atca_cfgs.c
        ${CRYPTOAUTHLIB_DIR}/atca_command.c
        ${CRYPTOAUTHLIB_DIR}/atca_device.c
        ${CRYPTOAUTHLIB_DIR}/atca_execution.c
        ${CRYPTOAUTHLIB_DIR}/atca_iface.c)
set(CRPYTOAUTHLIB_ATCACERT_SRC
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_client.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_date.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_def.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_der.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_host_hw.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_host_sw.c
        ${CRYPTOAUTHLIB_DIR}/atcacert/atcacert_pem.c)
set(CRPYTOAUTHLIB_BASIC_SRC
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_aes.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_aes_cbc.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_aes_cmac.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_aes_ctr.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_aes_gcm.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_checkmac.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_counter.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_derivekey.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_ecdh.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_gendig.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_genkey.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_hmac.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_info.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_lock.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_kdf.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_mac.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_nonce.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_privwrite.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_random.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_read.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_secureboot.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_selftest.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_sha.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_sign.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_updateextra.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_verify.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_basic_write.c
        ${CRYPTOAUTHLIB_DIR}/basic/atca_helpers.c)
set(CRPYTOAUTHLIB_CRYPTO_SRC
        ${CRYPTOAUTHLIB_DIR}/crypto/atca_crypto_sw_ecdsa.c
        ${CRYPTOAUTHLIB_DIR}/crypto/atca_crypto_sw_rand.c
        ${CRYPTOAUTHLIB_DIR}/crypto/atca_crypto_sw_sha1.c
        ${CRYPTOAUTHLIB_DIR}/crypto/atca_crypto_sw_sha2.c
        ${CRYPTOAUTHLIB_DIR}/crypto/hashes/sha1_routines.c
        ${CRYPTOAUTHLIB_DIR}/crypto/hashes/sha2_routines.c)
set(CRPYTOAUTHLIB_HOST_SRC
        ${CRYPTOAUTHLIB_DIR}/host/atca_host.c)
set(CRPYTOAUTHLIB_MBEDTLS_SRC
        ${CRYPTOAUTHLIB_DIR}/mbedtls/atca_mbedtls_ecdh.c
        ${CRYPTOAUTHLIB_DIR}/mbedtls/atca_mbedtls_wrap.c)

set(CRYPTOAUTHLIB_HAL_SRC
        ${CRYPTOAUTHLIB_DIR}/hal/atca_hal.c
        ${CRYPTOAUTHLIB_DIR}/hal/hal_esp32_i2c.c
        ${CRYPTOAUTHLIB_DIR}/hal/hal_esp32_timer.c)


set(COMPONENT_SRCS
        main.c
        ${CRPYTOAUTHLIB_SRC}
        ${CRPYTOAUTHLIB_ATCACERT_SRC}
        ${CRPYTOAUTHLIB_BASIC_SRC}
        ${CRPYTOAUTHLIB_CRYPTO_SRC}
        ${CRPYTOAUTHLIB_HOST_SRC}
        ${CRPYTOAUTHLIB_MBEDTLS_SRC}
        ${CRYPTOAUTHLIB_HAL_SRC})

set(COMPONENT_ADD_INCLUDEDIRS
        ${CRYPTOAUTHLIB_DIR}
        ${CRYPTOAUTHLIB_DIR}/hal
        ${CRYPTOAUTHLIB_DIR}/atcacert
        ${CRYPTOAUTHLIB_DIR}/crypto
        ${CRYPTOAUTHLIB_DIR}/crypto/hashes
        ${CRYPTOAUTHLIB_DIR}/basic
        ${CRYPTOAUTHLIB_DIR}/host
        ${CRYPTOAUTHLIB_DIR}/mbedtls
        "include"
        ".")

register_component()

target_compile_options(${COMPONENT_TARGET} PRIVATE -DATCA_HAL_I2C -DATCAPRINTF)
