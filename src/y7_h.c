typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }
extern u8 D_004F1F45, D_004F1F46;

void func_00380770(u8 *a, u8 *b) {
    extern void func_001757E0();
    extern void func_00185870();
    extern void func_00182C30();
    u8 *s0 = *(u8 **)(a + 0x1C4);
    if (*(s8 *)(s0 + 0x1B4) == 0) {
        u32 t = a[5];
        a[5] = t + 1;
        *(f32 *)(a + 0x50) = *(f32 *)(a + 0x64);
        *(f32 *)(a + 0x54) = *(f32 *)(a + 0x70);
        func_001757E0(s0, 0xE, 0);
        func_00185870(a, s0);
        *(s32 *)(a + 0xD4) = *(s32 *)(b + 0x1DC);
        *(s16 *)(a + 0x1C) = 0xB4;
        func_00182C30(*(s32 *)(b + 0x1DC), 1);
        s0[0x20A] = 6;
        b[0x20B] = 0xC0;
        s0[0x20B] = 0xC0;
        b[0x1FE] = 1;
        *(s8 *)(b + 0x16A) = -1;
        if (s0[0x20D] == 2) {
            *(s32 *)(s0 + 0x6C) = 0;
            *(s32 *)(s0 + 0x60) = 0;
            *(s32 *)(s0 + 0x68) = 0;
            *(s32 *)(s0 + 0x5C) = 0;
        }
    }
}

void func_002FAAC0(u8 *a, u8 *b) {
    extern void func_00175700();
    extern void func_001D8AB0();
    extern void func_001830D0();
    u32 v[3];
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t;
        *(s8 *)(a + 0x151) = 0;
        t = a[6];
        a[6] = t + 1;
        func_001D8AB0(a, 2, 0);
        v[0] = 0x413AAAAA;
        v[1] = 0x43092492;
        a[0x404] = 0;
        a[0x405] = 0;
        func_001830D0(a, v, 1);
        b[0xD] = 0;
        *(s16 *)(b + 0xE) = 0;
        b[0x14] = 0;
        b[0x15] = 0;
        a[0x214] = 0;
        *(s16 *)(a + 0x3FE) = 0;
        *(s16 *)(a + 0x3FA) = 0;
        a[0x402] = 0;
    }
}

void func_002ED4C0(u8 *a) {
    extern void func_00175700();
    extern void func_001843A0();
    extern void func_003A6DC0();
    s16 v;
    func_00175700();
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        func_001843A0(a);
        return;
    }
    if (*(s8 *)(a + 0x151) & 1) {
        *(s8 *)(a + 0x151) = *(s8 *)(a + 0x151) & ~1;
        func_003A6DC0(a, 1, 9);
    }
    if (*(s8 *)(a + 0x151) & 2) {
        u8 *q;
        *(s8 *)(a + 0x151) = *(s8 *)(a + 0x151) & ~2;
        q = *(u8 **)(a + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x20;
        a[0x1B5] = 0x20;
        q[0x1E6] = a[0x1E6];
        q[0x1E6] ^= 1;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
    }
}
