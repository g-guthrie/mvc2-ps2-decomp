typedef struct StreamGroup StreamGroup;
typedef signed int s32;
#include "cri_sj_ring_buffer_types.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;

extern void func_0040ED20(void *, s32);
void func_003FF228(void *group, s32 count) { func_0040ED20(group, count); }

extern s32 D_0048831C;
struct S24;
extern int func_0010EC08(struct S24 *, u8 *, int);
int func_004098D8(void *a, u8 *b) { return func_0010EC08((struct S24 *)a, b, D_0048831C); }

extern void func_0011EB60(void *);
extern char D_004BE950[];
s32 func_0040EF00(void) { func_0011EB60(D_004BE950); return 0; }

extern s32 D_00632140;
extern void func_00409708(s32, void *, s32, s32, s32);
void func_004108F0(s32 a) { D_00632140 = a; func_00409708(0x23, &D_00632140, 1, 0, 0); }

typedef struct { s32 pad0; s32 state; s32 h; char pad[0x80]; s32 z; } Q1;
extern void func_004044B0(s32);
void func_003F83F0(Q1 *p) { if (p->state == 3) { func_004044B0(p->h); p->z = 0; p->state = 0; } }

extern s32 D_0043BB60, D_0043BB64, D_00438990;
extern void func_00103E00(s32);
void func_0011DA38(void) { if (--D_0043BB64 == 0) { D_0043BB60 = -1; func_00103E00(D_00438990); } }

extern u32 func_0011FFA0(char *);
s32 func_0040BE90(char *s) { u32 n = func_0011FFA0(s); u32 i; if (n > 0x10) n = 0x10; for (i = 0; i < n; i++) if (s[i] == 0x3A) return 1; return 0; }


struct VO;
typedef struct VT { char pad[0xC]; void (*fn)(struct VO *); } VT;
typedef struct VO { VT *vt; } VO;
typedef struct { s8 a; s8 b1; s8 b2; s8 pad; StreamGroup *w4; s32 w8; s32 wc; s32 w10; VO *obj; s32 w18; } R2;
extern void func_003F9630(R2 *);
extern void func_003F9660(void);
extern void func_003FF148(s8 *, s32);
extern void func_003FF160(s32, s32);
extern void func_0040EA00(s32, s32);
extern void func_003FF658(StreamGroup *);
void func_004017E0(void *owner) {
    R2 *p = owner;
    func_003F9630(p);
    func_003FF148((s8 *)p->wc, 0);
    func_003FF160(p->wc, 0);
    func_0040EA00(p->wc, 1);
    func_003FF658(p->w4);
    if (p->b2 == 2 && p->obj != 0) { p->obj->vt->fn(p->obj); }
    p->obj = 0;
    p->b1 = 0;
    func_003F9660();
}

typedef struct { s32 x; s32 n; } R3;
typedef struct { char pad[0x1C]; void (*cb)(s32, s32); s32 arg; } O3;
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
void func_0040F2E8(SJ_OBJ *object, s32 mode, SJCK *chunk) {
    O3 *o = (O3 *)object;
    R3 *r = (R3 *)chunk;
    if (r->n > 0 && r->x != 0) {
        func_0040EFE0();
        if (mode == 0) {
        } else if (mode == 1) {
        } else {
            r->n = 0;
            r->x = 0;
            if (o->cb) o->cb(o->arg, -3);
        }
        func_0040EFF8();
    }
}

