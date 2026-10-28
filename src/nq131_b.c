typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x5C-0x3C]; f32 f5c; f32 f60; u8 p2[4]; f32 f68; f32 f6c; } SB;
extern s16 D_00476100[];
extern s16 D_00476102[];

void residual_003C8330(u8 *o, u8 *a) {
    extern void func_003C84E0(u8 *, u8 *, f32, f32);
    extern void func_00175700(u8 *);
    s16 x, y;
    s32 off;
    if (o[6] == 0) {
        o[6]++;
        o[0x13C] = 1;
        off = (o[0x20] * 2 + o[0x21] * 6) * 2;
        x = *(s16 *)((u8 *)D_00476100 + off);
        y = *(s16 *)((u8 *)D_00476102 + off);
        if (*(s16 *)(o + 0x140) != 0) {
            x = -x;
            y = -y;
        }
        *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34) + 1.6666666269302368f * (f32)(x + y);
        *(f32 *)(o + 0x38) = 1028.5714111328125f + *(f32 *)(a + 0x38);
        func_003C84E0(o, a, 1.6666666269302368f * (f32)(-y), -1028.5714111328125f);
        return;
    }
    func_00175700(o);
    {
    f32 *p5c, *p60, *p68, *p6c;
    p5c = (f32 *)(o + 0x5C); p68 = (f32 *)(o + 0x68); p60 = (f32 *)(o + 0x60); p6c = (f32 *)(o + 0x6C);
    *(f32 *)(o + 0x34) += *(f32 *)(o + 0x5C);
    *(f32 *)(o + 0x5C) += *(f32 *)(o + 0x68);
    *(f32 *)(o + 0x38) += *(f32 *)(o + 0x60);
    *(f32 *)(o + 0x60) += *(f32 *)(o + 0x6C);
    if (!(*(f32 *)(a + 0x430) <= *(f32 *)(o + 0x38))) {
        ((SB *)o)->f38 = *(f32 *)(a + 0x430);
        *(s32 *)p5c = 0;
        *(s32 *)p60 = 0;
        *(s32 *)p68 = 0;
        *(s32 *)p6c = 0;
        o[5] = 1;
        o[6] = 0;
    }
}
}
