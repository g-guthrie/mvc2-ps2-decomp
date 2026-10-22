typedef short s16;

/* Two s16 (x, y) pairs, mirrored in x. Reader at asm 001E1C64 (nonmatching). */
typedef struct { s16 x; s16 y; } s16_pair;
s16_pair data_u32_0044F050[2] = { { 64, 0 }, { -64, 0 } };
