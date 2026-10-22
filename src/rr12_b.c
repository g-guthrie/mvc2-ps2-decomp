typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96: ./tryee.sh src/rr12_b.c sn */
typedef struct VT { u8 _p[0x24]; s32 (*f24)(void *, s32); } VT;
typedef struct OB { VT *vt; } OB;
typedef struct P {
    u8 _p0;
    s8 b1;
    u8 _p1[2];
    s32 w4;
    s32 w8;
    u8 _p2[8];
    OB *w14;
    u8 _p3[0x20];
    s32 w38;
    u8 _p4[0x24];
    s16 h60;
    u8 _p5[2];
    s32 w64;
    u16 h68;
    u16 h6A;
    u8 _p6;
    s8 b6D;
    u8 _p7[4];
    s8 b72;
} P;

void func_00403E20(P *p)
{
    extern s32 func_003FF5C8(s32);
    extern s32 func_003FFEC8(s32);
    extern void func_00401868(P *);
    extern void func_00403D30(P *);
    extern s32 func_00400650(s32);
    s32 st;
    s32 r;
    s32 v;
    u32 t;
    st = p->b1;
    if (st == 3 && p->b72 == 0 && func_003FF5C8(p->w4) != st) {
        r = func_003FFEC8(p->w4);
        if (p->w64 == r) {
            p->h68 = p->h68 + 1;
            if (p->w38 * 5 < (s16)p->h68)
                p->h60 = -2;
        } else {
            p->h68 = 0;
        }
        p->w64 = r;
        if (p->h60 != 0) {
            t = (u8)p->b6D;
            if ((u32)(t - 1) < 2) {
                func_00401868(p);
                t = (u8)p->b6D;
            }
            if (t != 0) {
                p->h60 = 0;
                p->h68 = 0;
            }
        }
    } else {
        p->h68 = 0;
    }
    if ((u32)(st - 1) < 3 && p->b72 == 0 && func_003FF5C8(p->w4) != 3) {
        v = p->w14 ? p->w14->vt->f24(p->w14, 1) : 0;
        if (v < 0x40) {
            p->h6A = p->h6A + 1;
            if (st == 3) {
                if (p->w38 * 5 < (s16)p->h6A)
                    p->h60 = -1;
            } else {
                if (p->w38 * 20 < (s16)p->h6A)
                    p->h60 = -1;
            }
            if (p->h60 != 0) {
                if (p->b6D == 1)
                    func_00401868(p);
                else if (p->b6D == 2)
                    func_00403D30(p);
                if ((u8)p->b6D != 0) {
                    p->h60 = 0;
                    p->h6A = 0;
                }
            }
        } else {
            p->h6A = 0;
        }
    } else {
        p->h6A = 0;
    }
    if (p->w8 != 0 && func_00400650(p->w8) == 4) {
        if (p->b6D == 1)
            func_00401868(p);
        else if (p->b6D == 2)
            func_00403D30(p);
        if ((u8)p->b6D != 0) {
            p->h60 = 0;
            p->h6A = 0;
        }
    }
}
