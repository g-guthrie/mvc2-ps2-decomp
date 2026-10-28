typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B36;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G36;
extern G36 *D_004C2794;
typedef struct { u8 pad[0x34]; f32 f34; } S36;
extern u8 D_00463650[];
extern u8 D_00463651[];
extern u8 D_00463630[];


void residual_003636D0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_0015E630(u8 *);
    extern void func_00363900(u8 *);
    u32 t;
    u32 z;
    u8 *q;
    u8 *a;
    t = o[4];
    a = *(u8 **)(o + 0x18);
    o[4] = t + 1;
    *(u16 *)(o + 0x26) = 0x1003;
    *(B36 *)(o + 0xEC) = *(B36 *)(a + 0xEC);
    o[0x13C] = 1;
    o[2] = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    o[0x14C] = 0x10;
    o[0x14D] = 0x10;
    o[0x14E] = 0x18;
    o[0x14F] = 0x18;
    o[0x24] = 10;
    *(s16 *)(o + 0x1C) = 300;
    *(V3 *)(o + 0x34) = *(V3 *)(a + 0x34);
    q = o + 2;
    if (*(s16 *)(a + 0x140) == 0) {
        ((S36 *)o)->f34 += 613.3333129882812f;
        *(u32 *)(o + 0x5C) = 0xC1555555;
    } else {
        ((S36 *)o)->f34 -= 613.3333129882812f;
        *(u32 *)(o + 0x5C) = 0x41555555;
    }
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x430);
    *(s32 *)(o + 0x68) = 0;
    if (D_00463651[o[0x23] * 2] != 0) func_001E3210(o, 0x1A);
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = D_00463650[o[0x23] * 2];
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x17, D_00463630[o[0x20] * 2]);
    o[0] = 1;
    func_0015E630(o);
    func_00363900(o);
}
