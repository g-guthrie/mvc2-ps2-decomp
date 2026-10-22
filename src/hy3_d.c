typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef float f32;

extern u8 D_004BFA88[8];

void func_001D6160(u8 *a, u8 *b)
{
    u8 *s0;
    u16 *s1;
    extern void func_00175700(u8 *);
    extern void func_001D6B20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s1 = (u16 *)(a + 0xD0);
    a[0x24] = *(s8 *)(b + 0x24) + *(s8 *)(a + 0x31);
    s0 = a + 0x5C;
    if (*(s8 *)(a + 0x24) > 7) a[0x24] = 7;
    if (*(s8 *)(a + 0x24) < 0) a[0x24] = 0;
    func_00175700(a);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(f32 *)(a + 0x3C) = *(f32 *)(b + 0x3C);
    if (b[0x215] == 0) {
        u32 t = a[4];
        a[4] = t + 1;
        func_001D6B20(a, b);
        return;
    }
    if (b[0x168] == 0x11) a[0x13C] = 0; else a[0x13C] = 1;
    if (a[5] == 0) {
        if (b[0x169] != 0x1A) {
            u32 t;
            s0[0] = 1;
            func_001757E0(a, 0x17, D_004BFA88[s0[0]]);
            t = a[5];
            a[5] = t + 1;
            return;
        }
    } else {
        if (b[0x169] == 0x1A) a[5] = 0;
        return;
    }
    {
        s32 c = *(s8 *)(b + 0x151);
        if (c != 0) {
            if ((s8)c != s0[0]) {
                s0[0] = c;
                func_001757E0(a, 0x17, D_004BFA88[s0[0]]);
            }
            if (*(u16 *)(b + 0x168) != *s1) {
                *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
            }
        }
    }
}
