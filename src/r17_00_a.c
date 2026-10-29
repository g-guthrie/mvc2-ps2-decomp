/* func_003AD110: MW 3.0.3 "-O3 -Op -sdatathreshold 0" (also exact on 3.0 and with -O3,p). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Obj {
    u8 pad0[0x24];
    s8 b24;
    u8 pad25[0x34 - 0x25];
    f32 f34;
    f32 f38;
    u8 pad3c[0x140 - 0x3C];
    s16 h140;
} Obj;

typedef struct Node {
    u8 pad0[0xC];
    struct Node *next;
    u8 pad10[4];
    Obj *obj;
    u8 pad18[0x24 - 0x18];
    s8 b24;
} Node;

void func_003AD110(Node *a, u8 *o, u8 *in) {
    Obj *ob;
    f32 f2, f1;
    s32 i;
    u8 v8, vA, vB, vC;
    u8 *q;
    ob = a->obj;
    f2 = 1.66666662693f * (f32)*(s16 *)(in + 4);
    f1 = 2.14285707474f * (f32)*(s16 *)(in + 6);
    *(s16 *)(o + 0xA) = *(s8 *)(in + 0);
    o[0x35] = in[3];
    v8 = in[8];
    vA = in[0xA];
    vB = in[0xB];
    vC = in[0xC];
    o[0xD] = in[9];

    if (ob->h140 != 0) {
        f2 = -f2;
        v8 = -(s8)v8;
        vA = -(s8)vA;
        vB = -(s8)vB;
        vC = -(s8)vC;
    }

    *(f32 *)(o + 0x18) = f2;
    *(f32 *)(o + 0x1C) = f1;
    *(f32 *)(o + 0x10) = ob->f34 + f2;
    *(f32 *)(o + 0x14) = ob->f38 + f1;
    a->b24 = ob->b24;
    q = o;
    i = 0;
    while (i <= *(s8 *)(o + 0xF)) {
        q[0xC] = v8;
        v8 += vA;
        if ((s8)vA >= 0) {
            if ((s8)(vC - v8) < 0) v8 = vC;
        } else {
            if ((s8)(vC - v8) >= 0) v8 = vC;
        }
        vA += vB;
        if (vB) {
            if ((s8)vB < 0) {
                if ((s8)vA <= 0) vA = 1;
            } else {
                if ((s8)vA >= 0) vA = 0xFF;
            }
        }
        a = a->next;
        i++;
        q = (u8 *)a + 0x88;
    }
}
