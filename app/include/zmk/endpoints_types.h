/*
 * Copyright (c) 2021 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/**
 * The method by which data is sent.
 * @note This type is used in settings. Do not modify existing values.
 */
enum zmk_transport {
    ZMK_TRANSPORT_NONE = 0,
    ZMK_TRANSPORT_USB = 1,
    ZMK_TRANSPORT_BLE = 2,
    ZMK_TRANSPORT_ESB = 3,
};

/**
 * Configuration to select an endpoint on ZMK_TRANSPORT_USB.
 */
struct zmk_transport_usb_data {};

/**
 * Configuration to select an endpoint on ZMK_TRANSPORT_BLE.
 */
struct zmk_transport_ble_data {
    int profile_index;
};

/**
 * Configuration to select an endpoint on ZMK_TRANSPORT_ESB.
 */
struct zmk_transport_esb_data {
    int device_index;
};

/**
 * A specific endpoint to which data may be sent.
 */
struct zmk_endpoint_instance {
    enum zmk_transport transport;
    union {
        struct zmk_transport_usb_data usb; // ZMK_TRANSPORT_USB
        struct zmk_transport_ble_data ble; // ZMK_TRANSPORT_BLE
        struct zmk_transport_esb_data esb; // ZMK_TRANSPORT_ESB
    };
};
