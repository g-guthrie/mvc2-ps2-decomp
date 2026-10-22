typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
/* func_0037EAA0 selects a record by the byte at self+0x20 (index << 3), reads
 * s16 at +0 as a scale factor and s8 at +4. Bytes +2, +5, +6, +7 are not read by
 * that reader and are kept as unk fields. */
typedef struct {
    s16 scale;
    s16 unk_02;
    s8 field_04;
    u8 unk_05;
    u8 unk_06;
    s8 unk_07;
} DataU32_00464270Record;
typedef char DataU32_00464270Record_size8[(sizeof(DataU32_00464270Record) == 8) ? 1 : -1];
DataU32_00464270Record data_u32_00464270[4] = {
    { 40, 176, 7, 0, 0, 48 },
    { 40, 176, 7, 0, 0, 48 },
    { -136, 0, 10, 0, 7, 60 },
    { -136, 0, 10, 0, 7, 60 },
};
