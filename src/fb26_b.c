typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
extern u8 D_004F1F45, D_004F1F46;
typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad6[0x12]; u8 *q; s16 h1C; u8 pad1E[0x13C - 0x1E]; u8 b13C; } Pb;

void func_00328560(Pb *p)
{
    extern u8 func_00174240(Pb *);
    extern void func_00199460();
    extern void func_001C5390();
    extern void func_001E0CC0();
    extern void func_0015B200(u8 *, V3 *, s32, s32);
    u32 t;
    if (p->b5 == 0) {
        s16 v = p->h1C - 1;
        p->h1C = v;
        if (v != 0) {
            p->b13C = func_00174240(p);
        } else {
            u8 *q;
            u32 c;
            t = p->b5;
            p->b5 = t + 1;
            p->h1C = 0x3C;
            q = p->q;
            c = q[1];
            if (c == 5) {
                func_00199460();
                t = p->b4;
                p->b4 = t + 1;
            } else if (c == 0x1C || c == 0x1D) {
                func_001C5390();
                t = p->b4;
                p->b4 = t + 1;
            } else if (q[0x216] & 0x80) {
                V3 vec;
                vec = *(V3 *)(q + 0x34);
                vec.y = *(f32 *)(p->q + 0x430);
                func_0015B200(p->q, &vec, 1, 0x179);
                D_004F1F45 = 3;
                D_004F1F46 = 1;
                t = p->b4;
                p->b4 = t + 1;
            } else if (c == 0x3A) {
                func_001E0CC0(q, 0);
                t = p->b4;
                p->b4 = t + 1;
            }
        }
    } else {
        u8 r = func_00174240(p);
        p->b13C = r;
        if ((s8)r == 0) {
            t = p->b4;
            p->b4 = t + 1;
        } else {
            s16 v = p->h1C - 1;
            p->h1C = v;
            if (v == 0) {
                t = p->b4;
                p->b4 = t + 1;
            } else {
                p->b13C = *(s8 *)((u8 *)p + 0x1C) & 1;
            }
        }
    }
}
