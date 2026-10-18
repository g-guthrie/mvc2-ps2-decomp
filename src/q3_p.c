typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { V3 a, b; } W;
extern W D_0043E330[];
extern V3 D_0043E360[];
extern u8 D_004F20B0[];
extern u8 D_004F20B1[];
extern void func_00133860();

void func_00133760(s32 idx) {
    extern u8 *func_003DA750();
    u8 *o;
    s32 i;
    u32 *r;
    if ((o = func_003DA750(0, 0xF, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00133860;
        *(u32 *)(o + 0x84) = 0;
        *(u32 *)(o + 0xD0) = 0;
        o[2] = idx;
        *(V3 *)(o + 0x34) = D_0043E330[idx].a;
        *(V3 *)(o + 0x50) = D_0043E360[0];
        *(u8 **)(o + 0x18) = D_004F20B0 + idx * 0x5B8;
        o[1] = D_004F20B1[idx * 0x5B8];
        r = (u32 *)(o + 0x1B0);
        i = 0;
        do {
            i++;
            *r++ = 0;
        } while (i < 4);
    }
}
