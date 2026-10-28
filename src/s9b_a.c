/* func_003EA660: MWCC 3.0.3 (./try.sh, also exact on 3.0) "-O3,p -sdatathreshold 8". The six-nop asm statements are the retail busy-wait delays (same idiom as src/rt21_a.c); the retry loop is entered at the call, skipping the delay. */
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[8]; u32 w8; u8 padc[4]; s16 h10; s16 h12; u8 pad14[4]; s16 h18; s16 h1a; s16 h1c; u8 pad1e[2]; s32 w20; s16 h24; s16 h26; s32 w28; u8 pad2c[0x14]; } EA660;
extern EA660 D_006207A0[];
extern EA660 D_0061C7A0[];
extern u8 D_0062BBA0[];
extern u8 D_004BA9D0[];
typedef struct LA660 { u8 pad[4]; struct LA660 *next; } LA660;
extern LA660 *D_004C2AB4;

void func_003EA660(s32 n, u32 *list)
{
    extern s32 func_003EBA40(EA660 *);
    extern s32 func_003EBE70(s16);
    extern s32 func_003EBA80(s32, EA660 *);
    extern void func_003ED0D0(u8 *);
    extern s32 func_003EBF30(EA660 *, u32 *, s32);
    extern s32 func_003EBC20(s32, EA660 *);
    extern s32 func_003DD030(s32);
    extern s32 func_003DBD20(s32);
    extern s32 func_003DBD70(s32);
    extern void *func_003DD160(s32, s32);
    extern void func_003DBD80(void *pkt, s32 a1, u32 addr, u32 total, s16 p4, s16 p5, s16 p6, s16 p7, s16 p8, s16 p9, s16 p10);
    extern void func_003DC120(void *, s32);
    extern void func_003DC2F0(u32, u8 *);
    s32 i;
    EA660 *e;
    s32 j;
    void *s2;
    u32 v;
    s32 s5;
    s32 r;
    u32 idx;

    s2 = 0;
    i = 0;
    goto otest;
outer:
        v = list[i];
        j = 0;
        goto itest;
inner:
            if (j == 0) {
                idx = v & 0xFFFF;
                if (idx == 0) goto next;
                e = &D_006207A0[idx - 1];
            } else {
                idx = (v & 0xFFFF0000) >> 16;
                if (idx == 0) goto next;
                e = &D_0061C7A0[idx - 1];
            }
            if (func_003EBA40(e) != 0) goto next;
            r = func_003EBE70(e->h10);
            if (r != -1) {
                if (func_003EBA80(r, e) == 0) func_003ED0D0(D_004BA9D0);
            } else {
                goto call;
            delay:
                __asm__("nop;nop;nop;nop;nop;nop");
            call:
                r = func_003EBF30(e, list, n);
                if (r == -1) goto delay;
                if (r == 1) {
                    LA660 *o = D_004C2AB4;
                    while (*(LA660 * volatile *)&o->next != 0) {
                        o = o->next;
                        __asm__("nop;nop;nop;nop;nop;nop");
                    }
                    r = (s32)o;
                    if (func_003EBA80(r, e) == 0) func_003ED0D0(D_004BA9D0);
                } else {
                    if (func_003EBC20(r, e) == 0) func_003ED0D0(D_004BA9D0);
                }
            }
            s5 = func_003DD030(e->w28);
            s2 = func_003DD160(func_003DBD20(e->w8), 0x10);
            if (e->w20 == 0) {
                func_003DBD80(s2, 1, s5, e->w8, e->h12, e->h18 / 64, *(volatile s16 *)&e->h1c, 0, 0, *(volatile s16 *)&e->h18, e->h1a);
            } else {
                func_003DBD80(s2, 1, s5, e->w8, e->h12, e->h24 / 64, 0, 0, 0, *(volatile s16 *)&e->h24, e->h26);
            }
            func_003DC2F0(((u32)s2 & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
            s2 = e;
        next:
            j++;
        itest:
            if (j < 2) goto inner;
        i++;
otest:
    if (i < n) goto outer;
    if (s2 != 0) {
        s2 = func_003DD160(func_003DBD70(e->w8), 0x10);
        func_003DC120(s2, 1);
        func_003DC2F0((u32)s2 & 0xFFFFFFF, D_0062BBA0);
    }
}
