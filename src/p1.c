/* EE GCC 2.96 -O2 -G0 (tryee.sh src/p1.c sn): thunks, a soft-float double
   ratio, and one uncredited VU0 routine written as assembly. */
#include "stream_group_types.h"


/* VU0: convert four fixed-point (4.12) words to floats. */

/* Instruction-cache scrub over 0x1000 bytes using cache ops and mfc0 $28. */


/* A reserved but unused frame slot (volatile local) gives the 0x10 frame. */
void func_00411270(u16 *p) {
    volatile u32 pad;
    u16 v = p[1] + 1;
    p[1] = v;
}

typedef struct S3F6 S3F6;
extern void func_003F64D0(S3F6 *, s32);
void func_003FF600(StreamGroup *p, s32 v) {
    p->maximum_available = v;
    func_003F64D0((S3F6 *)p->engine, v);
}

extern char D_004BB448[];
extern void func_003FB128(char *s);
s32 func_003FD450(s32 *p) {
    if (p == 0) {
        func_003FB128(D_004BB448);
        return -3;
    }
    return p[3];
}

typedef struct {
    u8 pad0[2];
    s8 type;
    u8 pad3[0x25];
    s32 v;
} S40BCF8;
extern char D_004BE080[];
extern void func_0040AF58(S40BCF8 *p, char *s);
s32 func_0040BCF8(S40BCF8 *p) {
    if (p == 0) {
        func_0040AF58(p, D_004BE080);
        return 0;
    }
    if (p->type == 1) {
        return p->v << 11;
    }
    return 0;
}

/* Soft-float: (double)a / (double)b * 100.0 truncated to u32. */
extern s32 dptoli(double);
extern void func_00401B78(s32 x, s32 *a, s32 *b);
u32 func_00401E28(s32 x) {
    s32 a, b;
    func_00401B78(x, &a, &b);
    return (u32)dptoli((double)a / (double)b * 100.0);
}

typedef struct {
    s32 a;
    s32 b;
    s32 count;
} S3FD560;
extern S3FD560 *D_0047B180[];
extern char D_004BB530[];
extern char D_004BB558[];
s32 func_003FD560(u32 i, s32 n) {
    S3FD560 *p;
    if (i >= 0x100) {
        func_003FB128(D_004BB530);
        return -3;
    }
    p = D_0047B180[i];
    if (p == 0) {
        func_003FB128(D_004BB530);
        return -3;
    }
    if (n < 0 || n >= p->count) {
        func_003FB128(D_004BB558);
        return -3;
    }
    return 0;
}

typedef struct {
    s32 a;
    void (*cb)();
} S405FC0;
extern volatile s32 D_004872E0;
extern char D_004BC8B0[];
extern char D_004BC8D8[];
extern char D_004BC900[];
extern void func_00405D98();
extern void func_00405DC8(char *s);
extern S405FC0 *func_00406050(s32 a, s32 b);
void func_00405FC0(s32 a, s32 b) {
    S405FC0 *r;
    s32 x = D_004872E0;
    if (a == 0) {
        func_00405DC8(D_004BC8B0);
        return;
    }
    if (b == 0) {
        func_00405DC8(D_004BC8D8);
        return;
    }
    r = func_00406050(a, b);
    if (r == 0) {
        func_00405DC8(D_004BC900);
        return;
    }
    if (r->cb != 0) {
        r->cb(func_00405D98, 0);
    }
}

typedef struct {
    u8 p0[4];
    void *h;
    u8 p8[4];
    s32 c;
    s32 d;
    u8 p14[0x1C];
    s32 e;
} S3FCB20;
extern char D_004BB1F0[];
extern s32 func_003FD748(s32 a, s32 b, void *buf, s32 *x, s32 *y, s32 *z);
extern void *func_00400328(void *buf, s32 x, s32 y, s32 z, s32 w);
s32 func_003FCB20(S3FCB20 *p, s32 a, s32 b) {
    u8 buf[0x100];
    s32 x, y, z;
    if (func_003FD748(a, b, buf, &x, &y, &z) < 0) {
        return -3;
    }
    p->e = y;
    p->h = func_00400328(buf, x, y, z, 0);
    if (p->h == 0) {
        func_003FB128(D_004BB1F0);
        return -1;
    }
    p->c = z;
    p->d = z << 11;
    return 0;
}
