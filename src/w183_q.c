typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G7C;
extern G7C *D_004C2794;

void func_00352300(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u8 *a;
    f32 x, y;
    u8 r;
    u32 t;
    p[0x13C] = 1;
    a = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x34) = *(V3 *)(a + 0x34);
    x = -13.333333015441895f;
    y = 26.66666603088379f;
    if (*(s16 *)(p + 0x140) != 0) {
        x = -x;
        y = -y;
    }
    *(f32 *)(p + 0x5C) = x;
    *(f32 *)(p + 0x34) += y;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x60) = 0;
    if (p[0x20] == 1) {
        *(f32 *)(p + 0x38) += 137.14285278320312f;
    } else {
        *(f32 *)(p + 0x38) += 188.57142639160156f;
    }
    p[0x24] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s16 *)(p + 0x1C) = 0x3C;
    p[0x14E] = 0x30;
    p[0x14F] = 0x30;
    p[0x14D] = 0x10;
    p[0x14C] = 0x10;
    t = p[0x20];
    if (t == 0) r = 2;
    else { u8 c = t;
    if (c == 1) r = 2;
    else if (c == 3) r = 0x3E;
    else r = 0x43; }
    p[0x1B5] = r;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0x14, 0);
}
