struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00157F00(u8 *p) {
    extern void func_003DAA40(struct Object *);
    s16 v;
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x50) += 0.45f;
        *(f32 *)(p + 0x54) += 0.45f;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x14) {
            p[4] += 1;
        }
        break;
    case 1:
        *(f32 *)(p + 0x50) -= 0.23f;
        *(f32 *)(p + 0x54) -= 0.23f;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x14) {
            func_003DAA40((struct Object *)p);
            return;
        }
        break;
    }
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x78) += 0.2f;
        *(f32 *)(p + 0x7C) += 0.2f;
        *(f32 *)(p + 0x80) += 0.2f;
        if (*(s16 *)(p + 0x1C) >= 5) {
            p[5] += 1;
        }
        break;
    case 1:
        if (*(s16 *)(p + 0x1C) >= 0xF) {
            p[5] += 1;
        }
        break;
    case 2:
        *(f32 *)(p + 0x78) -= 0.2f;
        *(f32 *)(p + 0x7C) -= 0.2f;
        *(f32 *)(p + 0x80) -= 0.2f;
        if (*(s16 *)(p + 0x1C) >= 0x14) {
            func_003DAA40((struct Object *)p);
        }
        return;
    }
}
