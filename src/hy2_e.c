typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x20]; f32 f5C; f32 f60; u8 pad2[0x4]; f32 f68; f32 f6C; u8 pad3[0x3C0]; f32 f430; } PE;

void func_0022F380(u8 *p, u8 *q)
{
    extern s32 func_00175700();
    extern void func_00184540(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001863F0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_0035AEA0(u8 *, s32, s8);
    PE *d = (PE *)p;
    u32 *a, *c, *b, *e;
    s8 m;
    s8 r;
    r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] == 2) {
            d->f60 += 2.142857074737549f;
            d->f6C = -0.5357142686843872f;
            func_00184540(p);
            return;
        }
        func_001843A0(p);
    } else {
        func_001863F0(p);
        a = (u32 *)&d->f5C;
        b = (u32 *)&d->f68;
        c = (u32 *)&d->f60;
        e = (u32 *)&d->f6C;
        d->f34 += d->f5C;
        d->f5C += d->f68;
        d->f38 += d->f60;
        d->f60 += d->f6C;
        if (d->f38 < d->f430) {
            d->f38 = d->f430;
            *a = 0;
            *c = 0;
            *b = 0;
            *e = 0;
        }
        if (q[0xE] == 0) {
            if (*(s8 *)(p + 0x150) != 0) {
                p[0x150] = 0;
                if (*(s8 *)(p + 0x1B2) != 0) {
                    func_001E3210(p, 0x1E);
                } else {
                    if (p[0x20D] == 2) {
                        switch (p[0x1B7]) {
                        case 0:
                            m = 6;
                            break;
                        case 1:
                            m = 4;
                            break;
                        }
                    } else {
                        switch (p[0x1B7]) {
                        case 0:
                            m = 1;
                            break;
                        case 1:
                            m = 2;
                            break;
                        }
                    }
                    func_0035AEA0(q, 1, m);
                    func_001E3210(p, 0x1E);
                }
            }
        }
    }
}
