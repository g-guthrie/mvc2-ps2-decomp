typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 *D_004C2A08;
extern u8 D_004C1E54[4];
extern void func_0039BBF0();
extern void func_001757E0(void *p, u32 b, u32 c);

void func_0039BB70(u8 *p) {
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*D_004C2A08 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_0039BBF0();
    } else {
        s8 a = *(s8 *)(*(u8 **)(p + 0x18) + 0x150);
        s8 b = *(s8 *)(p + 0x150);
        if (b != a) {
            func_001757E0(p, 0x15, D_004C1E54[a >> 1]);
        }
    }
}

extern void func_003DA4A0();
extern void func_0011D8F8(void *d, u32 v, u32 n);
extern u8 D_004F1CD8[12];
extern u8 D_004F1F40[0x170];
extern u8 D_004F1D20[0x214];
extern u8 D_004F1D00[0x18];
extern u8 D_004F1CB0[0x10];
extern u8 D_004C27C4;
extern u8 D_004C27C0;

void func_003DA410(void) {
    func_003DA4A0();
    func_0011D8F8(D_004F1CD8, 0, 0xc);
    func_0011D8F8(D_004F1F40, 0, 0x170);
    func_0011D8F8(D_004F1D20, 0, 0x214);
    func_0011D8F8(D_004F1D00, 0, 0x18);
    func_0011D8F8(D_004F1CB0, 0, 0x10);
    D_004C27C4 = 0;
    D_004C27C0 = 0;
}

extern u8 *func_003DA750(u32 a, u32 b, u32 c);
extern void func_001398D0(void);
extern u32 D_004C2924;
extern u32 D_004C2830;

void func_00139830(u8 *a0) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o) {
        o[0x13c] = 1;
        *(u32 *)(o + 0xc8) = D_004C2924 + 0x88;
        *(void **)(o + 0x10) = func_001398D0;
        *(u16 *)(o + 0xcc) = (u32)a0 + 8;
        *(u32 *)(o + 0x84) = D_004C2830;
        *(u32 *)(o + 0x34) = 0;
        *(u32 *)(o + 0x38) = 0;
        *(u32 *)(o + 0x3c) = 0;
        *(u32 *)(o + 0x40) = 0;
        *(u32 *)(o + 0x44) = 0;
        *(u32 *)(o + 0x48) = 0;
        *(u32 *)(o + 0xd0) = 0x800c0f;
        *(u32 *)(o + 0x78) = 0x3f000000;
        *(u32 *)(o + 0x7c) = 0x3f000000;
        *(u32 *)(o + 0x80) = 0x3f000000;
        *(u32 *)(o + 0xdc) = 0;
    }
}
