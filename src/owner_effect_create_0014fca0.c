typedef unsigned char u8;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;struct B14FD;
void func_0014FCA0(u8 *p, s32 n) {
    extern void *func_003DA750(void *, s32, s32);
    extern void func_0014FD80(struct B14FD *);
    extern void func_00150520(u8 *, f32, f32, f32);
    extern u8 *D_004C27FC;
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(struct B14FD *))(o + 0x10) = func_0014FD80;
        *(u32 *)(o + 0xD0) = 0x421;
        *(s16 *)(o + 0x1E) = n;
        *(u32 *)(o + 0x34) = 0x410547AE;
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3DA3D70A;
        func_00150520(o, 1.0f, 0.620100021f, 0.807299972f);
        *(s16 *)(o + 0xCC) = 0x38;
        *(u8 **)(o + 0x84) = D_004C27FC;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}
