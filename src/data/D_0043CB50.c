typedef unsigned char u8;
extern u8 data_zero_0043BFC0[];
extern float data_f32_0043C450[48];
extern float data_f32_0043C530[12];
extern float data_f32_0043C860[162];
/* func_00123250 and func_001234D0 index directly using D_004F1F48. That selector is written as 0 at 0x00122DCC/0x003D2030, as 1 or 4 at 0x0032A0D4/0x0032A074, as 2 by func_00123760 (callers at 0x0032C074, 0x0032C664, 0x0032CEE4), and as 3 at 0x00126DD0. Thus all five entries are selectable. */
const void * const D_0043CB50[5] = {
    data_zero_0043BFC0,
    data_f32_0043C450,
    data_f32_0043C530,
    data_f32_0043C860,
    data_f32_0043C450,
};
