typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a, b, c; } E12;
typedef struct { u8 pad[0x18]; E12 tab[1]; } G95;
extern G95 *D_004C2794;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[0x50];
    union { struct { f32 f50, f54, f58; }; V3 v50; };
    u8 p1[0x74 - 0x5C];
    f32 f74, f78, f7c, f80;
    u8 p2[0x118 - 0x84];
    f32 f118;
    u8 p3[0x298 - 0x11C];
    V3 v298;
    u8 p4[0x428 - 0x2A4];
    s32 w428[2];
    f32 f430;
} P95;
extern void (*D_00448D00[])(u8 *);
extern u8 D_00446D00[];
extern u8 D_00446DD0[], D_00446DD1[], D_00446DD2[], D_00446DD3[];
extern s8 D_004470D0[];

void func_00180A30(u8 *p) {
    P95 *q = (P95 *)p;
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    extern void func_00190C10(u8 *);
    extern void func_00180DC0(u8 *);
    extern void func_00180F20(u8 *);
    u8 k;
    func_0011D8F8(p + 0x1E4, 0, 0x238);
    p[0x1B5] = 0;
    p[0x1B2] = 0;
    p[0x1B4] = 0;
    *(u16 *)(p + 0x1C0) = 0;
    *(u16 *)(p + 0x1C2) = 0;
    *(s8 *)(p + 0x1B0) = -0x80;
    *(s8 *)(p + 0x1B1) = -0x80;
    p[0x201] = 0;
    p[0x1E6] = *(s8 *)(p + 0x140);
    *(s32 *)(p + 0x220) = D_004C2794->tab[p[2] ^ 1].a;
    p[1] = *(s8 *)(p + 0x540);
    p[0x25] = *(s8 *)(p + 0x541);
    D_00448D00[p[1]](p);
    func_0015E630(p);
    p[0x21B] = D_00446D00[p[1]];
    func_00190C10(p);
    p[0x14C] = D_00446DD0[p[1] * 4];
    p[0x14D] = D_00446DD1[p[1] * 4];
    p[0x14E] = D_00446DD2[p[1] * 4];
    p[0x14F] = D_00446DD3[p[1] * 4];
    p[0x339] = D_004470D0[p[1]] << 1;
    p[0x1F5] = 0x50;
    k = (p[1] >= 0x20) ? 1 : 0;
    q->w428[k ^ 1] = 0;
    q->w428[k] = 1 << (p[1] - (k << 5));
    q->f50 = 1.0f;
    q->f54 = 1.0f;
    q->f58 = 1.0f;
    p[0x216] &= 0x7F;
    if (p[1] >= 0x18 && p[1] < 0x1B) {
        q->f50 /= 1.6666666269302368f;
        q->f54 /= 2.142857074737549f;
        if (p[1] == 0x1A) {
            q->f50 *= 4.0f;
            q->f54 *= 4.0f;
        } else {
            q->f50 *= 2.0f;
            q->f54 *= 2.0f;
        }
    }
    q->f118 = 1.0f;
    q->v298 = q->v50;
    q->f80 = 1.0f;
    q->f7c = 1.0f;
    q->f78 = 1.0f;
    q->f74 = 1.0f;
    if ((*(u32 *)(p + 0x42C) & 0x1400) != 0) {
        p[0x217] = 1;
        *(f32 *)(p + 0x21C) = q->f430;
    } else {
        p[0x217] = 0;
    }
    func_00180DC0(p);
    func_00180F20(p);
}
