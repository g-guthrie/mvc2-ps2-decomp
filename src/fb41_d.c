typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C27FC;
extern u8 *D_004CAE80[];
extern u8 D_004CAE88[];
extern u8 D_004CAE98[];
extern u8 D_004CAEC8[];
extern u8 D_0014C0D0[];

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

static void func_0014C030(u8 *a0, u8 *a1) {
    if (a1) {
        F(a1, 92) = F(a1, 52) - F(a0, 52);
        F(a1, 96) = F(a1, 56) - F(a0, 56);
        F(a1, 100) = F(a1, 60) - F(a0, 60);
        I(a1, 24) = (s32)a0;
    }
}

void func_0014CF20(s32 a, s32 b, s32 c)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014C760(f32, u8 *, s32, s32, s32, s32);
    extern void func_0014CB10(u8 *, s32, s32);
    extern void func_0014CE20(u8 *, s32);
    extern void func_0014D670(s32);
    u8 *o;
    s32 i;

    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)D_0014C0D0;
        *(s16 *)(o + 0xCC) = 0xA3 - a;
        *(s32 *)(o + 0x84) = D_004C27FC;
        o[0x20] = a;
        *(s32 *)(o + 0xD0) = 1;
        *(u32 *)(o + 0x34) = 0xC0F00000;
        *(u32 *)(o + 0x38) = 0;
        *(u32 *)(o + 0x3C) = 0xC1500000;
        D_004CAE80[0] = o;
    } else {
        D_004CAE80[0] = 0;
    }
    if (a == 0) {
        if ((o = func_003DA750(0, 0xD, 1)) != 0) {
            o[0x13C] = 1;
            *(void **)(o + 0x10) = (void *)D_0014C0D0;
            *(s16 *)(o + 0xCC) = b + 0x25;
            *(s32 *)(o + 0x84) = D_004C27FC;
            o[0x20] = a;
            *(s32 *)(o + 0xD0) = 0x411;
            *(f32 *)(o + 0x54) = 0.8999999761581421f;
            *(f32 *)(o + 0x50) = 0.8999999761581421f;
            *(u32 *)(o + 0x34) = 0xC0F33333;
            *(u32 *)(o + 0x38) = 0x3F4CCCCD;
            *(u32 *)(o + 0x3C) = 0xC14CCCCD;
            *(u32 *)(o + 0x7C) = 0x3F800000;
            *(u32 *)(o + 0x78) = 0x3F800000;
            *(u32 *)(o + 0x80) = 0;
            D_004CAE80[1] = o;
        } else {
            D_004CAE80[1] = 0;
        }
        func_0014C760(-0.5f, D_004CAE88, 0, (s16)c, 0, 0);
        func_0014C030(D_004CAE80[0], D_004CAE80[1]);
        for (i = 0; i < 4; i++)
            func_0014C030(D_004CAE80[0], D_004CAE80[i + 2]);
    } else {
        func_0014C760(-0.800000011920929f, D_004CAE88, 0, (s16)c, 0, 0);
        func_0014CB10(D_004CAE98, 0, b);
        for (i = 0; i < 4; i++) {
            func_0014C030(D_004CAE80[0], D_004CAE80[i + 6]);
            func_0014C030(D_004CAE80[0], D_004CAE80[i + 2]);
        }
    }
    func_0014CE20(D_004CAEC8, 0);
    for (i = 0; i < 2; i++)
        func_0014C030(D_004CAE80[0], D_004CAE80[i + 18]);
    if (b == -1)
        func_0014D670(0);
}
