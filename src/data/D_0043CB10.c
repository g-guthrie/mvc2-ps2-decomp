typedef unsigned int u32;
extern u32 data_u32_0043BB60[];
extern u32 data_u32_0043C370[];
extern u32 data_u32_004BF300[];
extern signed int data_u32_0043C560[28];
/* func_001234D0 indexes this table directly using D_004F1F48. That selector is written as 0 at 0x00122DCC/0x003D2030, as 1 or 4 at 0x0032A0D4/0x0032A074, as 2 by func_00123760 (callers at 0x0032C074, 0x0032C664, 0x0032CEE4), and as 3 at 0x00126DD0. Thus all five entries are selectable. */
const void * const D_0043CB10[5] = {
    &data_u32_0043BB60[4],
    data_u32_0043C370,
    data_u32_004BF300,
    data_u32_0043C560,
    &data_u32_004BF300[2],
};
