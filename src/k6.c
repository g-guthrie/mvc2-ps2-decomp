typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_0040EE88(void);
void func_003FF2A0(void) { func_0040EE88(); }
extern void func_0011EB60(void *);
extern char D_004BE838[];
void func_0040EA28(void) { func_0011EB60(D_004BE838); }
extern void func_0040D5A0(void *);
extern char D_004BE2F8[];
typedef struct S1 { char pad[0x24]; s32 v; } S1;
s32 func_0040D1A8(S1 *p) {
    if (p == 0) { func_0040D5A0(D_004BE2F8); return -1; }
    return p->v;
}
extern void func_003FB128(void *);
extern char D_004BB420[];
typedef struct S2 { char pad[0x14]; s32 v; } S2;
s32 func_003FD420(S2 *p) {
    if (p == 0) { func_003FB128(D_004BB420); return -3; }
    return p->v;
}
extern s32 func_004000B8(s32);
extern char D_004BC158[];
typedef struct S3 { char pad0[1]; signed char b; char pad1[2]; s32 v; } S3;
s32 func_00401FD8(S3 *p) {
    if (p == 0) { func_003FB128(D_004BC158); return -1; }
    if (p->b >= 2) return func_004000B8(p->v);
    return 0;
}
#include "HtciFileRequest.h"
extern HtciFileRequest D_00489220[13];
s32 func_0040AF88(void) {
    s32 i; signed char *p = (signed char *)D_00489220;
    for (i = 0; i < 13; i++, p += 0x30) if (p[0] == 1 && p[2] == 2) return 1;
    return 0;
}
extern void func_00409708(s32, void *, s32, void *, s32);
typedef struct V4 { s32 w[4]; } V4;
extern V4 D_00632100;
extern s32 D_00632240[];
extern s32 D_00632140[];
V4 *func_00410920(s32 a) {
    D_00632140[0] = a;
    func_00409708(0x24, D_00632140, 1, D_00632240, 4);
    D_00632100.w[0] = D_00632240[0]; D_00632100.w[1] = D_00632240[1];
    D_00632100.w[2] = D_00632240[2]; D_00632100.w[3] = D_00632240[3];
    return &D_00632100;
}
extern void func_00405DC8(void *);
extern char D_004BCA90[], D_004BCAB0[];
typedef struct VT3 { char pad[0x1C]; s32 (*f)(void *); } VT3;
typedef struct S5 { VT3 *vt; void *arg; } S5;
s32 func_00406890(S5 *p) {
    s32 r;
    if (p == 0) { func_00405DC8(D_004BCA90); return 0; }
    if (p->vt->f) r = p->vt->f(p->arg);
    else { r = 0; func_00405DC8(D_004BCAB0); }
    return r;
}
extern s32 func_00400068(s32);
extern void func_003FFF30(s32, s32);
extern void func_004007A0(s32, s32);
extern void func_00400658(s32, s32);
typedef struct S6 { char pad0[4]; s32 a; s32 b; char pad1[0x60]; signed char f; } S6;
void func_004031A8(S6 *p) {
    s32 s0 = p->b;
    s32 v = func_00400068(p->a);
    if (p->f == 0) { func_003FFF30(p->a, -1); func_004007A0(p->b, 0x7FFFFFFF); }
    else func_00400658(s0, v / 2048);
}
extern void func_004075B8(void *, s32);
extern void func_00405FC0(void *, void *, s32);
extern void func_004062F8(void *);
extern void func_0040CA70(s32);
extern void func_0040CAA0(s32);
extern void func_00400EF0(void);
extern void func_0040AEE8(void);
extern char D_004C23C0[];
typedef struct S7 { s32 a; s32 b; } S7;
void func_00400F08(S7 *p) {
    func_004075B8((void *)func_00400EF0, 0);
    func_00405FC0(D_004C23C0, (void *)func_0040AEE8, 0);
    func_004062F8(D_004C23C0);
    if (p) { func_0040CA70(p->b); func_0040CAA0(p->a); }
    else { func_0040CA70(0); func_0040CAA0(0); }
}
extern u8 D_004959D8[];
void func_00410540(s32 v, u8 *o) {
    o[6] = D_004959D8[v & 0xF]; v >>= 4;
    o[5] = D_004959D8[v & 0xF]; v >>= 4;
    o[4] = D_004959D8[v & 0xF]; v >>= 4;
    o[3] = D_004959D8[v & 0xF]; v >>= 4;
    o[2] = D_004959D8[v & 0xF]; v >>= 4;
    o[1] = D_004959D8[v & 0xF]; v >>= 4;
    o[0] = D_004959D8[v & 0xF];
}
extern void func_0040C7C0(void *, s32 *);
extern void func_0040BF58(void *, void *);
extern void func_0040B098(void);
extern void func_00408698(void);
extern void func_004086B8(void);
extern s32 func_00107E90(void *, s32);
extern void func_00108118(s32);
extern char D_00489490[];
s32 func_0040B3B8(void *a) {
    s32 st[2];
    s32 r;
    if (a == 0) return 0;
    func_0040C7C0(a, st);
    if (st[1] == 0) {
        func_0040BF58(a, D_00489490);
        func_0040B098();
        func_00408698();
        r = func_00107E90(D_00489490, 1);
        func_004086B8();
        if (r < 0) return 0;
        func_00408698();
        func_00108118(r);
        func_004086B8();
    }
    return 1;
}
