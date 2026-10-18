typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct T {
    u8 pad0[1];
    u8 b1;
    u8 pad1[0x34 - 2];
    f32 f34;
    f32 f38;
    u8 pad3[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad4[0x6C - 0x64];
    f32 f6C;
    u8 pad5[0x1E6 - 0x70];
    u8 b1E6;
    u8 pad6[0x210 - 0x1E7];
    u8 b210;
    u8 pad7[3];
    u8 b214;
    u8 pad8[0x2B2 - 0x215];
    u8 b2B2;
} T;

extern s16 D_00447BD0[];
extern s16 D_00447AE0[];
extern s16 D_00448340[];
extern s16 D_00448250[];

void func_001820A0(T *p) {
    s16 *tbl;
    f32 a, b, c, t;
    if (p->b2B2 == 0) {
        p->b2B2 = 1;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        if (p->b210 == 0) {
            if (p->b214 == 0) {
                tbl = D_00447AE0;
            } else {
                tbl = D_00447BD0;
            }
        } else {
            if (p->b214 == 0) {
                tbl = D_00448250;
            } else {
                tbl = D_00448340;
            }
        }
        tbl += p->b1 * 2;
        a = 1.6666666269302368f * (f32)tbl[0] / 256.0f;
        b = 1.6666666269302368f * (f32)tbl[1] / 256.0f;
        c = p->f5C;
        if (p->b1E6 != 0) {
            t = a;
            a = -b;
            b = -t;
        }
        if (c < a) {
            c = a;
        }
        if (c > b) {
            c = b;
        }
        p->f5C = c;
        p->f34 += c;
    }
}
