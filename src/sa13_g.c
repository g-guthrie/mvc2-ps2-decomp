typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_003AF4B0(u8 *a, u8 *b)
{
    extern void func_003DAA40(u8 *);
    u8 *t0, *t1, *t2, *t3, *t4, *v3, *s;
    t3 = *(u8 **)(a + 8);
    t1 = *(u8 **)(a + 0x14);
    t2 = *(u8 **)(a + 0x18);
    t4 = *(u8 **)(t3 + 8);
    *(f32 *)(a + 0x34) = *(f32 *)(t4 + 0x34) + (f32)*(s16 *)(t4 + 0x88) - (f32)*(s16 *)(b + 4);
    *(f32 *)(a + 0x38) = (f32)*(s16 *)(b + 6) + (*(f32 *)(t4 + 0x38) - (f32)*(s16 *)(t4 + 0x8A));
    a[0x13C] = 1;
    *(s16 *)(a + 0x1C) = 1;
    t0 = *(u8 **)(a + 0xC);
    *(f32 *)(t0 + 0x34) = *(f32 *)(t3 + 0x34) + (f32)*(s16 *)(t3 + 0x88) - (f32)*(s16 *)(*(u8 **)(a + 0xC) + 0x8C);
    *(f32 *)(t0 + 0x38) = (f32)*(s16 *)(t0 + 0x8E) + (*(f32 *)(t3 + 0x38) - (f32)*(s16 *)(t3 + 0x8A));
    t0[0x13C] = 1;
    *(s16 *)(t0 + 0x1C) = 1;
    t1[0xB1] = *(s8 *)(t1 + 0xB1) - 2;
    v3 = t1 + 0x88;
    if (*(s8 *)(t1 + 0xB1) != 2) {
        func_003AF4B0(*(u8 **)(t0 + 0xC), *(u8 **)(t0 + 0xC) + 0x88);
        return;
    }
    if (*(s8 *)(t2 + 0x1B4) != 0 || (D_004D18DC & (1 << D_004D18DB)) != 0)
        return;
    *(f32 *)(t2 + 0x34) = *(f32 *)(t0 + 0x34) - *(f32 *)(v3 + 0x1C);
    *(f32 *)(t2 + 0x38) = *(f32 *)(t0 + 0x38) - *(f32 *)(v3 + 0x20);
    v3[0x28] = *(s8 *)(v3 + 0x28) - 2;
    s = *(u8 **)(t0 + 0xC);
    func_003DAA40(s);
    func_003DAA40(*(u8 **)(s + 0xC));
}
