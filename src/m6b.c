typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_0016C770(u8 *p) {
    *(f32 *)(p + 0x104) -= 0.0005208333604969084f;
    *(f32 *)(p + 0x10C) -= 0.0005208333604969084f;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1C) = 0xF0;
        }
    }
}

extern f32 D_004F1FC8;
extern void func_00175670();
void func_001BF200(u8 *p, u8 *q) {
    if (q[0x1E4] != 0x16) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        *(s16 *)(p + 0x140) = 1;
        *(f32 *)(p + 0x50) = 4.0f;
        *(f32 *)(p + 0x54) = 0.8f;
        *(f32 *)(p + 0x118) = 0.75f;
        *(f32 *)(p + 0x34) = D_004F1FC8 - 106.66666412353516f;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_00175670();
    }
}

extern void func_003DAA40(void *);
extern void func_0032E690(void *);
void func_0015D270(u8 *p) {
    *(s16 *)(p + 0x1C) += 1;
    if (*(s16 *)(p + 0x1C) > 0x1E) {
        func_003DAA40(p);
    } else {
        func_0032E690(p);
        *(s32 *)(p + 0x40) += *(s32 *)(p + 0x48);
        *(s32 *)(p + 0x44) += *(s32 *)(p + 0x48) / 2;
        *(f32 *)(p + 0x74) -= 0.016666667535901070f;
    }
}
