typedef signed short s16;
typedef unsigned char u8;
typedef float f32;

/* Actor tables for the 0x0038xxxx-0x0039xxxx spawner family (each entry point
 * indexes by the actor's variant bytes p[0x20]/p[0x1B7]/p[0x22]/p[0x95]).
 * Every member is reached through its own address (%hi/%lo of D_004B8630,
 * D_004B8660, D_004B8680, D_004B86B0, D_004B86D0, D_004B8700, D_004B8728,
 * D_004B8730, D_004B8740, D_004B8750, D_004B8758); the code addresses nothing
 * by this unit's start alone. Members and widths:
 *
 * Data004B8630Rec10 (10 bytes). func_0038E2D0 (0x0038E2D0) and func_0039C4D0
 * (0x0039C4D0) take a pointer to one record (a2) and read: lh +0 (0x0038E2E8,
 * stored to p+0x5C, negated when facing flips), lh +2 (0x0038E340, stored to
 * p+0x60), lh +4 (0x0038E2E4, added to p+0x34), lh +6 (0x0038E320, added to
 * p+0x38), lbu +8 (0x0038E394, third argument of func_001757E0 with a1=0x15)
 * and lbu +9 (0x0038E364, stored to p+0x1B5). Callers index a record as
 * (p[0x20] * 2 + p[0x1B7]) * 10 (0x0038DC60-DC78, 0x0038DF18-DF2C,
 * 0x0039BD80-BD98, 0x0039C0A8-C0BC).
 * Pair arrays: func_0038F9E0 (src/fb37_g.c) reads D_004B8660 + (p[0x20] << 3)
 * as two f32 (+0 -> p+0x34, +4 -> p+0x38) and D_004B8680 + (p[0x20] << 4) as
 * four f32 (+0/+4/+8/+C -> p+0x5C/0x68/0x60/0x6C). func_003903F0
 * (0x003903F0) reads D_004B86B0 + ((p[0x20] & 6) << 2) as two f32 (+0 -> p+0x34,
 * +4 -> p+0x38) and D_004B86D0 + (p[0x20] << 3) as two f32 (+0 -> p+0x5C,
 * +4 -> p+0x60, lwc1 0x00390540-0x00390558).
 * g[8] (D_004B8728) and h[16] (D_004B8730) are lbu tables indexed by p[0x95]
 * (0x0039C878) and by a byte of the parent object (0x0039CC58-CC6C).
 * i[4] (D_004B8740) is lwc1-indexed by p[0x22] (src/actor_ancestor_position_init_0039cce0.c);
 * j[8] (D_004B8750) is lbu-indexed by p[0x22] (0x0039DCE8-DCF8). k[2] (D_004B8758)
 * is two {lh +0, lh +2} entries, +4 selected by the parent's p[0x20] (0x0039E81C-E8B0).
 * The 8-byte zero members pad_28 and pad_48 are unread alignment gaps (the next
 * table starts 16-byte aligned); the member sizes below follow the next
 * referenced address. Array bounds are fixed by those addresses where the index
 * range is not bounded in code (b: 3 live entries, the fourth pair slot is the
 * zero gap pad_48). */
typedef struct {
    s16 f5c;
    s16 f60;
    s16 dx34;
    s16 dy38;
    u8 anim;
    u8 b1b5;
} Data004B8630Rec10;
typedef struct {
    f32 f34;
    f32 f38;
} Data004B8630Pair34;
typedef struct {
    f32 f5c;
    f32 f68;
    f32 f60;
    f32 f6c;
} Data004B8630Quad;
typedef struct {
    f32 f5c;
    f32 f60;
} Data004B8630Pair5c;
typedef struct {
    s16 x;
    s16 y;
} Data004B8630Shift;
typedef struct {
    Data004B8630Rec10 variant_a[4];  /* 0x004B8630 */
    u8 pad_28[8];                     /* 0x004B8658 */
    Data004B8630Pair34 offs_b[3];    /* 0x004B8660 */
    u8 pad_48[8];                     /* 0x004B8678 */
    Data004B8630Quad vel_b[3];       /* 0x004B8680 */
    Data004B8630Pair34 offs_c[4];    /* 0x004B86B0 */
    Data004B8630Pair5c vel_c[6];     /* 0x004B86D0 */
    Data004B8630Rec10 variant_d[4];  /* 0x004B8700 */
    u8 index_g[8];                    /* 0x004B8728 */
    u8 index_h[16];                   /* 0x004B8730 */
    f32 spread_i[4];                  /* 0x004B8740 */
    u8 index_j[8];                    /* 0x004B8750 */
    Data004B8630Shift shift_k[2];    /* 0x004B8758 */
} Data004B8630;
typedef char data_rec_004B8630_size_check[(sizeof(Data004B8630) == 0x130) ? 1 : -1];

Data004B8630 data_rec_004B8630 = {
    {
        { -6, 0, -133, 113, 0x0B, 0x30 },
        { -8, 0, -133, 113, 0x0C, 0x31 },
        { -6, -4, -86, 102, 0x10, 0x40 },
        { -10, -6, -86, 102, 0x11, 0x40 }
    },
    { 0 },
    {
        { -0.0f, 68.57143f },
        { -85.0f, 79.28571f },
        { -26.666666f, 83.57143f }
    },
    { 0 },
    {
        { 0.0f, 0.0f, -4.285714f, -2.142857f },
        { -5.0f, 0.052083332f, 3.2142856f, -0.53571427f },
        { -26.666666f, -3.3333333f, 83.57143f, -2.142857f }
    },
    {
        { -50.0f, 143.57143f },
        { -83.33333f, 47.142857f },
        { -53.333332f, 154.2857f },
        { 0.0f, 0.0f }
    },
    {
        { -5.0f, 0.0f },
        { -8.333333f, 0.0f },
        { -5.0f, 0.0f },
        { -8.333333f, 0.0f },
        { -7.5f, -8.571428f },
        { -12.5f, -8.571428f }
    },
    {
        { -5, 0, -133, 113, 0x0B, 0x30 },
        { -7, 0, -133, 113, 0x0C, 0x31 },
        { -6, -4, -86, 102, 0x10, 0x40 },
        { -10, -6, -86, 102, 0x11, 0x40 }
    },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00 },
    { 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 213.33333f, 186.66666f, 133.33333f, 26.666666f },
    { 0x17, 0x18, 0x19, 0x18, 0x17, 0x18, 0x19, 0x18 },
    {
        { -8448, 14336 },
        { -9984, 16384 }
    }
};
