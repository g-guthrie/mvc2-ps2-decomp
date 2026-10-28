typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;


extern f32 D_004B7C04[];

static void func_00331730(u8 *p)
{
    extern f32 func_00417440(s32);
    f32 base;
    u32 ang;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s32 *)(p + 0xD8) != 0)
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 0x168)
        *(s16 *)(p + 0x1E) = 0;
    base = D_004B7C04[0];
    ang = (u32)(s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1E) / 360.0);
    *(f32 *)(p + 0x38) = base + 10.0f * func_00417440((u16)ang);
    if (*(s16 *)(p + 0x1C) > *(s32 *)(p + 0xD4)) {
        *(s16 *)(p + 0x1C) = 0;
        p[5] = 1;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern V3 D_004B81E8, D_004B7BE0, D_004B7C00, D_004B7FB8;
extern f32 D_004B8200[], D_004B8204[], D_004B7BF0[], D_004B7BF4[], D_004B7BF8[], D_004B7C10[], D_004B7C14[], D_004B7C18[], D_004B7FD0[], D_004B7FD4[];
extern void func_00339B40(), func_003319C0(), func_003314D0(), func_003370D0();

void func_00331820(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003314D0;
        *(s16 *)(o + 0xCC) = 26;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(V3 *)(o + 0x34) = D_004B7C00;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B7C10[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B7C14[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B7C18[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
    }
}

void func_00331D10(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003319C0;
        *(s16 *)(o + 0xCC) = 25;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(V3 *)(o + 0x34) = D_004B7BE0;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B7BF0[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B7BF4[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B7BF8[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
    }
}

void func_003374C0(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003370D0;
        *(s16 *)(o + 0xCC) = 40;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x803;
        *(V3 *)(o + 0x34) = D_004B7FB8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B7FD0[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B7FD4[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
        o[5] = a[5];
        o[0x23] = a[0x23];
    }
}

void func_00339EB0(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00339B40;
        *(s16 *)(o + 0xCC) = 12;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B81E8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B8200[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B8204[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
    }
}

