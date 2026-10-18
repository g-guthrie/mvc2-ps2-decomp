typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x2E]; s8 f2e; } G6;
extern G6 *D_004C2840;
extern s8 D_004D1926[];
extern u8 D_00446210[];
extern u8 D_00446230[];
s32 func_0016A250(u8 *p) {
    s32 a2, n, t0, v;
    if (p[0x496] != 0) return 0;
    if (D_004C2840->f2e != 0) return 0;
    a2 = D_00446210[*(s16 *)(p + 0x434) >> 3];
    n = D_004D1926[0];
    t0 = 0;
    if (n % 10 > 4) t0 = 8;
    v = D_00446230[(((n / 10) << 4) | t0) >> 3];
    if (a2 < v) a2 = v;
    if (p[0x470] != a2) {
        p[0x470] = a2;
        return 1;
    }
    return 0;
}
