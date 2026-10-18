typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct S1F3 S1F3;
struct S1F3 {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34, f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60, f64, f68, f6c;
    u8 pad70[0x1DC - 0x70];
    S1F3 *p1DC;
    u8 pad1E0[0x20B - 0x1E0];
    u8 b20B;
};

void func_001F36F0(S1F3 *p) {
    extern void func_00175700(S1F3 *);
    extern void func_0015D010(S1F3 *, u32 *, s32, s32);
    extern void func_001E3210(S1F3 *, s32);
    extern void func_001757E0(S1F3 *, s32, s32);
    extern void func_00185770(S1F3 *, S1F3 *);
    S1F3 *o;
    u32 v[4];
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    o = p->p1DC;
    if (o->f38 - p->f38 - 17.14285659790039f < -68.57142639160156f) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->b20B = 0xCA;
        v[0] = 0xC312AAAA;
        v[1] = 0x432B6DB6;
        func_0015D010(p, v, 0xCA, t + 1);
        func_001E3210(p, 5);
        func_001757E0(p, 0xF, 0x11);
        func_00185770(p, o);
    }
}
