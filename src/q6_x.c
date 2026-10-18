typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A4;

void func_00185640(u8 *a, u8 *b) {
    extern void func_00186A60(u8 *, s32);
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00190D50(u8 *, u8 *);
    u8 t;
    u32 u;
    *(u8 **)(a + 0x1DC) = b;
    *(u8 **)(a + 0x1E0) = b;
    *(u8 **)(b + 0x1DC) = a;
    *(u8 **)(b + 0x1E0) = a;
    (*(void (**)(u8 *))(*(u8 **)(a + 0x43C) + 0x28))(a);
    a[5] = 1;
    a[7] = 0;
    a[6] = 0;
    a[0x1FE] = 1;
    b[0x20B] = a[0x20B];
    b[5] = 2;
    func_00186A60(b, 0x1F);
    b[0x20A] = 0;
    b[7] = 0;
    b[6] = 0;
    *(s8 *)(b + 0x16A) = -1;
    b[0x1B4] = 0;
    b[0x1F7] = 0;
    b[0x215] = 0;
    b[0x23F] = b[0x23E];
    b[0x23E] = 0;
    D_004D18A4 |= 1 << *(s8 *)(b + 0x1B8);
    func_0011D8F8(b + 0x370, 0, 8);
    b[0x24A] = 0x78;
    func_00186A60(a, 0x1E);
    func_00175C00(b, 1);
    func_00190D50(b, a);
    u = b[0x24F];
    t = u + 2;
    b[0x24F] = t;
    if (t == 0) {
        b[0x24F] = 0xFF;
    }
}
