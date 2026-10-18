typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x104]; s16 h140; } PF;
extern void func_001757E0();
extern s8 func_00175700();
extern void func_003DAA40();

void func_001D0BC0(u8 *p, u8 *q) {
    u32 t;
    s32 n;
    s32 *d;
    s32 *s;
    if (p[4] == 0) {
        t = p[4]; p[4] = t + 1;
        s = (s32 *)(q + 0xEC);
        d = (s32 *)(p + 0xEC);
        n = 0x31;
        do {
            *d++ = *s++;
        } while (--n > 0);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -1;
        p[0x13C] = 1;
        func_001757E0(p, 0x17, 8);
    }
    if (((PF *)p)->h140 == 0) {
        ((PF *)p)->f34 = -23.333332061767578f + ((PF *)q)->f34;
    } else {
        ((PF *)p)->f34 = ((PF *)q)->f34 - -23.333332061767578f;
    }
    ((PF *)p)->f38 = 282.8571472167969f + ((PF *)q)->f38;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (func_00175700(p) < 0) func_003DAA40(p);
}
