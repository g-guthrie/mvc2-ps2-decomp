typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;
extern V3 D_004443A8;
extern V4 D_004443E0;
extern void func_00151100(void);

u8 *func_00150FD0(s32 kind, s32 b, s32 c, V3 *pos, s32 t) {
    extern u8 *func_003DA750();
    u8 *o;
    if (kind == 1 || kind == 2) {
        if ((o = func_003DA750(0, 0xD, 1)) == 0) return 0;
    } else {
        if ((o = func_003DA750(0, 0xD, 0)) == 0) return 0;
    }
    o[0x13C] = 1;
    *(void **)(o + 0x10) = (void *)func_00151100;
    o[0x23] = c;
    o[0x20] = kind;
    o[0x21] = b;
    *(s16 *)(o + 0xCC) = c;
    *(s32 *)(o + 0x84) = t;
    *(V3 *)(o + 0x34) = *pos;
    *(V3 *)(o + 0x50) = D_004443A8;
    *(V4 *)(o + 0x74) = D_004443E0;
    *(u32 *)(o + 0xD0) = 0x431;
    return o;
}
