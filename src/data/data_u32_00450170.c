typedef signed short s16;
/* Six 8-byte records, four s16 fields each. func_00200990 reads field 0 at stride 8 (lh D_00450170 + idx*8), field 1 at +2, field 2 at +4, field 3 at +6. */
typedef struct { s16 f[4]; } D00450170_Rec;
typedef char D00450170_Rec_size_check[(sizeof(D00450170_Rec) == 8) ? 1 : -1];
D00450170_Rec data_u32_00450170[6] = {
    { -12288, 16384, -28672, 8192 },
    { -12288, 8192, -28672, 16384 },
    { -8192, 16384, -28672, 8192 },
    { 0, 8192, -16384, 16384 },
    { -4096, 8192, 16384, 16384 },
    { 0, 16384, 28672, 8192 },
};
