typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
typedef int s32;
typedef struct { s16 a, b, c; } E6;
extern E6 D_0044C3C0[];
void func_001BEBD0(u8 *a, u8 *b) {
    extern void func_00175670(u8 *);
    u32 t;
    u16 h;
    E6 *e;
    s16 v;
    if (b[0x1E4] != 0x15 || b[0x1FD] != 2 || *(s8 *)(b + 0x150) == 0) {
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else {
        h = *(u16 *)(b + 0x168);
        if (h != 0x1506 && h != 0x1507) {
            t = a[4];
            a[4] = t + 1;
            a[0x13C] = 0;
        } else {
            func_00175670(a);
            e = &D_0044C3C0[a[0x20]];
            v = *(s16 *)(b + 0x140);
            *(s16 *)(a + 0x140) = v;
            if (v == 0) {
                *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + 1.6666666269302368f * (f32)e->a;
            } else {
                *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 1.6666666269302368f * (f32)e->a;
            }
            *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + 2.142857074737549f * (f32)e->b;
        }
    }
}
