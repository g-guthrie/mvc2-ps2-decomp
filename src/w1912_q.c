typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct E { void *f0; s32 f4; void *f8; s32 fc, f10; s32 f14; s32 f18; void *f1c; struct E *f20; } E;
extern E D_004908F8[];
extern void func_0040F010();
extern u8 D_004908C8[];
extern u8 D_004BE9D0[];


E *func_0040F0B8(s32 x, s32 y) {
    extern void func_0040F1D0(E *);
    s32 i;
    E *e;
    for (i = 0; i < 0x20; i++) {
        if (D_004908F8[i].f4 == 0) break;
    }
    if (i == 0x20) return 0;
    e = &D_004908F8[i];
    e->f4 = 1;
    e->f0 = D_004908C8;
    e->f14 = x;
    e->f18 = y;
    e->f8 = D_004BE9D0;
    e->f1c = (void *)func_0040F010;
    e->f20 = e;
    func_0040F1D0(e);
    return e;
}
