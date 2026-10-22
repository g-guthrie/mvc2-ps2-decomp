typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa19_f.c "-O3 -Op -sdatathreshold 8" */
extern u8 D_004D18A0[];

void func_00221000(u8 *a) {
    extern void func_00220F70(u8 *);
    extern void func_00184540(u8 *);
    extern s32 func_00417A40(void);
    extern void func_0019BA70(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_00186A20(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *q5c, *q60, *q68, *q6c;
    u8 *c;
    f32 lim;
    f32 x;
    lim = *(f32 *)(a + 0x430);
    x = 896.0f + lim;
    c = a + 0x2B8;
    if (*(f32 *)(a + 0x38) > x) {
        *(f32 *)(a + 0x38) = x;
    }
    if (*(s8 *)(a + 0x1B2) & 1) {
        u32 t = a[6];
        a[6] = t + 1;
        func_00220F70(a);
        return;
    }
    {
        u32 v = *(u16 *)(c + 0x24);
        *(u16 *)(c + 0x24) = v - 1;
    }
    if (!(*(u16 *)(c + 0x24) > 0)) {
        if (*(s8 *)(a + 0x1B2) & 0x80) {
            u32 t = a[6];
            a[6] = t + 1;
            func_00220F70(a);
            return;
        } else {
            s32 e;
            a[0x1EC] = 0;
            a[0x210] = 0;
            e = *(s8 *)(a + 0x1E8);
            a[0x1E8] = e + 1;
            a[0x1E9] = 1;
            a[0x1ED] = 0x7F;
            func_00184540(a);
        }
        return;
    }
    if ((func_00417A40() & 3) == 0) {
        func_0019BA70(a, 0xFF);
    }
    func_00175700(a);
    q5c = (u32 *)(a + 0x5C);
    q68 = (u32 *)(a + 0x68);
    q60 = (u32 *)(a + 0x60);
    q6c = (u32 *)(a + 0x6C);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00186A20(a);
    if (*(f32 *)(a + 0x38) < *(f32 *)(a + 0x430)) {
        a[6] = 7;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        func_001757E0(a, 0x15, 0xE);
        *q5c = 0;
        *q60 = 0;
        *q68 = 0;
        *q6c = 0;
    }

}
