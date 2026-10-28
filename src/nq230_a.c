typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B230a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G230a;
extern G230a *D_004C2794;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } P230a;

void func_00377E90(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00378280(u8 *, u8 *);
    u32 t;
    u8 *r;
    u8 *s;
    P230a *sa;
    sa = (P230a *)o;
    t = o[4];
    o[4] = t + 1;
    r = q + 0x2B8;
    *(B230a *)(o + 0xEC) = *(B230a *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x14C] = 0x40;
    o[0x14D] = 0x40;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    o[0x1B0] = 0;
    o[0x1B1] = 0;
    o[0x24] = 0xB;
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    s = o + 2;
    if (q[0x20D] == 2) {
        if (o[0x1B7] == 0) {
            if (*(s16 *)(o + 0x140) != 0) sa->f34 += 95.0f;
            else sa->f34 -= 95.0f;
            sa->f38 += 199.28570556640625f;
            *(u32 *)(o + 0x5C) = 0xC1855555;
            *(u32 *)(o + 0x60) = 0;
            o[0x20] = 2;
        } else {
            if (*(s16 *)(o + 0x140) != 0) sa->f34 += 66.66666412353516f;
            else sa->f34 -= 66.66666412353516f;
            sa->f38 += 180.0f;
            *(u32 *)(o + 0x5C) = 0xC1700000;
            *(u32 *)(o + 0x60) = 0xC14DB6DB;
            *(s32 *)(o + 0x48) = 0x1000;
            o[0x20] = 3;
        }
    } else {
        if (o[0x1B7] == 0) {
            if (*(s16 *)(o + 0x140) != 0) sa->f34 += 51.666664123535156f;
            else sa->f34 -= 51.666664123535156f;
            sa->f38 += 102.85713958740234f;
            *(u32 *)(o + 0x5C) = 0xC1855555;
            *(u32 *)(o + 0x60) = 0xC1892492;
            *(u32 *)(o + 0x6C) = 0x401A4924;
            o[0x20] = 0;
        } else {
            if (*(s16 *)(o + 0x140) != 0) sa->f34 += 96.66666412353516f;
            else sa->f34 -= 96.66666412353516f;
            sa->f38 += 115.71427917480469f;
            *(u32 *)(o + 0x5C) = 0xC1700000;
            *(u32 *)(o + 0x60) = 0xC14DB6DB;
            *(u32 *)(o + 0x6C) = 0x40092492;
            *(s32 *)(o + 0x48) = 0xEE00;
            o[0x20] = 1;
        }
    }
    if (*(s16 *)(o + 0x140) != 0) {
        *(f32 *)(o + 0x5C) = -*(f32 *)(o + 0x5C);
    }
    r[4] = 1;
    *(s16 *)(o + 0x1C) = 0x10;
    func_001757E0(o, 0x17, 0);
    *(s16 *)(o + 0x1E) = 0;
    o[0x21] = 3;
    *(u32 *)(o + 0x118) = 0x3F800000;
    o[0x1B5] = 0x30;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *s; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(s16 *)(o + 0x1C0) = 0x1000;
    func_00378280(o, q);
}
