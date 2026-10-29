/* r12_08_a: Metrowerks 3.0 (./try30.sh) "-O3,p -sdatathreshold 8".
   func_003DB020: per-slot record rebuild (5 records of 0x88 bytes, D_004C2A68 -> D_004C2A6C).
   func_003EBF30: free-block search over the D_004C2AB4 node list. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_240a;

extern u8 *D_004C2A68;
extern u8 *D_004C2A6C;
extern u8 D_0058EEF0[];
extern u8 D_004BA4A0[][16];
extern u8 D_004BA4E0[][4];
extern u32 D_004BA430[];

void func_003DB020(void)
{
    extern void func_003DB780(u8 *, u8, u32);
    extern void func_003DB890(u8 *, u32);
    extern void func_003DB8E0(u8 *);
    extern void func_003DB7F0(u8 *);
    u32 acc;
    s32 jo;
    s32 recoff;
    u8 *s3;
    s16 j;
    u32 m;
    s16 i;
    s32 off;
    s16 k;
    u8 *src;
    u32 w;
    u8 buf[32];
    u8 *p21;
    u8 *p22;

    i = 0;
    off = 0;
    recoff = 0;
    while (i < 5) {
        s3 = D_0058EEF0 + off;
        p21 = s3 + 0x21;
        p22 = s3 + 0x22;
        D_004C2A6C[recoff + 0] = D_004C2A68[recoff + 0];
        D_004C2A6C[recoff + 1] = D_004C2A68[recoff + 1];
        *(u16 *)(D_004C2A6C + recoff + 2) = *(u16 *)(D_004C2A68 + recoff + 2);
        *(f32 *)(D_004C2A6C + recoff + 4) = *(f32 *)(D_004C2A68 + recoff + 4);
        src = D_004C2A68 + recoff;
        w = *(u32 *)(src + 8);
        m = w & 0xFFF0;
        m |= D_004BA4A0[s3[0x20]][w & 0xF];
        m |= D_004BA4A0[s3[0x21]][(w >> 16) & 0xF] << 16;
        m |= D_004BA4A0[s3[0x22]][(w >> 20) & 0xF] << 20;
        for (k = 0; k < 4; k++) buf[k] = src[0x1C + D_004BA4E0[s3[0x20]][k]];
        for (k = 4; k < 16; k++) {
            buf[k] = src[0x1C + k];
        }
        for (k = 0; k < 16; k++) {
            D_004C2A6C[recoff + 0x1C + k] = 0;
        }
        acc = 0;
        j = 0;
        jo = 0;
        for (; j < 24; j++) {
            if (m & *(u32 *)((u8 *)D_004BA430 + jo)) {
                acc |= D_004BA430[s3[j]];
            }
            if (s3[j] < 16) {
                u8 *d = (u8 *)(recoff + (s32)D_004C2A6C) + s3[j] + 0x1C;
                if (*d < buf[j]) {
                    *d = buf[j];
                }
            } else if (s3[j] > 24) {
                func_003DB780(D_004C2A6C + recoff + 0x1C, buf[j], D_004BA430[s3[j]]);
            }
            jo += 4;
        }
        func_003DB890(D_004C2A6C + recoff, acc);
        func_003DB8E0(D_004C2A6C + recoff);
        *(u32 *)(D_004C2A6C + recoff + 0x44) = *(u32 *)(D_004C2A6C + recoff + 0x10);
        *(V3_240a *)(D_004C2A6C + recoff + 0x2C) = *(V3_240a *)(D_004C2A68 + recoff + 0x2C);
        switch (*p21) {
        case 1:
            *(s16 *)(D_004C2A6C + recoff + 0x2C) = -*(s16 *)(D_004C2A6C + recoff + 0x2C);
            { s16 *r = (s16 *)(D_004C2A6C + recoff + 0x32); *r = 0x21C - *r; }
            break;
        case 2:
            *(s16 *)(D_004C2A6C + recoff + 0x2E) = -*(s16 *)(D_004C2A6C + recoff + 0x2E);
            { s16 *r = (s16 *)(D_004C2A6C + recoff + 0x32); *r = 0x168 - *r; }
            break;
        case 3:
            *(s16 *)(D_004C2A6C + recoff + 0x2C) = -*(s16 *)(D_004C2A6C + recoff + 0x2C);
            *(s16 *)(D_004C2A6C + recoff + 0x2E) = -*(s16 *)(D_004C2A6C + recoff + 0x2E);
            *(s16 *)(D_004C2A6C + recoff + 0x32) += 0xB4;
            break;
        }
        *(V3_240a *)(D_004C2A6C + recoff + 0x38) = *(V3_240a *)(D_004C2A68 + recoff + 0x38);
        switch (*p22) {
        case 1:
            *(s16 *)(D_004C2A6C + recoff + 0x38) = -*(s16 *)(D_004C2A6C + recoff + 0x38);
            { s16 *r = (s16 *)(D_004C2A6C + recoff + 0x3E); *r = 0x21C - *r; }
            break;
        case 2:
            *(s16 *)(D_004C2A6C + recoff + 0x3A) = -*(s16 *)(D_004C2A6C + recoff + 0x3A);
            { s16 *r = (s16 *)(D_004C2A6C + recoff + 0x3E); *r = 0x168 - *r; }
            break;
        case 3:
            *(s16 *)(D_004C2A6C + recoff + 0x38) = -*(s16 *)(D_004C2A6C + recoff + 0x38);
            *(s16 *)(D_004C2A6C + recoff + 0x3A) = -*(s16 *)(D_004C2A6C + recoff + 0x3A);
            *(s16 *)(D_004C2A6C + recoff + 0x3E) += 0xB4;
            break;
        }
        *(s16 *)(D_004C2A6C + recoff + 0x32) %= 360;
        *(s16 *)(D_004C2A6C + recoff + 0x3E) %= 360;
        func_003DB7F0(D_004C2A6C + recoff + 0x2C);
        func_003DB7F0(D_004C2A6C + recoff + 0x38);
        i++;
        recoff += 0x88;
        off += 0x2C;
    }
}

#pragma padloop on

typedef struct Node {
    s32 f0;
    struct Node *next;
    u8 *f8;
    s32 fC;
    s32 kind;
    s16 pos;
    s16 size;
} Node;
typedef struct { u8 pad[0x10]; s16 size; } Obj;

extern Node *D_004C2AB4;
extern u8 D_006207A0[];
extern u8 D_0061C7A0[];

#define SCAN(n, i) \
    for (i = 0; i < a2; i++) { \
        e = a1[i]; \
        lo = e & 0xFFFF; \
        if (lo != 0 && D_006207A0 + ((lo - 1) << 6) == (n)->f8) goto next; \
        hi = (e & 0xFFFF0000) >> 16; \
        if (hi != 0 && D_0061C7A0 + ((hi - 1) << 6) == (n)->f8) goto next; \
    }
#define SCAN2(n, i, o) \
    i = 0; \
    if (i < a2) { \
        o = 0; \
        do { \
            e = *(u32 *)((u8 *)a1 + o); \
            lo = e & 0xFFFF; \
            if (lo != 0 && D_006207A0 + ((lo - 1) << 6) == (n)->f8) goto next; \
            hi = (e & 0xFFFF0000) >> 16; \
            if (hi != 0 && D_0061C7A0 + ((hi - 1) << 6) == (n)->f8) goto next; \
            i++; o += 4; \
        } while (i < a2); \
    }

s32 func_003EBF30(Obj *a0, u32 *a1, s32 a2) {
    s32 i;
    s32 cand;
    s32 off;
    Node *cur;
    Node *prev;
    s32 sz;
    s32 pos;
    Node *nx;
    u32 e;
    u32 lo;
    u32 hi;
    cur = D_004C2AB4;
    if (cur == 0) return 0;
    do {
        if (cur->kind == 1 || cur->kind == 4) {
            SCAN(cur, i)
            nx = cur->next;
            if (nx == 0) {
                if (!(0x4000 - cur->pos < a0->size)) return (s32)cur;
            } else {
                cand = (s32)cur;
                while (pos = ((Node *)cand)->pos, sz = a0->size, nx->pos - pos < sz) {
                    cur = nx;
                    if (nx->kind != 1 && nx->kind != 4) goto next;
                    SCAN2(nx, i, off)
                    nx = nx->next;
                    if (nx == 0) {
                        if (!(0x4000 - pos < sz)) return cand;
                        goto next;
                    }
                }
                return cand;
            }
        }
    next:
        prev = cur;
        cur = cur->next;
    } while (cur != 0);
    if (0x4000 - (prev->pos + prev->size) >= a0->size) return 1;
    return -1;
}
