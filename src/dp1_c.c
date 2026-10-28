/* func_0015F580: MW 3.0 -O3 -Op -fp off -sdatathreshold 8, warmed by src/z0_f.c (MWWARM_30) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x10];
    void (*f10)(u8 *);
    u8 *f14;
    u8 *f18;
    u8 pad1c[0x18];
    f32 f34, f38;
    u8 pad3c[0x14];
    f32 f50, f54;
    u8 pad58[4];
    f32 f5c, f60;
    u8 pad64[0x14];
    s32 f78, f7c, f80, f84;
    u8 pad88[0x44];
    s16 fCC;
    u8 padCE[2];
    s32 fD0, fD4, fD8, fDC;
    u8 padE0[0x5C];
    s16 f13C_pad;
} O73;

extern s32 D_004C2838;
extern u8 *func_003DA750(u8 *, s32, s32);
extern void (*jtbl_004454D8[])(u8 *);
extern void func_0015F4C0(u8 *p);
extern s32 func_00174170(void);

void func_0015F580(u8 *p)
{
    O73 *o;
    u8 *s1;
    if ((o = (O73 *)func_003DA750(0, 0x2A, 1)) != 0) {
        s1 = *(u8 **)(p + 0x18);
        ((u8 *)o)[0x13C] = 1;
        o->f10 = func_0015F4C0;
        o->fD0 = 0x800411;
        o->f78 = 0;
        o->f7c = 0;
        o->f80 = 0;
        o->fCC = 0x16;
        o->f84 = D_004C2838;
        o->fD4 = (s32)(1.6666666269302368f * (f32)(u32)s1[0x14E] * *(f32 *)(s1 + 0x50));
        o->fD8 = (s32)(2.142857074737549f * (f32)(u32)s1[0x14C] * *(f32 *)(s1 + 0x54));
        o->fDC = func_00174170();
        o->fDC %= o->fD4;
        o->fDC = (*(s16 *)(s1 + 0x140) != 0) ? -o->fDC : o->fDC;
        o->f5c = (f32)o->fDC;
        o->fDC = func_00174170();
        o->fDC %= o->fD8;
        o->f60 = (f32)o->fDC;
        o->f34 = *(f32 *)(s1 + 0x34) + o->f5c;
        o->f38 = *(f32 *)(s1 + 0x38) + o->f60;
        o->f18 = s1;
        o->f14 = p;
        *(s16 *)((u8 *)o + 0x140) = *(s16 *)(s1 + 0x140);
        o->f50 = 1.0f;
        o->f54 = 1.0f;
        *(s32 *)(p + 0xD4) += 1;
    }
}
