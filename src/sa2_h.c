typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x, y; u8 pad4; u8 b5; } E6;
extern E6 D_0044C0E0[];

void func_001BDE30(u8 *a, void *b_context) {
    extern int func_00175580(u8 *, s32, s32, s32);
    E6 *e;
    u32 t;
    u8 *b = (u8 *)b_context;
    if (b[0x1E4] != 0x1D || b[0x1FD] != 3) {
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
        return;
    }
    if (*(u16 *)(b + 0x168) != 0x1503) {
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
        return;
    }
    *(u32 *)(a + 0x118) = 0x3F000000;
    a[0x13C] = (*(s8 *)(b + 0x150) != 0) ? 1 : 0;
    e = (E6 *)((u8 *)D_0044C0E0 + a[0x20] * 6);
    func_00175580(a, 0x1B, e->b5, *(s8 *)(b + 0x150) & 0xF);
    t = *(s16 *)(b + 0x140);
    *(s16 *)(a + 0x140) = t;
    if (t == 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + 1.6666666269302368f * (f32)e->x;
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 1.6666666269302368f * (f32)e->x;
    }
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + 2.142857074737549f * (f32)e->y;
}
