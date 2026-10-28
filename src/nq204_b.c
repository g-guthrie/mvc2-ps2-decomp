/* MWCC 3.0.3: ./try.sh src/nq204_b.c (default -O3 -sdatathreshold 0); static func_001734D0 is the real callee body */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x4D2];
    s8 b4D2;
    u8 pad1[3];
    s16 h4D6;
    s16 h4D8;
    u8 pad2[0x520 - 0x4DA];
    s8 b520;
    u8 pad3[0x538 - 0x521];
    s8 b538;
    u8 pad4[0x544 - 0x539];
    s8 b544[4];
} P;

extern u16 D_004F4484[];
extern u16 D_004F4490[];

static void func_001734D0(P *a0)
{
    *(s16 *)((u8 *)a0 + 0x4DA) = 40;
    *((u8 *)a0 + 0x4D3) = 1;
}

void func_001737A0(P *p)
{
    extern s32 func_001733E0(P *);
    extern void func_00173470(P *);
    extern void func_00173C30();
    u16 h;
    s32 idx;
    s8 *q;
    s16 v;

    if (func_001733E0(p) == 0) {
        h = D_004F4484[(p->b538 & 1) * 10];
        if (h & 0x3F0) {
            p->h4D6 += 300;
            func_001734D0(p);
            v = p->h4D8;
            if (v == 0x2C) {
                p->b544[p->b4D2] = 0x2B;
                p->b4D2--;
                if (p->b4D2 < 0) {
                    p->b4D2 = 0;
                    p->b544[p->b4D2] = 0;
                }
                p->b520 ^= 1 << p->b4D2;
                p->h4D8 = p->b544[p->b4D2];
            } else if (v == 0x2D) {
                func_00173C30(p);
            } else {
                q = (s8 *)(p->b4D2 + (s32)p) + 0x544;
                if (*q == 0x2B) {
                    *q = 0;
                }
                p->b520 |= 1 << p->b4D2;
                p->b4D2++;
                if (p->b4D2 == 3) {
                    p->b544[3] = 0x2D;
                    p->h4D8 = 0;
                }
            }
        } else {
            if ((h & 0xC00) || (D_004F4490[(p->b538 & 1) * 10] & 0xC00)) {
                func_001734D0(p);
            } else {
                func_00173470(p);
            }
            idx = (p->b538 & 1) * 10;
            if (D_004F4484[idx] == 0x400 || D_004F4490[idx] == 0x400) {
                p->h4D8++;
                if (p->h4D8 == 0x2B) {
                    p->h4D8++;
                }
                p->h4D8 = (p->h4D8 + 0x2E) % 0x2E;
            }
            idx = (p->b538 & 1) * 10;
            if (D_004F4484[idx] == 0x800 || D_004F4490[idx] == 0x800) {
                p->h4D8--;
                if (p->h4D8 == 0x2B) {
                    p->h4D8--;
                }
                p->h4D8 = (p->h4D8 + 0x2E) % 0x2E;
            }
            p->b544[p->b4D2] = p->h4D8;
        }
    }
}
