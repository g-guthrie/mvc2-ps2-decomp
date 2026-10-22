typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef struct { s32 val; char name[12]; } Ent;
extern Ent D_0062FB48[32];
extern u8 D_004BC928[];
extern s32 func_00120288(s32, void *, s32);
extern s32 func_0011FFA0(s32);

void func_00406220(s32 a) {
    extern void func_00405DC8(u8 *);
    u32 i;
    s32 r;
    if (a == 0) {
        func_00405DC8(D_004BC928);
        return;
    }
    r = func_0011FFA0(a);
    for (i = 0; i < 32; i++)
        if (!func_00120288(a, D_0062FB48[i].name, r)) {
            D_0062FB48[i].name[0] = 0;
            return;
        }
}

typedef unsigned long long u64;
typedef signed long long s64;

typedef struct { u8 p0[2]; s8 b2; u8 p3[5]; u64 f8; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; s32 f2c; } IO;
extern u8 D_004BE080[];
extern u8 D_004BE098[];
extern u8 D_004BE0B8[];
extern s32 D_004895D0;
extern void func_0040AF58(IO *, u8 *);
extern s32 func_0040AF88(IO *);
extern s32 func_00407BF8(void);
extern void func_0040B1C0(IO *, s32);
extern s32 func_00407E10(s32, s32, s64, s64, s32);
extern void func_00408628(void);
extern void func_004084E8(void);
extern void func_00407C80(s32);

s32 func_0040BA28(IO *o, s32 n, s32 m) {
    s32 r;
    s32 k;
    s32 rem;
    u64 sz;
    if (o == 0) {
        func_0040AF58(o, D_004BE080);
        return 0;
    }
    if (n < 0) {
        func_0040AF58(o, D_004BE098);
        return 0;
    }
    if (m == 0) {
        func_0040AF58(o, D_004BE0B8);
        return 0;
    }
    if (func_0040AF88(o) == 1) return 0;
    if (o->b2 == 2) return 0;
    if (n == 0) {
        o->b2 = 1;
        return 0;
    }
    r = func_00407BF8();
    o->f2c = r;
    if (r == 0) return 0;
    rem = o->f10 - o->f1c;
    o->f20 = m;
    k = (n < rem) ? n : rem;
    o->f24 = k;
    sz = (u64)(n << 11);
    if (o->f8 < sz) sz = o->f8;
    func_0040B1C0(o, k);
    if (func_00407E10(o->f2c, o->f18, o->f1c, sz, m) == 0) return 0;
    if (D_004895D0 == 1) {
        func_00408628();
        func_004084E8();
        o->f1c = o->f1c + o->f24;
        func_00407C80(o->f2c);
        o->f2c = 0;
        o->b2 = 1;
        o->f28 = o->f24;
    } else {
        o->b2 = 2;
        o->f28 = 0;
    }
    o->f14 = 0;
    return o->f24;
}
