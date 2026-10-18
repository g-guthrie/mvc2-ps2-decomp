typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

struct Q1DA { u8 pad[0x211]; s8 b211; };

typedef struct {
    u8 p0[5];
    u8 b5;
    u8 p6[0x20 - 6];
    u8 b20;
    u8 b21;
    u8 b22;
    u8 p23[0x34 - 0x23];
    f32 f34;
    f32 f38;
    u8 p3c[0x151 - 0x3C];
    s8 b151;
    u8 p152[0x15B - 0x152];
    u8 b15B;
} A1DA;

typedef struct {
    u8 p0[0x34];
    f32 f34;
    f32 f38;
    u8 p3c[0x151 - 0x3C];
    s8 b151;
    u8 p152[0x1DC - 0x152];
    struct Q1DA *w1DC;
    u8 p1E0[0x2B8 - 0x1E0];
    u8 b2B8[4];
    u8 b2BC;
} B1DA;

void func_001DAA00(A1DA *a, B1DA *b) {
    extern void func_00175910();
    extern void func_00178F20();
    extern void func_001757E0();
    u8 *c = (u8 *)b + 0x2B8;
    s32 x = b->b151;
    if (a->b151 != x) {
        func_00175910(a, 0x15, a->b21, x);
    }
    if (a->b22 != 0 && a->b15B != 0 && c[4] == 0) {
        struct Q1DA *q = b->w1DC;
        if (q->b211 != 0) {
            b->f34 = a->f34;
            b->f38 = a->f38;
        } else {
            a->f34 = b->f34;
            a->f38 = b->f38;
        }
        func_00178F20(a, q);
    } else {
        a->f34 = b->f34;
        a->f38 = b->f38;
    }
    if (c[4] != 0) {
        u32 t = a->b5;
        a->b5 = t + 1;
        switch (a->b20) {
        case 0: a->b21 = 7; break;
        case 1: a->b21 = 3; break;
        case 2: a->b21 = 0xB; break;
        case 3: a->b21 = 0x13; break;
        case 4: a->b21 = 0x11; break;
        case 5: a->b21 = 0x15; break;
        }
        func_001757E0(a, 0x15, a->b21);
    }
}
