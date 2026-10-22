typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 bits, shift, mask; } Ch;
typedef struct { s32 f0, w, h, stride, base, bpp; Ch c[4]; } Px;

extern u8 D_00478320[];

s32 func_003EAEF0(Px *a, Px *b, s32 flag, s32 mode)
{
    s32 x;
    s32 y;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 v;
    u32 c3;
    s32 idx;
    u8 *ab;
    u8 *bb;
    u8 *sp;
    u8 *dp;
    s32 n;

    idx = 0;
    ab = (u8 *)a->base;
    bb = (u8 *)b->base;
    for (y = 0; y < b->h; y++) {
        for (x = 0; x < b->w; x++) {
            if (mode == 1 && flag == 1) {
                sp = ab + a->bpp * ((idx & 0xE0) + D_00478320[idx & 0x1F]);
            } else {
                sp = ab + a->stride * y + a->bpp * x;
            }
            n = a->bpp;
            switch (n) {
            case 2:
                v = *(u16 *)sp;
                break;
            case 3: {
                s32 q2 = ((s8 *)sp)[2];
                s32 q1 = ((s8 *)sp)[1];
                v = (q2 << 16) | (q1 << 8) | q2;
                break;
            }
            case 4:
                v = *(u32 *)sp;
                break;
            }
            c0 = ((v >> a->c[0].shift) & a->c[0].mask) << (8 - a->c[0].bits);
            c1 = ((v >> a->c[1].shift) & a->c[1].mask) << (8 - a->c[1].bits);
            c2 = ((v >> a->c[2].shift) & a->c[2].mask) << (8 - a->c[2].bits);
            c3 = ((v >> a->c[3].shift) & a->c[3].mask) << (8 - a->c[3].bits);
            if (mode == 1 && flag == 0) {
                dp = bb + b->bpp * ((idx & 0xE0) + D_00478320[idx & 0x1F]);
            } else {
                dp = bb + b->stride * y + b->bpp * x;
            }
            if (flag == 0) {
                if (c3 == 0xFF) c3 = 0x80; else c3 >>= 1;
            } else {
                if (c3 == 0x80) c3 = 0xFF; else c3 <<= 1;
            }
            v = (((c0 >> (8 - b->c[0].bits)) & b->c[0].mask) << b->c[0].shift)
              | (((c1 >> (8 - b->c[1].bits)) & b->c[1].mask) << b->c[1].shift)
              | (((c2 >> (8 - b->c[2].bits)) & b->c[2].mask) << b->c[2].shift)
              | (((c3 >> (8 - b->c[3].bits)) & b->c[3].mask) << b->c[3].shift);
            switch (n) {
            case 2:
                *(s16 *)dp = v;
                break;
            case 3:
                dp[0] = c2;
                dp[1] = c1;
                dp[2] = c0;
                break;
            case 4:
                *(s32 *)dp = v;
                break;
            }
            idx++;
        }
    }
    return 1;
}
