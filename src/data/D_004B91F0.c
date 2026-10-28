#include "button_config_render.h"

extern char gQuitGamePrompt_004B8F68[];
extern char gYesOptionPrompt_004B8F78[];
extern char gNoOptionPrompt_004B8F80[];

/* Quit prompt rows: func_003D40A0 (0x003D40C4) walks three 8-byte rows (lbu +0/+1/+3, lw +4). */
ButtonConfigRenderRecord D_004B91F0[3] = {
    { { 0x41, 0x38, 0x5E, 0x25 }, gQuitGamePrompt_004B8F68 },
    { { 0x4B, 0x40, 0x55, 0x26 }, gYesOptionPrompt_004B8F78 },
    { { 0x4B, 0x48, 0x54, 0x27 }, gNoOptionPrompt_004B8F80 },
};
