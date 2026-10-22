typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct E13c E13c;
struct E13c {
    u8 p0[2];
    s16 h2;
    u8 p4[8];
    E13c *w0C;
    E13c *w10;
    u8 p14[0x40];
    u8 s54[0xC0];
    s32 w114;
    s32 w118;
    f32 f11C[10];
    s32 w144[0x10];
    s32 w184;
    s32 w188;
    s16 h18C;
    s16 h18E;
};

typedef struct { u8 pad[2]; s16 cnt; } H13c;

extern H13c *func_003DD030(s32);
extern void func_003F38A0(u8 *);
extern void func_003DEAF0(E13c *, H13c *, s32);
extern void func_003DD260(u8 *);
extern void func_003F1650(E13c *, u8 *);
extern void func_003F4280(u8 *, u8 *);

s32 func_003DE890(E13c *p, s32 a1, H13c *a2)
{
    s32 i;
    s32 n;
    H13c *h;
    s32 j;
    s32 k;
    u8 buf[0x40];
    E13c tmp;

    h = func_003DD030(a1);
    n = h->cnt;
    for (i = 0; i < n; i++) {
        p[i].h2 = n;
        p[i].h18C = -1;
        p[i].h18E = -1;
        p[i].w0C = 0;
        p[i].w10 = 0;
        p[i].w114 = 0;
        p[i].w118 = 0;
        p[i].w184 = 0;
        p[i].w188 = 0;
        func_003F38A0(p[i].s54);
    }
    for (i = 0; i < n; i++) {
        func_003DEAF0(&p[i], h, i);
    }
    for (i = 0; i < n; i++) {
        if (p[i].h18E != -1) {
            p[i].w10 = &p[p[i].h18E];
        }
        if (p[i].h18C != -1) {
            p[i].w0C = &p[p[i].h18C];
        }
    }
    func_003DD260(buf);
    func_003F1650(p, buf);
    if (a2 != 0) {
        a2 = func_003DD030((s32)a2);
        for (i = 0; i < n; i++) {
            func_003DEAF0(&tmp, a2, i);
            for (j = 0; j < 10; j++) {
                p[i].f11C[j] = tmp.f11C[j];
            }
            func_003F4280(p[i].s54, tmp.s54);
        }
    }
    return 1;
}
