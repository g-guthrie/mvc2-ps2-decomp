typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00473220[];
extern s16 D_00473320[];

void func_003ACEB0(u8 *p, u8 *o, u8 *q) {
    extern s32 fptosi(f32);
    extern void func_00175580(u8 *, s32, s32, u8);
    u8 *r;
    f32 y, x;
    f32 a;
    u8 c;
    s32 v;
    u32 k;
    r = *(u8 **)(p + 0x14);
    a = 1.6666666269302368f * (f32)*(s16 *)(q + 4);
    c = q[1];
    if (*(s16 *)(r + 0x140) != 0) {
        c = -(s8)c;
        a = -a;
    }
    p[0x22] = c;
    *(f32 *)(o + 0x18) = a;
    *(f32 *)(o + 0x1C) = 2.142857074737549f * (f32)*(s16 *)(q + 6);
    x = *(f32 *)(r + 0x34) + *(f32 *)(o + 0x18);
    *(f32 *)(o + 0x10) = x;
    y = *(f32 *)(r + 0x38) + *(f32 *)(o + 0x1C);
    *(f32 *)(o + 0x14) = y;
    v = ((c & 0xFF) + 4) & 0xF8;
    k = (u8)(v / 8);
    func_00175580(p, 0x1B, 1, k);
    *(s16 **)(p + 0x164) = D_00473320;
    *(s32 *)(p + 0x1D4) = *(s32 *)(p + 0x17C) + (*(u16 *)(*(u8 **)(p + 0x164) + 0x12) << 4);
    *(s16 *)(o + 0) = fptosi(1.6666666269302368f * (f32)D_00473220[(u8)k * 4 + 0]);
    *(s16 *)(o + 2) = fptosi(2.142857074737549f * (f32)D_00473220[(u8)k * 4 + 1]);
    *(s16 *)(o + 4) = fptosi(1.6666666269302368f * (f32)D_00473220[(u8)k * 4 + 2]);
    *(s16 *)(o + 6) = fptosi(2.142857074737549f * (f32)D_00473220[(u8)k * 4 + 3]);
    if (q[3] != 0) {
        x -= (f32)*(s16 *)(o + 4);
        y += (f32)*(s16 *)(o + 6);
    }
    *(f32 *)(o + 0x2C) = x;
    *(f32 *)(p + 0x34) = x;
    *(f32 *)(p + 0x38) = y;
    p[0x24] = *(s8 *)(r + 0x24);
}
