typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001A59C0(u8 *, s32);
extern s32 func_00182D30(u8 *);
extern void func_00182C30(u8 *, s32);
extern void func_001843A0(u8 *);

void func_001A5880(u8 *a, s32 b, u8 *c) {
    func_00175700(a);
    switch (*(s8 *)(c + 0x1B3)) {
    case 0: break;
    default: {
        a[4] = 2;
        a[0x13C] = 0;
        *(s16 *)(a + 0x1C) = 0;
        c[0x13C] = 1;
        c[0x203] = 8;
        c[0x1FF] = 0xA;
        c[0x13C] = 1;
        func_001E3210(a, 0x23);
        func_001A59C0(a, b);
        return;
    }
    }
    c[0x13C] = 0;
    if (func_00182D30(c) != 0) {
        a[0x152] = 1;
        *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1C) - 7;
        func_00175700(a);
        func_00182C30(c, 0xA);
    }
    {
        s16 v = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = v;
        if (v < 0) {
            c[0x203] = 8;
            c[0x1FF] = 0xA;
            c[0x13C] = 1;
            func_001843A0(c);
            a[4] = 2;
            a[0x13C] = 0;
            *(s16 *)(a + 0x1C) = 0;
            func_001E3210(a, 0x23);
            func_001A59C0(a, b);
        }
    }
}
