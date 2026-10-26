/*
 * Copyright (c) 2026 Satoshi Yoshihara
 *
 * SPDX-License-Identifier: MIT
 *
 * Interface between ZMK core and the HID over ESB module
 * (zmk-feature-esb-hid). The functions are implemented by the module
 * and are only called when CONFIG_ZMK_ESB_HID is enabled.
 */

#pragma once

#include <stdbool.h>

#include <zmk/hid.h>

/** Whether the ESB link is initialized and ready to carry reports. */
bool zmk_esb_hid_is_ready(void);

/** Send the current keyboard report body over ESB (mirrors zmk_hog_send_keyboard_report). */
int zmk_esb_hid_send_keyboard_report(struct zmk_hid_keyboard_report_body *body);

/** Send the current consumer report body over ESB (mirrors zmk_hog_send_consumer_report). */
int zmk_esb_hid_send_consumer_report(struct zmk_hid_consumer_report_body *body);

#if IS_ENABLED(CONFIG_ZMK_POINTING)
/** Send the current mouse report body over ESB (mirrors zmk_hog_send_mouse_report). */
int zmk_esb_hid_send_mouse_report(struct zmk_hid_mouse_report_body *body);
#endif /* IS_ENABLED(CONFIG_ZMK_POINTING) */
