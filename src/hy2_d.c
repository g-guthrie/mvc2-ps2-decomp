typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x38]; f32 f38; u8 pad1[0x24]; f32 f60; u8 pad2[0x8]; f32 f6C; u8 pad3[0x3C0]; f32 f430; } PD;

void func_0020C520(u8 *p, u8 *q)
{
    extern s32 func_0020D2F0(u8 *, u8 *);
    extern void func_0020D250(u8 *, u8 *, s32);
    extern s32 func_00174170(void);
    extern void func_00154580(u8 *, u32 *, f32, f32);
    extern void func_00175700(u8 *);
    u32 h;
    u32 loc[3];
    if (func_0020D2F0(p, q) != 0) {
        func_0020D250(p, q, 5);
        return;
    }
    h = *(u16 *)(p + 0x35E);
    if ((h & 0x300) != 0) {
        p[0x1B7] = ((h & 0x100) != 0) ? 1 : 0;
        func_0020D250(p, q, 3);
    } else if ((h & 0x60) != 0) {
        if ((h & 0x1000) != 0) {
            func_0020D250(p, q, 6);
        } else {
            p[0x1B7] = ((h & 0x20) != 0) ? 1 : 0;
            func_0020D250(p, q, 4);
        }
        return;
    } else if ((h & 0x800) != 0) {
        func_0020D250(p, q, 7);
    } else if ((h & 0x1000) == 0) {
        func_0020D250(p, q, 0);
    } else {
        PD *d = (PD *)p;
        u32 *a, *b;
        d->f38 += d->f60;
        a = (u32 *)&d->f60;
        d->f60 += d->f6C;
        b = (u32 *)&d->f6C;
        if (d->f38 <= d->f430) {
            d->f38 = d->f430;
            *a = 0;
            *b = 0;
        }
        if ((func_00174170() & 0xF) == 0) {
            loc[0] = 0xC20C0000;
            loc[2] = 0;
            loc[1] = 0x43809249;
            func_00154580(p, loc, 1.0f, 1.0f);
            func_00154580(p, loc, 1.0f, 1.0f);
            func_00154580(p, loc, 1.0f, 1.0f);
        }
        func_00175700(p);
    }
}
