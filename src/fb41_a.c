typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3A;
typedef struct { V3A v[9]; } RA;
typedef struct { u32 w[3]; } WA;
extern RA D_0043FA10[];
extern WA D_0043FAF0[];
extern WA D_0043FAF4[];
extern WA D_0043FAF8[];
extern u8 D_004F20B0[];
extern u8 D_00583B92[];
extern u32 D_004C2830;

void func_00138350(u8 *p, s32 flag)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001391B0(u8 *);
    extern void func_00138980(u8 *);
    u8 *o;

    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        o[0x20] = p[0x20];
        o[0x21] = p[0x21];
        *(u32 *)(o + 0xD4) = p[0x21];
        *(u8 **)(o + 0x18) = p;
        *(u8 **)(o + 0x14) = D_004F20B0 + (o[0x20] + o[0x21] * 2) * 0x5B8;
        *(s16 *)(o + 0xCC) = o[0x20] * 3 + o[0x21] + 0x46;
        *(u32 *)(o + 0x84) = D_004C2830;
        *(V3A *)(o + 0x34) = D_0043FA10[o[0x20]].v[o[0x21]];
        if (flag != 0) {
            *(void (**)(u8 *))(o + 0x10) = func_001391B0;
        } else {
            if (*(s32 *)(p + 0xD8) != 0 || D_00583B92[o[0x20]] == 0x77) {
                s32 k = (s8)(-(s8)((s8)o[0x21] - 2));
                *(void (**)(u8 *))(o + 0x10) = func_001391B0;
                *(V3A *)(o + 0x34) = D_0043FA10[o[0x20]].v[k];
            }
            *(void (**)(u8 *))(o + 0x10) = func_00138980;
        }
        *(u32 *)(o + 0x40) = D_0043FAF0[o[0x20]].w[0];
        *(u32 *)(o + 0x44) = D_0043FAF4[o[0x20]].w[0];
        *(u32 *)(o + 0x48) = D_0043FAF8[o[0x20]].w[0];
        *(s32 *)(o + 0xD0) = 0x81F;
        *(u32 *)(o + 0x50) = 0x3DCCCCCD;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(s32 *)(o + 0xDC) = 0;
        o[0x23] = 0;
    }
}
