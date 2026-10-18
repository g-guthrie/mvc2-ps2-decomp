typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } E;
typedef struct {
    u8 pad0[0x5C];
    f32 f5c, f60, f64, f68, f6c, f70, f74;
    f32 f78, f7c, f80;
    u8 pad1[0xDC - 0x84];
    s32 fdc;
} P;

void func_001618E0(P *p) {
    extern u8 *D_004C2840;
    extern E D_004B3FB0[];
    s32 k;
    E *e = D_004B3FB0;
    k = *(s8 *)(D_004C2840 + 0x9C) & 0xF;
    if (k != 0) {
        e += k - 1;
        if (p->fdc == 0) {
            p->f5c = (e->x - p->f78) / 20.0f;
            p->f60 = (e->y - p->f7c) / 20.0f;
            p->f68 = (e->z - p->f80) / 20.0f;
            p->fdc = 20;
        }
    }
    if (p->fdc != 0) {
        p->fdc -= 1;
        p->f78 += p->f5c;
        p->f7c += p->f60;
        p->f80 += p->f68;
    }
}

s32 func_00334FA0(u8 *p) {
    extern s32 D_004C283C;
    extern void func_00335070();
    s16 h, c, t;
    f32 a, z;
    h = *(s16 *)(p + 0x1E);
    if (h > 7) {
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        p[6] = 2;
        func_00335070(p);
        return 0;
    }
    if (*(s16 *)(p + 0x1C) == 0) {
        t = h + 0x1B;
        if (t > 0x22) t = 0x22;
        *(s16 *)(p + 0xCC) = t;
        *(s32 *)(p + 0x84) = D_004C283C;
    }
    z = 0.0f;
    a = *(f32 *)(p + 0x74) - 0.0625f;
    *(f32 *)(p + 0x74) = a;
    if (a < z) *(f32 *)(p + 0x74) = z;
    c = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = c;
    if (c > 0) {
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    }
    return 0;
}
