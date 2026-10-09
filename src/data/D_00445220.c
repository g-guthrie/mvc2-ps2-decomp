typedef signed short s16;
extern s16 data_s16_00445100[];
extern s16 data_s16_00445130[];
extern s16 data_s16_00445160[];
extern s16 data_s16_00445180[];
extern s16 data_s16_004451C0[];
extern s16 data_s16_004451E0[];
/* func_0015C740 creates selectors 0,1,3,2,5,4 at 0x0015C7D8/7F8/80C/830/844/858.
 * func_0015CED0 stores each selector to field20 at 0x0015CF3C; its allocator
 * zero-fills the 0x1E4-byte object at 0x003DA804, so field1C starts at 0.
 * func_0015CF60 checks signed field1C against the selected D_00445240 count
 * before reading (0x0015CF74-0x0015CFA0), increments field1C after the read
 * (0x0015CFF4-0x0015CFFC), and deletes the object when the bound fails. Thus
 * each selected curve is read exactly at indices 0..count-1. */
const s16 * const D_00445220[6] = {
    data_s16_00445100,
    data_s16_00445130,
    data_s16_00445160,
    data_s16_00445180,
    data_s16_004451C0,
    data_s16_004451E0,
};
