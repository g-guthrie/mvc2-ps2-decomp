typedef unsigned char u8;
typedef unsigned int u32;

#include "button_config_render.h"

extern u8 data_raw_004B3460[];
extern u8 data_raw_004B3440[];
extern u8 data_raw_004B3470[];
extern u8 data_raw_004B3480[];
extern u8 data_raw_004B3490[];
extern u8 data_raw_004B3498[];
extern u8 data_raw_004B34A0[];
extern u8 data_raw_004B3590[];
extern u32 data_u32_004B35B0[];
extern u8 data_raw_004B35C8[];
extern u8 data_raw_004B35D0[];
extern u8 data_raw_004B35D8[];
extern u8 data_raw_004B35E0[];
extern u8 data_raw_004B35E8[];
extern u8 data_raw_004B35F8[];
extern u8 data_raw_004B3608[];
extern u8 data_raw_004B3610[];
extern u8 data_raw_004B3618[];
extern u8 data_raw_004B3620[];
extern u8 data_raw_004B3628[];
extern u8 data_raw_004B3638[];
extern u8 data_raw_004B3640[];
extern u8 data_raw_004B3648[];
extern u8 data_raw_004B3650[];
extern u8 data_raw_004B3658[];
extern char gButtonConfigLabel_004B3450[];
extern char gControllerUpLabel_004B34B0[];
extern char gControllerDownLabel_004B34D0[];
extern char gControllerRightLabel_004B34F0[];
extern char gControllerLeftLabel_004B3510[];
extern char gVibrationSettingPrompt_004B3530[];
extern char gCommandSettingPrompt_004B3550[];
extern char gDefaultSettingsLabel_004B3570[];
extern char gExitLabel_004B3588[];
extern char gL1ButtonSettingPrompt_004B3660[];
extern char gL2ButtonSettingPrompt_004B3680[];
extern char gR1ButtonSettingPrompt_004B36A0[];
extern char gR2ButtonSettingPrompt_004B36C0[];

/*
 * The matched consumer references this base, steps by one 8-byte record, and
 * passes rendererArgs[0], [1], [3], and resource to the renderer. Its idx/n
 * parameters remain unchecked; this physical record count is not a runtime
 * index-range claim. The next independently referenced object starts at
 * 0x004B3830, so the 0x150-byte span is exactly 42 records with no residue.
 */
ButtonConfigRenderRecord data_button_config_render_004B36E0[42] = {
    {{0x44, 0x34, 0x5C, 0x22}, data_raw_004B3440},
    {{0x3C, 0x3C, 0x63, 0x23}, gButtonConfigLabel_004B3450},
    {{0x3E, 0x44, 0x62, 0x24}, data_raw_004B3460},
    {{0x42, 0x4C, 0x5D, 0x25}, data_raw_004B3470},
    {{0x41, 0x38, 0x5E, 0x25}, data_raw_004B3480},
    {{0x4B, 0x40, 0x55, 0x26}, data_raw_004B3490},
    {{0x4C, 0x48, 0x54, 0x27}, data_raw_004B3498},
    {{0x44, 0x32, 0x5C, 0x22}, data_raw_004B3440},
    {{0x3C, 0x38, 0x63, 0x32}, data_raw_004B34A0},
    {{0x3C, 0x3E, 0x63, 0x23}, gButtonConfigLabel_004B3450},
    {{0x3E, 0x44, 0x62, 0x24}, data_raw_004B3460},
    {{0x42, 0x4A, 0x5D, 0x24}, data_raw_004B3470},
    {{0x1E, 0x28, 0x4E, 0x28}, gControllerUpLabel_004B34B0},
    {{0x1E, 0x2C, 0x4E, 0x29}, gControllerDownLabel_004B34D0},
    {{0x1E, 0x30, 0x4E, 0x2A}, gControllerRightLabel_004B34F0},
    {{0x1E, 0x34, 0x4E, 0x2B}, gControllerLeftLabel_004B3510},
    {{0x1E, 0x48, 0x4E, 0x2E}, gVibrationSettingPrompt_004B3530},
    {{0x1E, 0x4C, 0x4E, 0x2F}, gCommandSettingPrompt_004B3550},
    {{0x1E, 0x50, 0x4E, 0x30}, gDefaultSettingsLabel_004B3570},
    {{0x2D, 0x54, 0x39, 0x31}, gExitLabel_004B3588},
    {{0x1E, 0x38, 0x4E, 0x2C}, data_raw_004B3590},
    {{0x1E, 0x3C, 0x4E, 0x2D}, data_u32_004B35B0},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B35C8},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B35D0},
    {{0x32, 0x28, 0x44, 0x28}, data_raw_004B35D8},
    {{0x32, 0x28, 0x44, 0x28}, data_raw_004B35E0},
    {{0x2D, 0x28, 0x48, 0x28}, data_raw_004B35E8},
    {{0x2D, 0x28, 0x48, 0x28}, data_raw_004B35F8},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B3608},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B3610},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B3618},
    {{0x30, 0x28, 0x45, 0x28}, data_raw_004B3620},
    {{0x2A, 0x28, 0x4B, 0x28}, data_raw_004B3628},
    {{0x33, 0x28, 0x42, 0x28}, data_raw_004B3638},
    {{0x3F, 0x48, 0x48, 0x2E}, data_raw_004B3640},
    {{0x41, 0x48, 0x47, 0x2E}, data_raw_004B3648},
    {{0x39, 0x4C, 0x4B, 0x2F}, data_raw_004B3650},
    {{0x3C, 0x4C, 0x48, 0x2F}, data_raw_004B3658},
    {{0x1E, 0x40, 0x4E, 0x2D}, gL1ButtonSettingPrompt_004B3660},
    {{0x1E, 0x44, 0x4E, 0x2D}, gL2ButtonSettingPrompt_004B3680},
    {{0x1E, 0x38, 0x4E, 0x2C}, gR1ButtonSettingPrompt_004B36A0},
    {{0x1E, 0x3C, 0x4E, 0x2C}, gR2ButtonSettingPrompt_004B36C0},
};
