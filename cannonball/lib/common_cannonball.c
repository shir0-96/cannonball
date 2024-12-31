// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lib/common_cannonball.h"
#include "lib/add_keycodes.h"

/* ポインティングデバイス用変数 */
cb_config_t cb_config;      // eeprom保存用

/* eeprom */
// 初期化
void eeconfig_init_kb(void) {
    cb_config.rgb_layers = true;
    eeconfig_update_kb(cb_config.raw);

    eeconfig_init_user();
}

// 実タスク
bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    // 追加キーコードタスク
    process_record_addedkeycodes(keycode, record);

    return process_record_user(keycode, record);
}

/* マトリクス走査 */
// 初期化
void matrix_init_kb(void) {
    cb_config.raw = eeconfig_read_kb();

    matrix_init_user();
}
