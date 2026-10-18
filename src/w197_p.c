typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_00444280[];
extern f32 D_00444250[];
extern s32 D_004C27FC;
extern u8 *D_004CAE80[];
extern u8 *D_004CAFF8[];
extern s32 D_004CAFFC[];
extern void D_0014C0D0(void);
extern void func_0014C4C0(void);

s32 func_0014D410(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    s32 i;
    f32 *v;
    s32 off;
    s32 *t;
    u8 *o;
    i = 0;
    off = 0;
    do {
        t = (s32 *)((u8 *)D_00444280 + off);
        v = &D_00444250[*t * 3];
        if ((o = func_003DA750(0, 0xD, 1)) == 0) {
            return 0;
        }
        o[0x13C] = 0;
        *(s16 *)(o + 0xCC) = *(s16 *)t + 0x72;
        *(s32 *)(o + 0x84) = D_004C27FC;
        *(void **)(o + 0x10) = (void *)D_0014C0D0;
        *(s32 *)(o + 0xD0) = 1;
        *(f32 *)(o + 0x34) = v[0];
        *(f32 *)(o + 0x38) = v[1];
        *(f32 *)(o + 0x3C) = v[2];
        if (*t == 3) {
            *(s32 *)(o + 0xD0) |= 0x10;
            *(s32 *)(o + 0x50) = 0;
            *(s32 *)(o + 0x54) = 0x3F800000;
            *(void **)(o + 0x10) = (void *)func_0014C4C0;
        }
        D_004CAE80[*t + 0x5C] = o;
        off += 4;
        i++;
    } while (i < 4);
    *(s32 *)(D_004CAFF8[0] + 0xD0) |= 0x20;
    *(s32 *)(D_004CAFF8[0] + 0x74) = 0x3F800000;
    return D_004CAFFC[0];
}
