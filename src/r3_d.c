typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

extern u8 D_006207A0[];
extern s32 D_004C2AE8[2];
extern u8 D_004BA890[];
extern s32 func_003ED0D0(void *);
s32 func_003E8F90(void) {
    s32 i = 0;
    s32 off = 0;
    do {
        if (*(s16 *)(D_006207A0 + off + 0x2C) == 0) break;
        i++;
        off += 0x40;
    } while (i < 0x180);
    if (i >= 0x180) {
        func_003ED0D0(D_004BA890);
        return 0;
    }
    D_004C2AE8[0]++;
    return i + 1;
}

typedef struct N2 { u8 pad0[4]; struct N2 *next; u8 pad1[0xC]; s16 f14; s16 f16; } N2;
extern void *D_004C2AB4[2];
extern u32 D_0062BC34[];
N2 *func_003EBE70(u32 n) {
    N2 *p = D_004C2AB4[0];
    N2 *q;
    s32 e;
    if (p == 0) return 0;
    if (D_0062BC34[0] < p->f14) {
        if (p->f14 - D_0062BC34[0] >= n) return 0;
    }
    for (;;) {
        q = p->next;
        if (q == 0) {
            e = p->f14 + p->f16;
            if (e >= 0x4000) return (N2 *)-1;
            if (n + e >= 0x4000) return (N2 *)-1;
            return p;
        }
        if (q->f14 - (p->f14 + p->f16) >= n) return p;
        p = q;
    }
}

typedef struct N1 { struct N1 *next; struct N1 *prev; } N1;
extern void *D_004C2AB4[2];
extern s32 D_004C2AB0[2];
extern void func_003F55B0(void *, s32, s32);
void func_003EB9C0(N1 *p) {
    N1 *a = p->next;
    N1 *b = p->prev;
    if (a) a->prev = b; else D_004C2AB4[0] = b;
    if (b) b->next = a;
    func_003F55B0(p, 0, 0x18);
    D_004C2AB0[0] = D_004C2AB0[0] - 1;
}

