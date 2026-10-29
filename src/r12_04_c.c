/* func_00176360: MW 3.0.3 (try.sh) -O3,p -sdatathreshold 8. opt_dead_assignments +
 * opt_propagation off: locals colour in declaration order (named k constant,
 * n3 = n1 << 12 temp); ,p supplies retail's loop-tail scheduling. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s32 f10, f14, f18, f1C;
    u32 *f20;
    s32 f24, f28, f2C, f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54;
} Tex176;

extern s8 data_s8_004ACD08[];
extern s32 D_00446BF0[];
extern s32 D_0063248C[];

#pragma push
#pragma opt_dead_assignments off
#pragma opt_propagation off

void func_00176360(s32 a, u16 *c)
{
    extern void func_00413C00();
    Tex176 t;
    u32 buf[16];
    s32 n1;
    s32 n2;
    s32 v;
    s32 n3, n0;
    u32 k;
    u32 al;
    s32 id;
    s32 i;
    s32 o2, o4;

    id = -1;
    if (a >= data_s8_004ACD08[0] && a < data_s8_004ACD08[1]) {
        id = D_00446BF0[0]; a -= data_s8_004ACD08[0];
    } else if (a >= data_s8_004ACD08[1] && a < data_s8_004ACD08[2]) {
        id = D_00446BF0[1]; a -= data_s8_004ACD08[1];
    } else if (a >= data_s8_004ACD08[2] && a < data_s8_004ACD08[3]) {
        id = D_00446BF0[2]; a -= data_s8_004ACD08[2];
    } else if (a >= data_s8_004ACD08[3] && a < data_s8_004ACD08[4]) {
        id = D_00446BF0[3]; a -= data_s8_004ACD08[3];
    } else if (a >= data_s8_004ACD08[4] && a < data_s8_004ACD08[5]) {
        id = D_00446BF0[4]; a -= data_s8_004ACD08[4];
    } else if (a >= data_s8_004ACD08[5]) {
        id = D_00446BF0[5]; a -= data_s8_004ACD08[5];
    }
    switch (id) {
    case -1: break;
    default: {
    i = 0; o2 = 0; o4 = 0;
    do {
        k = 0xF0000000;
        v = *(u16 *)((u8 *)c + o2);
        al = (v & 0xF000) >> 12;
        n2 = (v & 0xF00) >> 8;
        n1 = (v & 0xF0) >> 4;
        v &= 0xF;
        al <<= 28;
        if (al == k) al = 0xFF000000;
        n3 = n1 << 12;
        *(u32 *)((u8 *)buf + o4) = (n2 << 20) | (n3 | (al | (v << 4)));
        i++; o2 += 2; o4 += 4;
    } while (i < 16);
    t.f10 = 0; t.f14 = 16; t.f18 = 1; t.f1C = 0x40; t.f20 = buf;
    t.f24 = 4; t.f28 = 8; t.f2C = 16; t.f30 = 0xFF; t.f34 = 8; t.f38 = 8;
    t.f3C = 0xFF; t.f40 = 8; t.f44 = 0; t.f4C = 8; t.f48 = 0xFF; t.f50 = 0x18; t.f54 = 0xFF;
    func_00413C00(D_0063248C[id * 5], a, &t, 8);
    }
}
}

#pragma pop
