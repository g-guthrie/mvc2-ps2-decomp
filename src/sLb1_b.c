/* func_0032B800: MW 3.0.3 (also 3.0) -O3 -sdatathreshold 8, exact. (s32)p->b538 index on the 0x2000 test breaks the s0*2 CSE. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 p0[4]; s8 b4; u8 p5; u8 b6; u8 p7[0x25]; u32 w2c; u8 p30[0x4AC]; s8 b4dc; u8 p4dd[0x5B]; s8 b538; } PP;
typedef struct { u8 p0[0x49]; s8 b49; u8 p4a[0xBC]; s16 h106[4]; } GG;
typedef struct { u16 h; u8 pad[18]; } EE;

extern GG *D_004C2840;
extern u16 D_004C291C[4];
extern s8 D_004C292C;
extern s16 D_00583BDC[];
extern u8 D_00583BE2[];
extern u8 D_00583B90[];
extern EE D_004F4482[];

void func_0032B800(PP *p)
{
    extern void func_001E3CE0(s32);
    extern void func_0013A070(PP *, s32);
    s32 s0;

    s0 = p->b538;
    switch (p->b6) {
    case 0:
        p->b6++;
        D_00583BE2[p->b538] = 0;
        D_004C2840->h106[s0] = 1;
        p->w2c = (u16)D_004C2840->h106[s0];
    case 1:
        if (D_00583B90[p->b538] == 4) p->b6++;
        break;
    case 2:
        if (D_00583BDC[0] == 0) {
            D_004C291C[s0] = 0x200;
        } else {
            if (D_004C291C[(s32)p->b538] & 0x2000) {
                if ((D_004F4482[s0].h & 0x3FC) == 0) {
                    D_004C2840->h106[s0]--;
                    func_001E3CE0((u8)(p->b538 * 2 + 0x40));
                    goto L93C;
                }
                goto LA00;
            }
        L93C:
            if (D_004C291C[p->b538] & 0x1000) {
                if ((D_004F4482[p->b538].h & 0x3FC) == 0) {
                    D_004C2840->h106[s0]++;
                    func_001E3CE0((u8)(p->b538 * 2 + 0x40));
                } else goto LA00;
            }
            D_004C2840->h106[s0] &= 1;
            p->w2c = (u16)D_004C2840->h106[s0];
            if ((D_004F4482[p->b538].h & 0x3FC) == 0) break;
        }
    LA00:
        p->b6++;
        D_00583BE2[p->b538] = 1;
        D_004C2840->h106[s0] = ((u16)D_004C2840->h106[s0] != 0) ? 0 : 1;
        func_001E3CE0((u8)(p->b538 * 2 + 0x41));
        break;
    case 3:
        if (D_00583B90[s0] == 5) {
            s8 c = D_004C292C;
            if (c < 0) {
                D_004C292C = p->b4dc;
                if (D_004C2840->b49 != 0) {
                    p->b4 = 11;
                    D_00583BE2[p->b538] = 0;
                    p->b6 = 0;
                } else {
                    p->b4 = 8;
                    D_00583BE2[p->b538] = 0;
                    p->b6 = 0;
                    func_0013A070(p, 0);
                }
            } else if (c == p->b4dc) {
                if (D_004C2840->b49 != 0) {
                    p->b4 = 11;
                    D_00583BE2[p->b538] = 0;
                    p->b6 = 0;
                } else {
                    p->b4 = 8;
                    D_00583BE2[p->b538] = 0;
                    p->b6 = 0;
                    func_0013A070(p, 0);
                }
            } else {
                p->b4 = 11;
            }
        }
        break;
    }
}
