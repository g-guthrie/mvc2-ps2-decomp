typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00473220[];
extern s16 D_00473320[];

void func_003AAE20(u8 *a, u8 *b)
{
    extern s32 fptosi(f32);
    extern void func_00175580(u8 *, s32, s32, u32);
    extern void func_003AC500(u8 *, u8 *);
    u8 *s0;
    u8 *a0;
    u8 *b0;
    u8 *o;
    s32 n;
    s32 carry;
    u32 ang;
    s32 dir;
    u32 v;

    a0 = a;
    carry = 0;
    s0 = *(u8 **)(a + 0x18);
    n = b[9];
    *(s16 *)(b + 8) -= 0x140;
    b0 = b;
    if (b[9] != n)
        carry = 1;
    if ((s8)n >= 0) {
        *(u8 *)&dir = b[0x33];
        do {
            a[0x24] = *(s8 *)(s0 + 0x24);
            if ((*(s8 *)&ang = *(s8 *)&dir) < 0) {
                ang = -(ang & 0x7F);
                ang = (ang + 0x40) & 0xFF;
            }
            *(u8 *)&ang = (u32)*(u8 *)&ang + b0[0xA];
            a[0x22] = (s8)ang - 0x20;
            *(u8 *)&ang = ((s8)dir & 0x7F) + 0xC;
            if ((s8)ang >= 0x40) {
                ang &= 0x3F;
                dir ^= 0x80;
            }
            dir = (dir & 0x80) | ang;
            b[0x33] = (s8)dir;
            if (carry) {
                carry = 0;
                v = ang + 0xC;
                if ((s8)v >= 0x40) {
                    v &= 0x3F;
                    dir ^= 0x80;
                }
                dir = (dir & 0x80) | v;
                b[0x33] = (s8)dir;
            }
            ang = (s32)((a[0x22] + 4) & 0xF8) / 8;
            func_00175580(a, 0x1B, 1, ang);
            *(s16 **)(a + 0x164) = D_00473320;
            *(s32 *)(a + 0x1D4) = *(s32 *)(a + 0x17C) + (*(u16 *)(*(u8 **)(a + 0x164) + 0x12) << 4);
            *(s16 *)(b + 0) = fptosi(1.6666666269302368f * (f32)D_00473220[ang * 4 + 0]);
            *(s16 *)(b + 2) = fptosi(2.142857074737549f * (f32)D_00473220[ang * 4 + 1]);
            *(s16 *)(b + 4) = fptosi(1.6666666269302368f * (f32)D_00473220[ang * 4 + 2]);
            *(s16 *)(b + 6) = fptosi(2.142857074737549f * (f32)D_00473220[ang * 4 + 3]);
            o = a;
            a = *(u8 **)(a + 0xC);
            b = a + 0x88;
        } while (--n >= 0);
        *(f32 *)(o + 0x34) = *(f32 *)(b0 + 0x10);
        *(f32 *)(o + 0x38) = *(f32 *)(b0 + 0x14);
        o[0x13C] = 1;
        if (b0[9] > 0) {
            func_003AC500(o, a0);
            return;
        }
    }
    a0[4]++;
    if (s0[6] == 6)
        s0[6] = 7;
    else
        s0[6] = 3;
}
