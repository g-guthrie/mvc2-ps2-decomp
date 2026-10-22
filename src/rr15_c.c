typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[0x24];
    s8 b24;
    u8 p1[0xF];
    f32 f34;
    f32 f38;
    u8 p2[0xC];
    s32 i48;
    u8 p3[0xF4];
    s16 h140;
    u8 p4[0x1E];
    s8 b160;
    u8 p5[7];
    u8 b168;
    u8 p6;
    s8 b16A;
    u8 p7[0xA6];
    s8 b211;
} OB;

typedef struct {
    s16 x;
    s16 y;
    u8 b4;
    u8 b5;
    s8 b6;
    u8 b7;
} TB;

void func_00178F20(u8 *actor, u8 *owner) {
    extern void func_001823C0(OB *);
    extern void func_001757E0(OB *, s32, s32);
    extern void func_00178EB0(OB *);
    extern s32 fptosi(f32);
    TB *t;
    s8 *k;
    OB *b = (OB *)owner;
    OB *a = (OB *)actor;
    k = &a->b160;
    t = (TB *)(*(s32 *)((u8 *)a + 0x188) + (((u8 *)b)[1] << 10));
    t += a->b160;
    if (a->h140 != 0) {
        b->f34 = a->f34 - 1.6666666269302368f * t->x;
    } else {
        b->f34 = a->f34 + 1.6666666269302368f * t->x;
    }
    func_001823C0(b);
    if (b->b211 != 0) {
        a->f34 = b->f34;
        if (a->h140 != 0) {
            a->f34 += 1.6666666269302368f * t->x;
        } else {
            a->f34 -= 1.6666666269302368f * t->x;
        }
    }
    b->f38 = a->f38 + 2.142857074737549f * t->y;
    b->b168 = t->b4;
    b->h140 = a->h140 ^ (u8)(t->b5 & 1);
    if (t->b6 > 0) {
        s8 x = a->b24;
        s8 y = b->b24;
        if (y < x) {
            b->b24 = x;
            a->b24 = y;
        }
    } else {
        s8 x = a->b24;
        s8 y = b->b24;
        if (x < y) {
            b->b24 = x;
            a->b24 = y;
        }
    }
    b->i48 = fptosi((f32)a->i48 + (f32)(t->b7 << 8));
    if (*k != b->b16A) {
        func_001757E0(b, 0x10, b->b168);
        b->b16A = *(u8 *)((u8 *)a + 0x160);
    }
    func_00178EB0(b);
}
