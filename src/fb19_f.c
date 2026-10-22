typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad1[0x1C];
    f32 f58, f5c, f60;
    u8 pad2[4];
    f32 f68, f6c;
    u8 pad3[0x14];
    f32 b10, b14;
} P19f;

void func_00196260(u8 *a0, u8 *q) {
    extern void func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    P19f *p = (P19f *)a0;
    f32 z;
    u8 *b;
    z = 0.0f;
    *(f32 *)(a0 + 0x98) = *(f32 *)(q + 0x34) + *(f32 *)(a0 + 0xA0);
    *(f32 *)(a0 + 0x9C) = *(f32 *)(q + 0x38) + *(f32 *)(a0 + 0xA4);
    b = a0 + 0x88;
    if (p->f60 > z) {
        if (*(f32 *)(b + 0x14) - p->f38 < z) {
            if (p->f6c > z) p->f6c = -p->f6c;
        }
    } else {
        if (*(f32 *)(b + 0x14) - p->f38 > z) {
            if (p->f6c < z) p->f6c = -p->f6c;
        }
    }
    if (p->f5c < z) {
        if (*(f32 *)(b + 0x10) - p->f34 > z) {
            if (p->f68 < z) p->f68 = -p->f68;
        }
        if (*(f32 *)(b + 0x10) - p->f34 < z) {
            if (p->f68 > z) p->f68 = -p->f68;
        }
    } else {
        if (*(f32 *)(b + 0x10) - p->f34 < z) {
            if (p->f68 > z) p->f68 = -p->f68;
        }
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175670(a0);
    func_001975C0(a0, q);
}
