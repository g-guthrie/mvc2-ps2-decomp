typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_00464930[];
extern void func_001757E0(u8 *, s32, s32);
extern void func_003874C0(u8 *);

void residual_003873A0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u8 *tbl;
    s16 code;
    u32 t;
    code = 0x1C03;
    n = 0x31;
    q = *(u8 **)(p + 0x18);
    t = p[4];
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    s = (s32 *)(q + 0xEC);
    *(s16 *)(p + 0x26) = code;
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
    p[0x13C] = 1;
    tbl = D_00464930 + p[0x20] * 6;
    func_001757E0(p, tbl[4], tbl[5]);
    p[0x24] = 0xB;
    *(s8 *)(p + 0x31) = *(s8 *)tbl;
    func_003874C0(p);
}
