typedef signed short s16;
extern s16 data_s16_0044B870[];

/* Spans the 2-byte tail of the s16 record at 0x0044B870, alignment padding, the
   three-entry pointer array D_0044B898 (each entry is the s16 base at 0x0044B870;
   func_001ACB50 loads the pointer with lw, indexes it by field 0x1C * 4 and reads lh),
   and 4 bytes of padding before the bounds table at 0x0044B8A8. */
#pragma pack(2)
typedef struct {
    s16 pad_a[3];
    s16 *base[3];
    s16 pad_b[2];
} CallbackBaseBlock;
#pragma pack()
typedef char CallbackBaseBlock_size_check[(sizeof(CallbackBaseBlock) == 22) ? 1 : -1];

CallbackBaseBlock data_raw_0044B892 = {
    { 0, 0, 0 },
    { data_s16_0044B870, data_s16_0044B870, data_s16_0044B870 },
    { 0, 0 },
};
