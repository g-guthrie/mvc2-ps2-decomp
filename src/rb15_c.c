typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x30]; u32 w[2]; } G_41CB60;
typedef struct { s16 v[64]; } T_41CB60;
extern G_41CB60 *D_004C2840;
extern T_41CB60 D_004A6DF0;
extern s16 D_00633720[][8];

void func_0041CB60(void)
{
    extern s32 func_00131830(s32, s32);
    T_41CB60 loc;
    s32 i;
    s32 n;
    s32 j;
    u32 *q;
    s16 code;
    s16 *dst;

    loc = D_004A6DF0;
    i = 0;
    j = 0;
    do {
        code = *(s16 *)((u8 *)&loc + j);
        dst = &D_00633720[i & 7][i >> 3];
        *dst = code;
        if (code != 0xFFFF) {
            n = code & 0x3F;
            if (func_00131830(n, 0) != 0) {
                *dst = *(u8 *)dst;
            } else {
                *dst |= 0x100;
            }
            if (n >= 0x20) {
                n -= 0x20;
                q = &D_004C2840->w[1];
            } else {
                q = &D_004C2840->w[0];
            }
            if ((*q & (1 << n)) != 0) {
                *dst &= 0xFF3F;
            }
        }
        i++;
        j += 2;
    } while (i < 64);
}
