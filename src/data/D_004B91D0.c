#include "button_config_render.h"

extern char gContinueDebugLabel_004B8F28[];
extern char gButtonConfigDebugLabel_004B8F38[];
extern char gCommandListDebugLabel_004B8F48[];
extern char gModeMenuDebugLabel_004B8F58[];

/*
 * Four 8-byte renderer rows. func_003D3E90 (0x003D4058) walks all four
 * (lbu +0/+1/+3, lw +4 -> func_003D7350); func_003D4630 (0x003D4634) and
 * func_003D4980/4AD4/4F94/5000/5040 index rows by selector * 8 (byte 2 is
 * read there). func_003D6750 addresses row 2 directly as D_004B91E0
 * (= &D_004B91D0[2]; a native port must use that expression).
 */
ButtonConfigRenderRecord D_004B91D0[4] = {
    { { 0x44, 0x34, 0x5C, 0x22 }, gContinueDebugLabel_004B8F28 },
    { { 0x3C, 0x3C, 0x63, 0x23 }, gButtonConfigDebugLabel_004B8F38 },
    { { 0x3E, 0x44, 0x62, 0x24 }, gCommandListDebugLabel_004B8F48 },
    { { 0x42, 0x4C, 0x5D, 0x25 }, gModeMenuDebugLabel_004B8F58 },
};
