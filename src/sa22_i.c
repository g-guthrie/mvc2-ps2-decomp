typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct S {
    u8 pad0[0x6];
    u8 b6;
    u8 pad7[0x2D];
    f32 f34;
    f32 f38;
    u8 pad3C[0x20];
    f32 f5C;
    f32 f60;
    u8 pad64[0x4];
    f32 f68;
    f32 f6C;
    u8 pad70[0xE1];
    s8 b151;
    u8 pad152[0x63];
    u8 b1B5;
    u8 pad1B6[0x12];
    struct S * x1C8;
    u8 pad1CC[0x10];
    struct S * x1DC;
    u8 pad1E0[0x6];
    u8 b1E6;
    u8 pad1E7[0x23];
    u8 b20A;
    u8 pad20B[0x2];
    u8 b20D;
    u8 pad20E[0x222];
    f32 f430;
} S;
void func_001ED520(S *p)
{
    extern s32 func_00175700();
    extern void func_001266A0();
    extern void func_001843A0();
    S *q;
    f32 lim;
    if ((p->b6 = 0) != 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f5C /= 8.0f;
        p->f60 /= 8.0f;
        p->f6C /= 8.0f;
        p->f68 /= 8.0f;
    } else {
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        if (p->f38 <= (lim = 66.66666412353516f + p->f430)) {
            p->f38 = lim;
        }
        if (p->b151 != 0) {
            p->b151 = 0;
            q = p->x1DC;
            q->x1C8 = p;
            q->b20A = 1;
            q->b20D = 2;
            func_001266A0(p, 0, 0);
            q->b1B5 = 0x22;
            q->b1E6 = p->b1E6;
        }
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
    }
}
