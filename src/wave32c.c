typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void (*D_004BF5A0[2])(u8 *, u8 *);

void func_001973F0(u8 *a, u8 *b) {
    u8 *q = a + 0x88;
    if (b[5] != 0 || b[0x1E4] != 0x1D || b[0x1FD] != 9) {
        *q = 0;
    } else {
        if (a[0x21] < 5) D_004BF5A0[a[6]](a, b);
    }
}

extern u8 *func_003DA750(int, int, int);
extern void func_00161370(void);
extern u32 D_004C2838;

void func_001612F0(u8 *a) {
    u8 *p = func_003DA750(0, 7, 1);
    if (p) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_00161370;
        *(s16 *)(p + 0xCC) = 0x9D;
        *(u32 *)(p + 0x84) = D_004C2838;
        *(u32 *)(p + 0xD0) = 0x821;
        *(u8 **)(p + 0xC8) = a + 0x88;
        *(u8 **)(p + 0x18) = a;
        *(u32 *)(p + 0x74) = 0x3F800000;
    }
}

typedef struct { u8 *x, *y, *z; } T3;
extern u8 *D_004C2794;

void func_00190CC0(u8 *a) {
    u8 *t = D_004C2794;
    u32 i = a[2] ^ 1;
    T3 *e = (T3 *)(t + 0x18) + i;
    u8 *b = e->x;
    u8 *c = e->y;
    u8 *d = e->z;
    if (b[5] >= 3 || c[5] >= 3 || d[5] >= 3 || t[0x38] != 0 || (*(u8 **)(a + 0x1CC))[0x425] != 0) {
        a[0x249] = 0;
        b[0x249] = 0;
        c[0x249] = 0;
        d[0x249] = 0;
    }
}
