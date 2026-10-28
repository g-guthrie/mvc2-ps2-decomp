/* gr9: MW 3.0.3 -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F46C0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern u8 *func_001E7FD0(u8 *);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185770(u8 *, u8 *);
    u32 tmp[3];
    u8 *s0;

    *(s16 *)(p + 0x3F8) = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        p[6] = 4;
        func_001757E0(p, 0xF, 0x36);
        return;
    }
    {
        switch ((s32)(s0 = func_001E7FD0(p))) { case 0: break; default: {
            u32 t6 = p[6];
            p[6] = t6 + 1;
            p[7] = 0;
            func_001266A0(p, 5, 5);
            p[0x20B] = 0xCD;
            tmp[0] = 0xC312AAAA;
            tmp[1] = 0x432B6DB6;
            func_0015D010(p, tmp);
            func_001757E0(p, 0xF, 0x1D);
            func_00185770(p, s0);
        } }
    }
}
void func_0024E170(u8 *p) {
    extern s32 func_0018A580();
    extern void func_00186A60(u8 *, s32);
    u8 *c = p + 0x2B8;
    if (*(s8 *)(p + 0x2BD) != 0) {
        if (*(u16 *)(p + 0x354) & 0x100) {
            s32 t = c[6];
            c[6] = t + 1;
            if (t >= 100) {
                s8 e;
                c[6] = 0;
                e = c[0xE];
                if (e < 0x30) c[0xE] = e + 1;
            }
        } else {
            c[5] = 0;
            switch (func_0018A580(p)) { case 0: break; default: {
                p[5] = 0;
                if (p[0x20D] == 2) {
                    p[6] = 1;
                } else {
                    p[6] = 0;
                }
                p[7] = 0;
                p[0x1FD] = 4;
                p[0x1B7] = 1;
                func_00186A60(p, 0x15);
            } }
        }
    }
}
