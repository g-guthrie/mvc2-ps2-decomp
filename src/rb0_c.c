typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b0; s8 b1; u8 pad2[0xA]; s32 wC; u8 pad10[0x5C]; s8 b6C; u8 pad6D[5]; s8 b72; u8 pad73[0x29]; s32 w9C; s32 wA0; } O;
extern volatile s32 D_004C22C4;
extern s32 D_004C23C4;
extern s32 D_004C23FC;
extern s8 D_004BC560[];

void func_004026B0(O *o, s32 n) {
    extern void func_003FB128(void *);
    extern void func_003F9630(void);
    extern void func_003F9660(void);
    extern void func_003FF160(void *, s32);
    extern void func_00401B78(void *, s32 *, s32 *);
    s32 w, h;
    s32 t, sv;
    if (o == 0) {
        func_003FB128(D_004BC560);
        return;
    }
    t = o->b1;
    if (n != o->b72) {
        func_003F9630();
        o->b72 = n;
        if ((u32)(t - 3) < 2) {
            if (n == 1) {
                func_003FF160((void *)o->wC, 0);
            } else {
                func_003FF160((void *)o->wC, 1);
                o->wA0 = D_004C22C4;
            }
            sv = D_004C23C4;
            D_004C23C4 = 0;
            func_00401B78(o, &w, &h);
            D_004C23C4 = sv;
            o->w9C = (s32)((f32)w / (f32)h * (f32)D_004C23FC);
        }
        func_003F9660();
    }
}
