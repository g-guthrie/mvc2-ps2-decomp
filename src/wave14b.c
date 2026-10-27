struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void (*D_004C1C18[2])(u8 *, u8 *);
extern void (*D_004C2160[2])(u8 *, u8 *);
extern void (*D_004BF390[2])(u8 *);
extern u8 D_004F2598[];
extern u8 D_004F2B50[];
extern void func_003DAA40(struct Object *);
extern void func_00191840(u8 *p, s32 a, s32 b);



void func_003C47E0(u8 *p, u8 *q) {
    if (q[0x169] != 0x16) {
        p[4]++;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        D_004C2160[p[5]](p, q);
    }
}

void func_00145ED0(u8 *p) {
    if (*(s8 *)(D_004C2840 + 2) != 3) {
        func_003DAA40((struct Object *)p);
    } else {
        D_004BF390[p[4]](p);
    }
}

void func_001917F0(u8 *p, s32 a, s32 b) {
    if (*(s8 *)(D_004C2840 + 0x88) != 3) {
        u8 *t = D_004F2598;
        if (p[2] != 0) t = D_004F2B50;
        func_00191840(t, a, b);
    }
}
