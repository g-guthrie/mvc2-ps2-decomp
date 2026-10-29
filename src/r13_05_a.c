/* func_002801B0: MW 3.0.3 (also 3.0) -O3 -Op -sdatathreshold 8. Case-0 constant/pointer idiom copied from sibling func_0027FF50 (src/sLa1_a.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C[];
extern u8 *D_004C2794;

typedef struct { u8 pad[0x2B8]; u8 b[8]; } NQA;

#pragma opt_propagation off
void func_002801B0(u8 *p) {
    extern void func_00155490(u8 *);
    extern void func_003298B0(s32, s32, s32);
    f32 f;
    p[0x13C] = 0; p[0x201] = 0x10; p[0x1B1] = 0; p[0x159] = 0xFF;
    switch (p[6]) {
    case 0: {
        u8 *q; u8 *r;
        f = 40.0f * *(f32 *)(p + 0x50);
        if (*(s16 *)(p + 0x140) == 0) f = -f;
        *(f32 *)(p + 0x34) = D_004F1F4C[0] - f;
        { s32 c = 1; q = ((NQA *)p)->b; q[1] = c; r = q + 1; }
        if (*D_004C2794 >= 9) {
            u32 t = p[6]; p[6] = t + 1;
            *r = 0;
            func_00155490(p);
            *(s16 *)(p + 0x1C) = 0xDC;
            return;
        }
        return;
    }
    case 1: {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[6]; p[6] = t + 1;
            func_003298B0(-1, 0x20, 1);
        }
        return;
    }
    }
}
