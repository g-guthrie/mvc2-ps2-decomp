#include "stream_group_types.h"
typedef unsigned long long u64;

typedef struct { u8 prefix[4]; void *engine; } RuntimeStreamHandle;
extern s32 func_003F8130(void *);
s32 func_003FFF90(void *object) { RuntimeStreamHandle *p = (RuntimeStreamHandle *)object; return func_003F8130(p->engine); }

extern char D_004BE8D8[];
extern void func_0011EB60(void *);
s32 func_0040EE60(void) { func_0011EB60(D_004BE8D8); return 0; }

struct H;
extern void func_003F83C0(struct H *);
void func_003FF658(StreamGroup *p) { func_003F83C0(p->engine); p->lifecycle = 0; }



extern char D_004BB340[];
extern s32 func_003FB128(void *);
extern s32 func_003FCF88(s32, s32, s32);
s32 func_003FD0F8(s32 a, s32 b, s32 c) {
    if (c & 0x3F) { func_003FB128(D_004BB340); return -3; }
    return func_003FCF88(a, b, c);
}

typedef struct { s32 cls, sign, exp; u32 mant; } Unp;
void func_00118F48(u32 *src, Unp *o) {
    u32 b = *src;
    u32 e = (b >> 23) & 0xFF;
    u32 f = b & 0x7FFFFF;
    o->sign = b >> 31;
    if (e == 0) { o->cls = 2; return; }
    o->exp = e - 0x7F;
    o->cls = 3;
    o->mant = (f << 7) | 0x40000000;
}

extern char D_004BCA58[], D_004BCA78[];
extern void func_00405DC8(void *);
extern s32 func_00406678(void *);
typedef struct { char pad[0x14]; void (*fn)(s32); } Ops2;
typedef struct { Ops2 *ops; s32 arg; } Obj2;
s32 func_00406818(Obj2 *p) {
    if (p == 0) { func_00405DC8(D_004BCA58); return; }
    if (p->ops->fn) { p->ops->fn(p->arg); return func_00406678(p); }
    else { func_00405DC8(D_004BCA78); __asm__ volatile(""); }
}

s32 func_003F98C8(char *p, s32 n, short *out) {
    s32 best = 0x7FFFFFFF;
    s32 i = 0;
    s32 m = 0x80;
    n--;
    for (i = 0; i < n; i += 2) { if (*(short *)(p + i) == m) { if (i < best) best = i; break; } }
    if (best != 0x7FFFFFFF) { *out = best; return 0; }
    *out = 0;
    return -1;
}

extern char D_004C2290[];
extern s32 func_0011D6A8(void *, void *, s32);
s32 func_003F9948(u8 *p, s32 len, short *out) {
    s32 n, end, off;
    if (len < 0x10) return 0;
    if ((p[1] | (p[0] << 8)) != 0x8000) return 0;
    n = (p[2] << 8) | p[3];
    end = n + 4; off = n - 2;
    if (len <= 0x7FFF) return 0;
    if (func_0011D6A8(p + off, D_004C2290, 6) != 0) return 0;
    if (out) *out = end;
    return 1;
}
