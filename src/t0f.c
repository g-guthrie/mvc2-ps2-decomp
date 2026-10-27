struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_003DAA40(struct Object *);
void func_00140C70(u8 *p) {
    f32 z = 0.0f;
    u8 st = p[4];
    u32 t;
    switch (st) {
    case 0:
        if (*(s16 *)(D_004C2840 + 0xA) >= 0x190) p[4] = st + 1;
        break;
    case 1:
        *(f32 *)(p + 0x78) -= 0.01f;
        *(f32 *)(p + 0x7C) -= 0.01f;
        *(f32 *)(p + 0x80) -= 0.01f;
        if (*(f32 *)(p + 0x78) <= z) {
            t = p[4];
            p[4] = t + 1;
            *(f32 *)(p + 0x78) = z;
            *(f32 *)(p + 0x7C) = z;
            *(f32 *)(p + 0x80) = z;
        }
        break;
    case 2:
        func_003DAA40((struct Object *)p);
        break;
    }
}
