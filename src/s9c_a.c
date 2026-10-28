typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00158280(u8 *p) {
    extern void func_003DAA40();
    f32 k;
    *(s16 *)(p + 0x1C) += 1;
    switch (p[4]) {
    case 0:
        k = 0.02500000037252903f;
        *(f32 *)(p + 0x50) += k;
        *(f32 *)(p + 0x58) += k;
        if (*(s16 *)(p + 0x1C) >= 0x10) p[4]++;
        break;
    }
    switch (p[5]) {
    case 0:
        *(f32 *)(p + 0x54) += 0.08299999684095383f;
        if (*(s16 *)(p + 0x1C) >= 6) p[5]++;
        break;
    case 1:
        *(f32 *)(p + 0x54) -= 0.035999998450279236f;
        break;
    }
    switch (p[6]) {
    case 0:
        k = 0.25f;
        *(f32 *)(p + 0x74) += k;
        *(f32 *)(p + 0x78) += k;
        *(f32 *)(p + 0x7C) += k;
        *(f32 *)(p + 0x80) += k;
        if (*(s16 *)(p + 0x1C) >= 4) p[6]++;
        break;
    case 1:
        if (*(s16 *)(p + 0x1C) >= 10) p[6]++;
        break;
    case 2:
        k = 0.10000000149011612f;
        *(f32 *)(p + 0x74) -= k;
        *(f32 *)(p + 0x78) -= k;
        *(f32 *)(p + 0x7C) -= k;
        *(f32 *)(p + 0x80) -= k;
        break;
    }
    if (*(s16 *)(p + 0x1C) > 0x14) { func_003DAA40(); return; }
}

typedef struct {
    u8 pad0[4];
    u8 b4, b5, b6;
    u8 pad7[0x15];
    s16 h1c;
    u8 pad1e[0x32];
    f32 f50, f54, f58;
    u8 pad5c[0x18];
    f32 f74, f78, f7c, f80;
} St158510;

void func_00158510(St158510 *p) {
    extern void func_003DAA40();
    f32 k;
    p->h1c++;
    switch (p->b4) {
    case 0:
        if (p->h1c >= 7) p->b4++;
        break;
    case 1:
        k = 0.04600000008940697f;
        p->f50 += k;
        p->f58 += k;
        break;
    }
    switch (p->b5) {
    case 0:
        p->f54 += 0.5709999799728394f;
        if (p->h1c >= 7) p->b5++;
        break;
    case 1:
        p->f54 -= 0.30799999833106995f;
        break;
    }
    switch (p->b6) {
    case 0:
        k = 0.1599999964237213f;
        p->f74 += k; p->f78 += k; p->f7c += k; p->f80 += k;
        if (p->h1c >= 6) p->b6++;
        break;
    case 1:
        k = 0.08299999684095383f;
        p->f74 -= k; p->f78 -= k; p->f7c -= k; p->f80 -= k;
        if (p->h1c >= 0x12) p->b6++;
        break;
    case 2:
        break;
    }
    if (p->h1c > 0x14) { func_003DAA40(); return; }
}
