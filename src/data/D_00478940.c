typedef unsigned int u32;
extern u32 data_raw_00478540[0x80];
extern u32 data_raw_00478740[0x80];
/* func_003EB4A0 consumes this exact four-entry list in its fixed a3=0..3 loop at 0x003EB4B4-0x003EB5B8. Each pointer is read as two 32-bit packed values per pixel and the nested fixed loops cover 0x200 bytes per target. */
u32 * const D_00478940[4] = {
    data_raw_00478540,
    data_raw_00478740,
    data_raw_00478540,
    data_raw_00478740,
};
