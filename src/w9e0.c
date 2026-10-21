#include "stream_group_types.h"

extern void func_00408628(s32);
extern volatile s32 D_00487334;
void func_00408700(s32 a)
{
    func_00408628(a);
    D_00487334 = a;
}

extern void func_0040D5A0(void *);
extern char D_004BE2F8[];
s32 func_0040D498(s32 *p)
{
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
        return -1;
    }
    return p[5];
}

extern void func_00103CE0(void *, void *);
extern void func_00103D10(void *);
void func_003FE120(void *p)
{
    s32 t[12];
    if (p != 0) {
        func_00103CE0(p, t);
        if (t[0] == 4 || t[0] == 12) {
            func_00103D10(p);
        }
    }
}

typedef struct { s32 a, b, c, d, e; } S5;
extern void func_003FE5D8(S5 *);
void func_003FEC50(S5 *p)
{
    S5 s;
    S5 *q;
    if (p != 0) {
        s.d = p->d;
        s.a = p->a;
        s.b = p->b;
        s.c = p->c;
        s.e = 25;
        q = &s;
    } else {
        q = 0;
    }
    func_003FE5D8(q);
}

extern void func_003F7D58(void *);
extern void func_003F9630(void);
extern void func_003F9660();
extern void *func_0011D8F8(void *, s32, u32);
void func_003FF568(s32 *object)
{
    StreamGroup *p = (StreamGroup *)object;
    if (p != 0) {
        if (p->engine != 0) func_003F7D58(p->engine);
        func_003F9630();
        func_0011D8F8(p, 0, sizeof(*p));
        func_003F9660();
    }
}

extern s8 D_00485880[];
extern void func_00404968(void *);
void func_00404AA8(void)
{
    s8 *p = D_00485880;
    s32 i = 3;
    do {
        if (*p == 1) {
            func_00404968(p);
        }
        i--;
        p += 0x1C0;
    } while (i >= 0);
}



extern s32 func_00108298(void *, s32, s32);
extern void func_0040B110(void *);
extern void func_00408698(void);
extern void func_004086B8(void);
s32 func_0040B618(void *p)
{
    s32 r;
    func_0040B110(p);
    func_00408698();
    r = func_00108298(p, 0, 0);
    func_004086B8();
    if (r < 0) {
        return 0;
    }
    func_0040B110(p);
    func_00408698();
    r = func_00108298(p, 0, 2);
    func_004086B8();
    if (r < 0) {
        r = 0;
    }
    return r;
}


extern s32 func_003F8318(void *);
extern void func_003FF930(void *);
extern void func_003F88E0(void *);
extern void func_003FFB08(void *);
extern void func_003FFCF8(StreamGroup *);
void func_003FFD88(StreamGroup *p)
{
    u8 *s = (u8 *)p->engine;
    s32 h;
    if (func_003F8318(s) == 0) {
        func_003FF930(p);
    }
    func_003F88E0(s);
    if (func_003F8318(s) == 3) {
        func_003FFB08(p);
    }
    h = *(s16 *)(s + 0x98);
    if (h == 10 || h == 20) {
        func_003FFCF8(p);
        return;
    }
}



typedef struct {
    u8 *p;
    s32 r;
    s32 w;
    s16 flags;
    s16 file;
    u8 *base;
    s32 size;
    u8 pad[0x54 - 0x18];
    void *data;
} FileX;
extern s32 func_001209B8(FileX *, char *, void *);
s32 func_0011F8B0(void *reent, char *buf, char *fmt, ...)
{
    FileX f;
    s32 ret;
    __builtin_va_list ap;
    __builtin_stdarg_start(ap, fmt);
    f.flags = 0x208;
    f.p = (u8 *)buf;
    f.base = (u8 *)buf;
    f.w = 0x7FFFFFFF;
    f.size = 0x7FFFFFFF;
    f.data = reent;
    ret = func_001209B8(&f, fmt, ap);
    *f.p = 0;
    return ret;
}
