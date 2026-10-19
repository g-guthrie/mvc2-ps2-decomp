typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s16 D_0044E400[];
extern u8 D_0044E420[];
extern f32 D_0044E430[];
extern s32 func_00118FA8(f32);
extern void func_001757E0(u8 *, s32, s32);

void residual_001D5320(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[4]++;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + (f32)D_0044E400[p[0x21]] * 2.1428570747375488f;
    func_001757E0(p, 0x17, (D_0044E420[p[0x21]] + 0xA) & 0xFF);
    *(s8 *)(p + 0x24) = (s8)func_00118FA8(D_0044E430[*(s8 *)(p + 0x151) >> 1]);
}
