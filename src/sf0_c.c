typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/sf0_c.c "-O3 -Op -fp off -sdatathreshold 8"
   func_00145560 is a static copy of the real function immediately before
   func_00145780 in retail address order (soft-float; it also stores
   func_00145780 as its callback). It verifies exact at its own address under
   these flags. */

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
void func_00145780(u8 *p);
extern u32 D_004C2808;
extern V3 D_004B33C0;
extern f32 data_f32_004B33D8[3];

static void func_00145560(u8 *owner)
{
    s32 i;
    u8 *p;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    for (i = 0; i < 2; i++) {
        if ((p = func_003DA750(0, 0xD, 1)) == 0)
            return;
        *(u8 **)(p + 0x18) = owner;
        p[0x23] = (u8)i;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00145780;
        *(s16 *)(p + 0xCC) = 8;
        *(u32 *)(p + 0x84) = D_004C2808;
        *(V3 *)(p + 0x34) = D_004B33C0;
        *(u32 *)(p + 0x40) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[0] / 360.0) & mask);
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[1] / 360.0) & mask);
        *(u32 *)(p + 0x48) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[2] / 360.0) & mask);
        *(u32 *)(p + 0xD0) = 0x80082F;
        *(s16 *)(p + 0x1C) = 0;
        *(f32 *)(p + 0x74) = (f32)(1.0 - 0.2 * (double)(p[0x23] + 1));
        *(V3 *)(p + 0x50) = *(V3 *)(p + 0x34);
    }
}
static void (*keep_00145560)(u8 *) = func_00145560;


extern V3 D_004B80B8;
extern V3 D_004B3200[];
extern f32 D_004B3350[];
extern f32 D_004B3354[];
extern f32 D_004B3358[];
extern s8 D_004B3368[];
extern void func_00144BF0();
extern void func_00170DF0(u32);
extern f32 D_004B80A0[];
extern f32 D_004B80A4[];
extern s32 D_004C283C;
extern void func_00338570();
extern void func_00338C70();
extern V3 D_004B80E8;
extern f32 D_004B8100[];
extern f32 D_004B8104[];


extern u8 *D_004C2840;

void func_00145780(u8 *p)
{
    extern void func_003DAA40(u8 *);
    u8 *q;
    if (*(s8 *)(D_004C2840 + 2) != 3) {
        func_003DAA40(p);
        return;
    }
    q = *(u8 **)(p + 0x18);
    if (q[6] == 0) {
        if (*(s16 *)(q + 0x1C) == 0 && *(s16 *)(q + 0x1E) <= 10) {
            p[0x13C] = 1;
            if (*(s16 *)(p + 0x1C) == 0) {
                *(V3 *)(p + 0x34) = *(V3 *)(p + 0x50);
                *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)(p + 0x5C) / 360.0) & 0xFFFF;
                *(s16 *)(p + 0x1C) = p[0x23] + 1;
                *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
                *(f32 *)(p + 0x5C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x5C);
            } else {
                *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
            }
        } else {
            p[0x13C] = 0;
            *(s16 *)(p + 0x1C) = 0;
            *(f32 *)(p + 0x5C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x5C);
        }
    } else {
        p[0x13C] = 0;
    }
}
