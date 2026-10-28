typedef signed short s16;
/* func_003C88C0 (src/w20b2_g.c): a = lh D_00476100[b20 * 2 + b21 * 6], c = lh D_00476102[...],
 * i.e. one {a, c} pair per [b21][b20]; b20 is the 3-way variant (D_00476140 has 3 records,
 * D_00476170 is [3][5]) and b21 the 5-way slot. Both are negated when facing left. */
typedef struct { s16 a; s16 c; } S16Pair476100;
S16Pair476100 data_s16_00476100[5][3] = {
    { { 64, -256 }, { -24, 256 }, { 88, 512 } },
    { { 80, -256 }, { 80, 256 }, { 16, 512 } },
    { { -16, -256 }, { 68, 256 }, { 26, 512 } },
    { { -64, -256 }, { -32, 256 }, { -96, 512 } },
    { { -16, -256 }, { 68, 256 }, { 26, 512 } },
};
