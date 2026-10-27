struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x0032F050 */
extern u8 *D_004C2840;
extern void func_003DAA40(struct Object *);
void func_0032F050(u8 *p) {
    switch (p[5]) {
    case 0:
        *(s16 *)(p + 0x1C) += 1;
        p[0x13C] = *(s16 *)(p + 0x1C) % 2;
        if (*(s16 *)(p + 0x1C) >= 5) {
            p[5] += 1;
            *(s16 *)(p + 0x1C) = 0;
            p[0x13C] = 1;
            *(u32 *)(p + 0x78) = 0x3F800000;
            *(u32 *)(p + 0x7C) = 0x3F800000;
            *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
        }
        break;
    case 1: {
        f32 v = *(f32 *)(p + 0x78) - 0.06666667014360428f;
        *(f32 *)(p + 0x78) = v;
        *(f32 *)(p + 0x7C) = v;
        *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
        {
        s16 t = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = t;
        if (t >= 0xF) {
            p[4] = 0;
            p[0x13C] = 0;
            if (*(u32 *)(D_004C2840 + 0x94) > 0x1194) func_003DAA40((struct Object *)p);
        }
        }
        break;
    }
    default:
        break;
    }
}
