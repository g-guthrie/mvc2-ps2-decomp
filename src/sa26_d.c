typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { V3 a[3]; } Row139;
typedef struct { u8 pad[0x85]; s8 b85; } G139;

extern G139 *D_004C2840;
extern s32 D_004C2830;
extern u8 D_00583BC3[];
extern Row139 D_0043FBE0[];

u8 *func_00139900(u8 *p, s32 flag) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0032DEF0(void);
    extern void func_00139A90(void);
    u8 *o;
    s32 t;
    if (flag != 0) {
        if (D_004C2840->b85 == 7) return 0;
    }
    if ((o = func_003DA750(0, 6, 1)) == 0) return 0;
    o[0x13C] = 1;
    *(u8 **)(o + 0x18) = p;
    o[0x20] = *(s8 *)(p + 0x538);
    o[0x21] = *(s8 *)(p + 0x1E);
    if (*(s8 *)(p + 0x538) != 0) {
        *(u32 *)(o + 0x44) = 0x8000;
        *(s16 *)(o + 0xCC) = 0xB2;
        *(s32 *)(o + 0x84) = D_004C2830;
    } else {
        *(u32 *)(o + 0x44) = 0;
        *(s16 *)(o + 0xCC) = 0xB1;
        *(s32 *)(o + 0x84) = D_004C2830;
    }
    t = D_00583BC3[0];
    if (t == 3) {
        *(V3 *)(o + 0x34) = D_0043FBE0[*(s8 *)(p + 0x538)].a[0];
    } else {
        *(V3 *)(o + 0x34) = D_0043FBE0[*(s8 *)(p + 0x538)].a[(u8)t];
    }
    *(s32 *)(o + 0xD0) = 0x801;
    *(s32 *)(o + 0xDC) = D_00583BC3[0];
    if (flag != 0) {
        *(void **)(o + 0x10) = (void *)func_0032DEF0;
    } else {
        *(void **)(o + 0x10) = (void *)func_00139A90;
    }
    return o;
}
