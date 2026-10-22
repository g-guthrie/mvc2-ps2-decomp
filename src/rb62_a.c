typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/rb62_a.c "-O3 -Op -fp off -sdatathreshold 8" */
typedef struct DB {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x22];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
} DB;

extern f32 D_00583C48[];
extern f32 D_00583C4C[];
extern f32 D_00583C50[];

static void func_00338670(DB *p)
{
    p->h1c = p->h1c + 1;
    if (p->h1c > 150) {
        p->b4 = 0;
        p->h1c = 0;
        return;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f5c / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f60 / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f64 / 360.0) & 0xFFFF;
    p->w40 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C48[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C4C[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w48 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C50[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
}

static void (*keep_00338670)(DB *) = func_00338670;

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7E40[];
extern f32 D_004B7E80[];
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003349E0();

void func_003351B0(void) {
    u8 *o;
    s32 i;
    s32 off;
    double k;
    off = 0;
    i = 0;
    do {
        if ((o = func_003DA750(0, 0x5B, 1)) == 0) return;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003349E0;
        *(s16 *)(o + 0xCC) = 0x1B;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x800C39;
        o[0x23] = i;
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_004B7E40 + off);
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off + 4) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off + 8) / 360.0) & 0xFFFF;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x58) = 1.0f;
        *(f32 *)(o + 0x74) = 1.0f;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        i++;
        off += 12;
    } while (i < 5);
}
