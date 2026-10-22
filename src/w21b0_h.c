typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3h;
extern V3h D_00444190[];
extern u8 D_00444180[];
extern s32 D_004C27FC;
extern s32 D_004C27E8;
extern u16 D_004F7F92[];
extern u8 D_004CAFC0[];
extern u8 D_0014C0D0[];

u8 *func_0014C910(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014C760(f32, u8 *, s32, u16, s32, s32);
    u8 *s0;
    V3h *t;
    s32 i;
    s32 k;
    u8 *o;
    i = 0;
    k = 0;
    t = D_00444190;
    do {
        if ((o = func_003DA750(0, 0xD, 1)) == 0) return 0;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)D_0014C0D0;
        if (i != 3) {
            *(s16 *)(o + 0xCC) = *(s16 *)(D_00444180 + k);
            *(s32 *)(o + 0x84) = D_004C27FC;
        } else {
            *(s16 *)(o + 0xCC) = *(s16 *)(D_00444180 + k);
            *(s32 *)(o + 0x84) = D_004C27E8;
        }
        *(s32 *)(o + 0xD0) = 1;
        *(f32 *)(o + 0x34) = t->x;
        *(f32 *)(o + 0x38) = t->y;
        *(f32 *)(o + 0x3C) = t->z;
        t++;
        if (i < 2) {
            *(s32 *)(o + 0xD0) |= 0x10;
            *(u32 *)(o + 0x50) = 0x3F800000;
            *(u32 *)(o + 0x54) = 0x3E99999A;
        }
        if (i == 2) {
            s0 = o;
            *(s32 *)(o + 0xD0) |= 0x400;
        }
        i++;
        k += 4;
    } while (i < 4);
    func_0014C760(-5.989999771118164f, D_004CAFC0, 5, D_004F7F92[0], 0, 1);
    return s0;
}
