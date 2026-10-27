#include "stream_group_types.h"
typedef long long s64;
extern void func_003F81B8(s32);
extern s32 func_003F8128(void *);
void func_00400008(s32 *p) { func_003F81B8(p[1]); }
s32 func_003FFF78(void *object) { return func_003F8128(*(void **)((u8 *)object + 4)); }
extern void func_00408628(void);
extern volatile s32 D_0048733C;
void func_00408760(s32 a) { func_00408628(); D_0048733C = a; }
extern void func_00105540(int);

extern void func_00102428();
s32 func_00102B50(u32 *p, s32 m) { if (m == 1) return (*p >> 8) & 1; func_00102428(); return 0; }
typedef struct VT { char pad[0x24]; s32 (*f24)(void *, int); } VT;
typedef struct Q1 { VT *vt; } Q1;
typedef struct P1 { s32 pad0; Q1 *q; s32 pad1[4]; s32 a; s32 b; } P1;
void func_00400CA0(P1 *p, Q1 *q) { s32 r; p->q = q; r = q->vt->f24(q, 0); p->a = r; p->b = r; }
extern s32 D_00632140[], D_00632240[];
extern s32 func_00409708(int, void *, int, void *, int);
s32 func_00410898(s32 a, s32 b, s32 c) { D_00632140[0] = a; D_00632140[1] = b; D_00632140[2] = c; func_00409708(0x22, D_00632140, 3, D_00632240, 1); return D_00632240[0]; }
extern void func_00405DC8(void *);
extern char D_004BCB70[], D_004BCB90[], D_004BD1D0[], D_004BD1F0[];
typedef struct { char pad[0x28]; void (*f28)(int); char pad2[0x38]; s32 (*f64)(int); } Ops6;
typedef struct { Ops6 *ops; int arg; } Obj6;
void func_00406A30(Obj6 *p) {
    if (p == 0) { func_00405DC8(D_004BCB70); return; }
    if (p->ops->f28) p->ops->f28(p->arg); else func_00405DC8(D_004BCB90);
}
s32 func_00407648(Obj6 *p) {
    s32 r = 0;
    if (p == 0) { func_00405DC8(D_004BD1D0); return 0; }
    if (p->ops->f64) r = p->ops->f64(p->arg); else func_00405DC8(D_004BD1F0);
    return r;
}
extern void func_003FFE20(StreamGroup *);
void func_003FFE60(void) {
    s32 i;
    StreamGroup *p = D_00484100;
    for (i = 15; i >= 0; i--, p++) { if (p->active == 1) func_003FFE20(p); }
}
typedef struct E138 { signed char st; char pad[0x137]; } E138;
extern E138 D_00479E00[];
E138 *func_003FC918(void) { s32 i; E138 *r = 0; for (i = 0; i < 16; i++) { if (D_00479E00[i].st == 0) { r = &D_00479E00[i]; break; } } return r; }
typedef struct S25 { char pad0; signed char b1; char pad2[2]; s32 f4; char pad8[0xC]; s32 f14; char pad18[8]; s32 f20; } S25;
extern s32 func_00400650(s32);
extern void func_00400B58(s32, s32 *);
extern void func_003FCC80(S25 *);
void func_003FD228(S25 *p) {
    s32 v[4];
    if (p->b1 == 2) {
        p->b1 = func_00400650(p->f4);
        func_00400B58(p->f4, v);
        p->f20 = v[0];
        if ((u8)(p->b1 - 3) < 2) { p->f14 += v[0]; func_003FCC80(p); }
    }
}
s32 func_004029D8(u16 *p, s32 n, s32 *out) { u16 v; if (n < 2) return 0; v = *p; if ((u16)((v << 8) | (v >> 8)) != 0x8001) return 0; *out = n; return 1; }
