typedef struct StreamGroup StreamGroup;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define GET_FLOAT_WORD(i, d) do { union { float f; u32 w; } gf_u; gf_u.f = (d); (i) = gf_u.w; } while (0)
#define SET_FLOAT_WORD(d, i) do { union { float f; u32 w; } sf_u; sf_u.w = (i); (d) = sf_u.f; } while (0)

float func_00116F60(float x, float y) {
    u32 ix, iy;
    GET_FLOAT_WORD(ix, x);
    GET_FLOAT_WORD(iy, y);
    SET_FLOAT_WORD(x, (ix & 0x7FFFFFFF) | (iy & 0x80000000));
    return x;
}

typedef struct Obj Obj;
typedef struct { u8 pad[0x14]; void (*fn)(Obj *); } VT;
struct Obj { VT *vt; };

extern void func_003F9630();
extern void func_003F9660();
extern void func_003FF148(s8 *, s32);
extern void func_003FF160();
extern void func_003FF658(StreamGroup *);
extern void func_00400740();
extern void func_00400658();
extern void func_004006E8();
extern void func_00401640();

void func_00403D30(u8 *p) {
    Obj **q;
    s32 i;
    func_003F9630();
    func_003FF148(*(s8 **)(p + 0xC), 0);
    func_003FF160(*(s32 *)(p + 0xC), 0);
    func_003FF658(*(StreamGroup **)(p + 4));
    func_003F9660();
    if (*(s32 *)(p + 8) != 0) {
        func_00400740(*(s32 *)(p + 8));
        (*(Obj **)(p + 0x14))->vt->fn(*(Obj **)(p + 0x14));
    }
    func_003F9630();
    i = 0;
    if (*(s8 *)(p + 3) > 0) {
        q = (Obj **)(p + 0x18);
        do {
            Obj *o = *q;
            q++;
            o->vt->fn(o);
            i++;
        } while (i < *(s8 *)(p + 3));
    }
    if (*(s32 *)(p + 8) != 0) {
        func_00400658(*(s32 *)(p + 8), 0);
        func_004006E8(*(s32 *)(p + 8));
    }
    func_00401640(p, *(s32 *)(p + 0x14));
    func_003F9660();
}

typedef struct VT2 VT2;
typedef struct Inner { VT2 *vt; } Inner;
struct VT2 { u8 pad[0x20]; void (*fn)(Inner *, s32, void *); };
typedef struct { s32 pad; Inner *in; } Obj2;
extern void func_0040EFE0();
extern void func_0040EFF8();

void func_00410C18(s32 a0, u8 *a1) {
    u8 *p;
    u8 *q;
    s32 n;
    if (a1 == 0) {
        for (;;) {
            __asm__ volatile("nop");
        }
    }
    n = *(s32 *)a1;
    func_0040EFE0();
    if (n > 0) {
        p = a1;
        do {
            q = p + 0x10;
            if (*(s8 *)q == 0) {
                Inner *in = (*(Obj2 **)(p + 0x14))->in;
                in->vt->fn(in, *(s8 *)(p + 0x11), p + 0x18);
            }
            p = q;
            n--;
        } while (n != 0);
    }
    func_0040EFF8();
}
