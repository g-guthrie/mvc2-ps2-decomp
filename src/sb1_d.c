typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044A010[];
extern s16 D_0044A012[];
extern s8 D_0044A014[];

typedef struct { u8 pad[0x160]; s8 b[8]; } S196B;

void func_00196760(u8 *a, u8 *b)
{
    extern void func_00175580(u8 *, s32, u8, s8); extern void func_001975C0();
    s8 *p;
    s8 f;
    s8 *q;
    s32 u;
    u8 *a2 = a + 0x88;
    u8 *a3 = b + 0x2B8;
    if (b[5] != 0 || *(u16 *)(a2 + 0x20) != *(u16 *)(b + 0x168)) {
        a2[0] = 0;
        if (b[0x1E4] != 0x16) a3[0xC] = 0;
        a[5] = 0;
        return;
    }
    if ((u = a[0x21]) < 4) {
        p = ((S196B *)b)->b;
        f = p[1];
        q = p + 1;
        func_00175580(a, 0x1B, u += 0xB, f);
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
        *(s16 *)(a + 0x140) = 0;
        *(f32 *)(a + 0x5C) = 1.6666666269302368f * (f32)(*(s16 *)(q[0] * 6 + ((s32)D_0044A010 + a[0x21] * 54)) * 256) / 256.0f;
        *(f32 *)(a + 0x60) = 2.1428570747375488f * (f32)(*(s16 *)(q[0] * 6 + ((s32)D_0044A012 + a[0x21] * 54)) * 256) / 256.0f;
        a[0x31] = *(s8 *)(q[0] * 6 + ((s32)D_0044A014 + a[0x21] * 54));
        if (*(s16 *)(b + 0x140) != 0) {
            *(f32 *)((s32)a + 0x5C) = -*(f32 *)(a + 0x5C);
            *(s16 *)((s32)a + 0x140) ^= 1;
        }
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x38) -= *(f32 *)(a + 0x60);
        func_001975C0(a, b);
    }
}
