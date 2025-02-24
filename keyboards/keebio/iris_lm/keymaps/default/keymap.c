// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _WINDOWS,
     _NUM,
     _SYMBOL,
     _MAC,
     _MAC_NUM,
     _MAC_SYMBOL,
     _GAME,
     _HUB,
     _LOWER,
     _RAISE
};

enum tap_dance {
   TD_BRACES,
   TD_BRACKETS,
};

enum custom_keycodes {
   WIN_NEXT_WORD = SAFE_RANGE,
   WIN_PREV_WORD,
   M_NEXT_W,   // Mac next word
   M_PREV_W,   // Mac previous word
   SW_MAC,     // Select word on Mac
   SW_WIN,     // Select word on Windows
   SL_MAC,     // Select line on Mac
   SL_WIN,     // Select line on Windows
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
   [TD_BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
   [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),

};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods
#define HOME_A_M LALT_T(KC_A)
#define HOME_S_M LCTL_T(KC_S)
#define HOME_D_M LSFT_T(KC_D)
#define HOME_F_M LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J_M RGUI_T(KC_J)
#define HOME_K_M RSFT_T(KC_K)
#define HOME_L_M RCTL_T(KC_L)
#define HOME_SC_M LALT_T(KC_SCLN)

// Tap Dance for tab key
#define M_TAB_SYM LT(_MAC_SYMBOL, KC_TAB)
#define W_TAB_SYM LT(_SYMBOL, KC_TAB)

// Mod Tap for Selections
#define M_SW_CTRL LCTL_T(SW_MAC)
#define W_SW_CTRL LCTL_T(SW_WIN)
#define M_SL_SHFT LSFT_T(SL_MAC)
#define W_SL_SHFT LSFT_T(SL_WIN)

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case M_NEXT_W:
       if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RGHT) SS_UP(X_LALT));
       } else {
       }
       break;

   case M_PREV_W:
       if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
       } else {
       }
       break;
   case WIN_NEXT_WORD:
       if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RGHT) SS_UP(X_LCTL));
       } else {
       }
       break;
   case WIN_PREV_WORD:
       if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
       } else {
       }
      break;
   case M_SW_CTRL:
       if (record->tap.count && record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RGHT) SS_UP(X_LALT) SS_UP(X_LSFT));
       } else {
       }
       break;
   case W_SW_CTRL:
         if (record->tap.count && record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_TAP(X_RGHT) SS_UP(X_LCTL) SS_UP(X_LSFT));
         } else {
         }
         break;
   case M_SL_SHFT:
         if (record->tap.count && record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME)  SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) );
         } else {
         }
         break;
   case W_SL_SHFT:
         if (record->tap.count && record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME)  SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) );
         } else {
         }
         break;

   } 
   return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
   switch (get_highest_layer(state)) {
   case _WINDOWS:
   rgb_matrix_set_color_all(RGB_WHITE);
   break;
   case _MAC:
   rgb_matrix_set_color_all(RGB_BLUE);
   break;
   case _NUM:
   rgb_matrix_set_color_all(RGB_ORANGE);
   break;
   default: //  for any other layers, or the default layer
   rgb_matrix_set_color_all(RGB_RED);
   break;
   }
 return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WINDOWS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(_HUB),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     W_SW_CTRL, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     W_SL_SHFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,          KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_BSPC, KC_SPC, W_TAB_SYM,           MO(_NUM), LT(_SYMBOL,KC_ENT),  KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, XXXXXXX,                    XXXXXXX,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_1,    KC_2,    TD(TD_BRACKETS),TD(TD_BRACES),KC_GRV,                  WIN_PREV_WORD,    KC_LEFT, KC_DOWN, KC_RGHT,    WIN_NEXT_WORD,    KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, XXXXXXX,                    XXXXXXX,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
   
  [_MAC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(_HUB),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     M_SW_CTRL, HOME_A_M,HOME_S_M, HOME_D_M,HOME_F_M,KC_G,                              KC_H,    HOME_J_M,HOME_K_M,HOME_L_M,HOME_SC_M, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     M_SL_SHFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,          KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_BSPC, KC_SPC, M_TAB_SYM,           MO(_MAC_NUM), LT(_MAC_SYMBOL, KC_ENT),  KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MAC_NUM] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, XXXXXXX,                    XXXXXXX,  _______, _______
                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),
 
   [_MAC_SYMBOL] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN,  KC_F11,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_DEL,  KC_1,    KC_2,    TD(TD_BRACKETS),TD(TD_BRACES),KC_GRV,                 M_PREV_W,    KC_LEFT, KC_DOWN, KC_RGHT,    M_NEXT_W,    KC_PIPE,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, XXXXXXX,                    XXXXXXX,  _______, _______
                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [_GAME] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MO(_HUB),
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,          KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_BSPC, KC_SPC,  KC_ENT,           MO(_NUM), LT(_SYMBOL,KC_ENT),  KC_DEL
                                    // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
      ),

  [_HUB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_MUTE, KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_MPLY, KC_MPRV,   KC_MNXT,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     DF(_WINDOWS), DF(_MAC),    DF(_GAME),    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, RM_NEXT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,  XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, QK_BOOT, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, EE_CLR,  _______, _______, _______, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

