typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00473220[];
extern s16 D_00473222[];
extern s16 D_00473224[];
extern s16 D_00473226[];
extern u8 D_00473320[];


void func_003AB950(u8 *p, s16 *out, u8 idx) {
    extern void func_00175580(u8 *, s32, s32, u8);
    extern s32 func_00118FA8(f32);
    u8 *q;
    s32 k;
    s32 o;
    p[0x22] = idx;
    k = (u8)((((u8)idx + 4) & 0xF8) / 8);
    func_00175580(p, 0x1B, 1, k);
    *(u8 **)(p + 0x164) = D_00473320;
    *(u8 **)(p + 0x1D4) = *(u8 **)(p + 0x17C) + (*(u16 *)(*(u8 *volatile *)(p + 0x164) + 0x12) << 4);
    o = (u8)k << 3;
    out[0] = func_00118FA8(1.6666666269302368f * (f32)*(s16 *)((u8 *)D_00473220 + o));
    out[1] = func_00118FA8(2.142857074737549f * (f32)D_00473222[(u8)k * 4]);
    out[2] = func_00118FA8(1.6666666269302368f * (f32)*(s16 *)((u8 *)D_00473224 + o));
    out[3] = func_00118FA8(2.142857074737549f * (f32)*(s16 *)((u8 *)D_00473226 + o));
    q = *(u8 **)(p + 8);
    *(f32 *)(out + 0x2C / 2) = (*(f32 *)(q + 0x34) + (f32)*(s16 *)(q + 0x88)) - (f32)out[2];
    *(f32 *)(p + 0x34) = *(f32 *)(out + 0x2C / 2);
    *(f32 *)(p + 0x38) = (f32)out[3] + (*(f32 *)(q + 0x38) - (f32)*(s16 *)(q + 0x8A));
    p[0x24] = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
}
