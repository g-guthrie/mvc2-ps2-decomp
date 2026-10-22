typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w20b2_d.c */
typedef struct {
    u8 pad0[6]; u8 b6; u8 b7; u8 pad8[0x38 - 8]; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x140 - 0x70]; s16 h140; u8 pad142[0x151 - 0x142]; s8 b151;
    u8 pad152[0x1FC - 0x152]; u8 b1fc;
    u8 pad1fd[0x430 - 0x1FD]; f32 f430;
} P_d;

void func_0029C840(P_d *p) {
    extern s8 func_00175700(P_d *);
    extern void func_001843A0(P_d *);
    s32 b = p->b1fc;
    switch (b) {
    case 2:
        if (p->b6 == 0) {
            if (func_00175700(p) < 0) func_001843A0(p);
        } else {
            u32 t;
            s32 v;
            func_00175700(p);
            t = p->b7;
            if (t == 0) {
                if (p->b151 != 0) {
                    p->b7 = t + 1;
                    *(u32 *)&p->f5c = 0x41555555;
                    *(u32 *)&p->f68 = 0xBF480000;
                    if (p->h140 == 0) {
                        p->f5c = -p->f5c;
                        p->f68 = -p->f68;
                    }
                }
            } else {
                v = p->b151;
                if (v == 0) {
                    p->b6 = 0;
                    p->f38 = p->f430;
                    *(u32 *)&p->f5c = 0;
                    *(u32 *)&p->f60 = 0;
                    *(u32 *)&p->f68 = 0;
                    *(u32 *)&p->f6c = 0;
                } else if ((s8)v == 2) {
                    p->b151 = 1;
                    *(u32 *)&p->f60 = 0x41092492;
                    *(u32 *)&p->f6c = 0xBF892492;
                }
            }
        }
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
