typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34]; f32 f34, f38, f3c; u8 pad1[0x1C]; f32 f5c, f60, f64, f68, f6c;
} S298830;

void func_00298830(S298830 *p)
{
    extern void func_00185490();
    extern void func_00298390();
    extern void func_00175700();
    extern void func_001757E0();
    func_00185490(p);
    func_00298390(p);
    *((u8 *)p + 0x209) = 2;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if ((double)(p->f68 * p->f5c) < 0.0
        && !((*(s8 *)((u8 *)p + 0x211)) & (1 << *((u8 *)p + 0x1E6)))) {
        func_00175700(p);
    } else {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        func_001757E0(p, 0x15, 0x16);
    }
}

