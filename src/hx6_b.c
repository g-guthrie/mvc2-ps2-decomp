typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef void (*hx6b_fp)(u8 *, u8 *);
extern s16 D_00472D40[];
extern s16 D_00472D42[];
extern hx6b_fp D_00472D70[];

void func_003A5220(u8 *p, u8 *a1)
{
    extern void func_003A58E0(u8 *, u8 *);

    *(s8 *)(p + 0x24) = *(s8 *)(a1 + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) {
        *(s8 *)(p + 0x24) = 7;
    }
    if (*(s8 *)(p + 0x24) < 0) {
        *(s8 *)(p + 0x24) = 0;
    }
    if (a1[0x169] != 9) {
        {
            u32 t4 = p[4];
            p[4] = t4 + 1;
        }
        func_003A58E0(p, a1);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(a1 + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(a1 + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(a1 + 0x3C);
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) += 1.6666666f * (f32)*(s16 *)((u8 *)D_00472D40 + (p[0x21] << 2));
    } else {
        *(f32 *)(p + 0x34) -= 1.6666666f * (f32)*(s16 *)((u8 *)D_00472D40 + (p[0x21] << 2));
    }
    *(f32 *)(p + 0x38) += 2.142857f * (f32)*(s16 *)((u8 *)D_00472D42 + (p[0x21] << 2));
    D_00472D70[p[5]](p, a1);
}
