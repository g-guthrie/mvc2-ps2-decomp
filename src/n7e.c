typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x00291800 */
s32 func_00291800(u8 *p) {
    u8 f = p[0x1E6];
    u8 *q = *(u8 **)(p + 0x220);
    if ((f == 0 && *(f32 *)(p + 0x34) < *(f32 *)(q + 0x34)) || (f != 0 && !(*(f32 *)(p + 0x34) <= *(f32 *)(q + 0x34)))) return 1;
    return 0;
}

/* 0x002ABAC0 */
extern u8 D_00458AA0[];
extern u8 jtbl_00458B20[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);
s32 func_002ABAC0(u8 *p) {
    u8 *t = (*(u32 *)(p + 0xD0) == 0) ? D_00458AA0 : jtbl_00458B20;
    if (func_00189310(p, t, p + 0x378) == 0) return 0; if (**(s8 **)(p + 0x420) == 0) return 0; func_0018A990(p, p + 0x378); p[5] = 0; p[7] = 0; p[6] = 0; p[0x1FD] = 6; func_00186A60(p, 0x1D); return 1;
}
