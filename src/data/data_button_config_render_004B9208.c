#include "button_config_render.h"

extern char gContinueDebugLabel_004B8F28[];
extern char gTrainingMenuDebugLabel_004B8F88[];
extern char gButtonConfigDebugLabel_004B8F38[];
extern char gCommandListDebugLabel_004B8F48[];
extern char gModeMenuDebugLabel_004B8F58[];
extern char gControllerUpDebugPrompt_004B8FA0[];
extern char gControllerDownDebugPrompt_004B8FC0[];
extern char gControllerRightDebugPrompt_004B8FE0[];
extern char gControllerLeftDebugPrompt_004B9000[];
extern char gVibrationDebugPrompt_004B9020[];
extern char gCommandSettingDebugPrompt_004B9040[];
extern char gDefaultSettingsDebugLabel_004B9060[];
extern char gExitDebugLabel_004B9078[];
extern char gLeftControlDebugPrompt_004B9080[];
extern char gRightControlDebugPrompt_004B90A0[];
extern char gLowPunchDebugLabel_004B90B8[];
extern char gHighPunchDebugLabel_004B90C0[];
extern char gLowKickDebugLabel_004B90C8[];
extern char gHighKickDebugLabel_004B90D0[];
extern char gPartnerADebugLabel_004B90D8[];
extern char gPartnerBDebugLabel_004B90E8[];
extern char gLightHeavyPunchDebugLabel_004B90F8[];
extern char gLightHeavyKickDebugLabel_004B9100[];
extern char gLightPunchKickDebugLabel_004B9108[];
extern char gHeavyPunchKickDebugLabel_004B9110[];
extern char gPartnerABDebugLabel_004B9118[];
extern char gTauntDebugLabel_004B9128[];
extern char gOffDebugLabel_004B9130[];
extern char gOnDebugLabel_004B9138[];
extern char gNormalDebugLabel_004B9140[];
extern char gLongDebugLabel_004B9148[];
extern char gL1DebugPrompt_004B9150[];
extern char gL2DebugPrompt_004B9170[];
extern char gR1DebugPrompt_004B9190[];
extern char gR2DebugPrompt_004B91B0[];

/*
 * Native users reference the tail at 0x004B9208, advance by 8-byte records,
 * and pass the resource field to the NUL-terminated formatter. The block ends
 * at the independently referenced switch table at 0x004B9330: 37 records, no
 * residue. Dynamic row selectors are unchecked; no global range is asserted.
 */
ButtonConfigRenderRecord data_button_config_render_004B9208[37] = {
    {{0x44, 0x32, 0x5C, 0x22}, gContinueDebugLabel_004B8F28},
    {{0x3C, 0x38, 0x63, 0x32}, gTrainingMenuDebugLabel_004B8F88},
    {{0x3C, 0x3E, 0x63, 0x23}, gButtonConfigDebugLabel_004B8F38},
    {{0x3E, 0x44, 0x62, 0x24}, gCommandListDebugLabel_004B8F48},
    {{0x42, 0x4A, 0x5D, 0x24}, gModeMenuDebugLabel_004B8F58},
    {{0x1E, 0x28, 0x4E, 0x28}, gControllerUpDebugPrompt_004B8FA0},
    {{0x1E, 0x2C, 0x4E, 0x29}, gControllerDownDebugPrompt_004B8FC0},
    {{0x1E, 0x30, 0x4E, 0x2A}, gControllerRightDebugPrompt_004B8FE0},
    {{0x1E, 0x34, 0x4E, 0x2B}, gControllerLeftDebugPrompt_004B9000},
    {{0x1E, 0x48, 0x4E, 0x2E}, gVibrationDebugPrompt_004B9020},
    {{0x1E, 0x4C, 0x4E, 0x2F}, gCommandSettingDebugPrompt_004B9040},
    {{0x1E, 0x50, 0x4E, 0x30}, gDefaultSettingsDebugLabel_004B9060},
    {{0x2D, 0x54, 0x39, 0x31}, gExitDebugLabel_004B9078},
    {{0x1E, 0x38, 0x4E, 0x2C}, gLeftControlDebugPrompt_004B9080},
    {{0x1E, 0x3C, 0x4E, 0x2D}, gRightControlDebugPrompt_004B90A0},
    {{0x30, 0x28, 0x45, 0x28}, gLowPunchDebugLabel_004B90B8},
    {{0x30, 0x28, 0x45, 0x28}, gHighPunchDebugLabel_004B90C0},
    {{0x32, 0x28, 0x44, 0x28}, gLowKickDebugLabel_004B90C8},
    {{0x32, 0x28, 0x44, 0x28}, gHighKickDebugLabel_004B90D0},
    {{0x2D, 0x28, 0x48, 0x28}, gPartnerADebugLabel_004B90D8},
    {{0x2D, 0x28, 0x48, 0x28}, gPartnerBDebugLabel_004B90E8},
    {{0x30, 0x28, 0x45, 0x28}, gLightHeavyPunchDebugLabel_004B90F8},
    {{0x30, 0x28, 0x45, 0x28}, gLightHeavyKickDebugLabel_004B9100},
    {{0x30, 0x28, 0x45, 0x28}, gLightPunchKickDebugLabel_004B9108},
    {{0x30, 0x28, 0x45, 0x28}, gHeavyPunchKickDebugLabel_004B9110},
    {{0x2A, 0x28, 0x4B, 0x28}, gPartnerABDebugLabel_004B9118},
    {{0x33, 0x28, 0x42, 0x28}, gTauntDebugLabel_004B9128},
    {{0x3F, 0x48, 0x48, 0x2E}, gOffDebugLabel_004B9130},
    {{0x41, 0x48, 0x47, 0x2E}, gOnDebugLabel_004B9138},
    {{0x39, 0x4C, 0x4B, 0x2F}, gNormalDebugLabel_004B9140},
    {{0x3C, 0x4C, 0x48, 0x2F}, gLongDebugLabel_004B9148},
    {{0x1E, 0x40, 0x4E, 0x2D}, gL1DebugPrompt_004B9150},
    {{0x1E, 0x44, 0x4E, 0x2D}, gL2DebugPrompt_004B9170},
    {{0x1E, 0x38, 0x4E, 0x2C}, gR1DebugPrompt_004B9190},
    {{0x1E, 0x3C, 0x4E, 0x2C}, gR2DebugPrompt_004B91B0},
    {{0x4B, 0x40, 0x55, 0x26}, gOnDebugLabel_004B9138},
    {{0x4B, 0x48, 0x54, 0x27}, gOffDebugLabel_004B9130},
};
