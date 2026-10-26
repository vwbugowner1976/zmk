/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

int zmk_usb_hid_send_keyboard_report(void);

/**
 * Send a raw HID report body (without report ID) received from another
 * transport, e.g. the ESB HID receiver. The report ID is prepended here
 * so the bytes on the USB wire match a locally generated report.
 * Note: always uses the report protocol format; boot protocol hosts are
 * not supported by this path.
 */
int zmk_usb_hid_send_report_with_id(uint8_t report_id, const uint8_t *body, size_t len);
int zmk_usb_hid_send_consumer_report(void);
#if IS_ENABLED(CONFIG_ZMK_POINTING)
int zmk_usb_hid_send_mouse_report(void);
#endif // IS_ENABLED(CONFIG_ZMK_POINTING)
void zmk_usb_hid_set_protocol(uint8_t protocol);
