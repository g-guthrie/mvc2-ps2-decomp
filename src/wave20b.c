typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00175700();
extern void func_00186A20();

void func_002D3A10(u8 *p) {
    float f;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        t = p[6];
        p[6] = t + 1;
        *(float *)(p + 104) = 0.0f;
        if (p[486] != 0) {
            *(float *)(p + 92) = 5.0f;
        } else {
            *(float *)(p + 92) = -5.0f;
        }
        *(float *)(p + 96) = 12.857142f;
        *(float *)(p + 108) = -0.9375f;
        func_00186A20(p);
    }
}

extern s32 func_00175670();
extern void func_001D7060();

void func_001D6FD0(u8 *p, u8 *q) {
    s8 r;
    if (*(s8 *)(q + 435) != 0 || (r = func_00175670(p)) < 0) {
        func_001D7060(p, q);
    } else {
        *(float *)(p + 56) += 1.0714285f;
    }
}

extern void func_001757E0();
extern void func_00362CA0();

void func_00362C20(u8 *p, u8 *q) {
    u32 t = p[6];
    p[6] = t + 1;
    if (*(s16 *)(p + 320) == 0) {
        *(float *)(p + 92) = -7.9166665f;
    } else {
        *(float *)(p + 92) = 7.9166665f;
    }
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 23, 13);
    func_00362CA0(p, q);
}

extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0();

void func_002329F0(u8 *p) {
    float v[4];
    if ((*(u16 *)(p + 526) & 0x800) != 0) {
        p[486] = *(s8 *)(p + 486) ^ 1;
        *(s16 *)(p + 320) = *(s16 *)(p + 320) ^ 1;
    }
    func_001266A0(p, 5, 5);
    p[436] = 10;
    p[6] = 0;
    v[0] = -106.666664f;
    v[1] = 137.14285f;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 15, 1);
}
