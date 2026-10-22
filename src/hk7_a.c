typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Hk7nSub {
    s16 h0;
    s16 h2;
    u8 b4;
    u8 pad5;
    s16 h6;
    s16 h8;
    s8 bA;
} Hk7nSub;

typedef struct Hk7nCtx {
    u8 pad0[4];
    u8 b4;
    u8 pad5[3];
    u8 *pa;
    u8 pad9[0x14 - 0x0C];
    u8 *pb;
    u8 padC[0x21 - 0x18];
    u8 b21;
    u8 pad22[0x13C - 0x22];
    s8 b13C;
    u8 pad13D[0x1B2 - 0x13D];
    s8 b1B2;
    s8 b1B3;
} Hk7nCtx;

extern s8 *D_004C2840;

void func_003B6D90(Hk7nCtx *p, void *a1) {
    extern void func_003B6FF0(Hk7nCtx *, void *);
    extern void func_003B70F0(Hk7nCtx *, void *);
    extern void func_001E7F60(Hk7nCtx *);
    extern s32 func_00174240(Hk7nCtx *);
    Hk7nSub *s0;
    Hk7nSub *s1;
    Hk7nSub *a3;
    s0 = (Hk7nSub *)((u8 *)p + 0x88);
    s1 = (Hk7nSub *)((u8 *)p->pb + 0x88);
    a3 = (Hk7nSub *)((u8 *)p->pa + 0x88);
    if (p->pb[4] != 1) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
        s0->bA = s1->bA;
        s0->h0 = a3->h0;
        func_003B6FF0(p, a1);
        func_003B70F0(p, a1);
        if (p->b1B3 != 0) {
            s1->h6 = p->b21;
            s1->h2 = -1;
            s0->h2 = 0;
            p->b1B3 = 0;
            return;
        }
        if (p->b1B2 != 0) {
            s1->h6 = p->b21;
            s1->h2 = -1;
            s0->h2 = 0;
            p->b1B2 = 0;
            return;
        }
        if (p->b13C == 0) {
            return;
        }
        if (s1->h8 != 0) {
            s1->h8 = 0;
            p->b13C = 0;
            return;
        }
        if (s1->h6 == p->b21 && s1->h6 < 0xB) {
            s1->h6 = s1->h6 + 1;
            s1->h8 = 1;
        }
        if (s1->h2 > 0) {
            if (*(s32 *)(D_004C2840 + 0x1C) & 1) {
                func_001E7F60(p);
            }
        }
        p->b13C = func_00174240(p);
}
