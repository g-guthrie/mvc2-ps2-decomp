typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y; } P2;
extern P2 D_00459470[];
extern P2 D_00459474[];
extern s16 D_00462D80[];
extern s16 D_00462D82[];
extern void func_001C3A80(u8 *, u8 *);
extern f32 D_004F1FE0;

void func_002BA910(u8 *p) {
    f32 v;
    u32 t = p[6];
    p[6] = t + 1;
    *(f32*)(p+0x38) += 34.28571320f;
    p[0x20D] = 2;
    if (p[0x1E6] != 0) {
        v = D_00459470[p[0x1B7]].x;
    } else {
        v = -D_00459470[p[0x1B7]].x;
    }
    *(f32*)(p+0x5C) = v;
    *(u32*)(p+0x68) = 0;
    *(u32*)(p+0x60) = 0;
    *(f32*)(p+0x6C) = D_00459474[p[0x1B7]].x;
}

void func_003578A0(u8 *p) {
 f32 a, b, c, d;
 a = 1.666666627f * (f32)D_00462D80[p[0x21] * 2]; if (*(s16*)(p+0x140) != 0) a = -a;
 b = *(f32*)(*(u8**)(p+0x18) + 0x34); *(f32*)(p+0x34) = b; *(f32*)(p+0x34) = b + a;
 c = 2.142857075f * (f32)D_00462D82[p[0x21] * 2]; *(f32*)(p+0x38) = *(f32*)(*(u8**)(p+0x18) + 0x38) + c;
}

s32 func_00174780(u8 *p) {
    u32 n = p[0x14D];
    f32 v = 2.142857075f * (f32)n * *(f32 *)(p + 0x54) - 34.28571320f;
    return !(*(f32 *)(p + 0x38) + v > D_004F1FE0);
}
