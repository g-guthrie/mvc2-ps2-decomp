typedef unsigned int u32;
extern u32 data_u32_0043BC10[];
extern u32 data_u32_0043C370[];
extern u32 data_u32_0043C510[];
extern u32 data_u32_0043C5D0[];
extern u32 data_u32_0043CAE0[];
/* func_00123250 and func_001234D0 index directly using D_004F1F48. That selector is written as 0 at 0x00122DCC/0x003D2030, as 1 or 4 at 0x0032A0D4/0x0032A074, as 2 by func_00123760 (callers at 0x0032C074, 0x0032C664, 0x0032CEE4), and as 3 at 0x00126DD0. Thus all five entries are selectable. */
const void * const D_0043CB30[5] = {
    data_u32_0043BC10,
    &data_u32_0043C370[8],
    data_u32_0043C510,
    data_u32_0043C5D0,
    &data_u32_0043CAE0[4],
};
