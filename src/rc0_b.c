typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

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
extern V3 D_0045FA28;
extern V3 D_0045FA40[];
extern V3 D_0045FA70[];
extern V3 D_0045FAA0[];
extern s32 D_004C283C;

void func_00340B20(s32 n)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00340290();
    u8 *o;
    V3 *s1, *s2;
    f64 k;

    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00340290;
        *(s16 *)(o + 0xCC) = n + 0xC;
        *(s32 *)(o + 0x84) = D_004C283C;
        if (n >= 4) {
            *(V3 *)(o + 0x34) = D_0045FA28;
            *(s32 *)(o + 0x44) = 0xE001;
            *(f32 *)(o + 0x5C) = (D_0045FAA0[n].x - D_0045FA28.x) / 50.0f;
            *(s32 *)(o + 0x60) = 0;
            *(f32 *)(o + 0x64) = (D_0045FAA0[n].z - D_0045FA28.z) / 50.0f;
            *(f32 *)(o + 0x6C) = 2.0f * (D_0045FAA0[n].y - D_0045FA28.y) / 2500.0f;
        } else {
            s1 = &D_0045FA40[n];
            s2 = &D_0045FA70[n];
            *(V3 *)(o + 0x34) = *s1;
            k = 65536.0;
            *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= s2->x) / 360.0) & 0xFFFF;
            *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)s2->y / 360.0) & 0xFFFF;
            *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)s2->z / 360.0) & 0xFFFF;
            *(f32 *)(o + 0x5C) = (D_0045FAA0[n].x - s1->x) / 50.0f;
            *(s32 *)(o + 0x60) = 0;
            *(f32 *)(o + 0x64) = (D_0045FAA0[n].z - s1->z) / 50.0f;
            *(f32 *)(o + 0x6C) = 2.0f * (D_0045FAA0[n].y - s1->y) / 2500.0f;
        }
        *(s32 *)(o + 0xD0) = 0x80F;
        o[0x20] = n;
        *(s16 *)(o + 0x1E) = n * 6;
    }
}
