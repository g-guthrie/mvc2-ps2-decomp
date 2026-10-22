typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

extern u8 D_004BF350[8];
extern s32 D_004C2834;
extern V3 D_0043E2B0[];
extern V3 D_0043E2F8;
extern V4 D_0043E310;
extern u8 D_0043E290[];
extern u8 D_004F20B0[];
extern u8 D_004F24D5[];

void func_001333D0(s32 idx) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00133510();
    u8 *o;
    u8 *a;
    if ((o = func_003DA750(0, 0xE, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00133510;
        *(s16 *)(o + 0xCC) = *(s16 *)(D_0043E290 + idx * 4);
        a = D_004F20B0 + idx * 0x5B8;
        *(s32 *)(o + 0x84) = D_004C2834;
        *(V3 *)(o + 0x34) = D_0043E2B0[D_004BF350[a[0x425] + a[2] * 3]];
        *(s32 *)(o + 0xD0) = 0x810C31;
        *(V3 *)(o + 0x50) = D_0043E2F8;
        o[0x20] = idx;
        o[0x21] = D_004F24D5[idx * 0x5B8];
        *(V4 *)(o + 0x74) = D_0043E310;
        *(u8 **)(o + 0x18) = a;
    }
}
