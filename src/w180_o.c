typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x; s16 y; u8 a; u8 b; } E;
extern E D_0044C3C0[];

void func_001BEF20(u8 *d, u8 *s) {
    E *e;
    u32 c;
    u32 h;
    s16 flag;
    extern void func_00175580(u8 *, s32, s32, s32);
    if (s[0x1E4] != 0x15 || s[0x1FD] != 2) {
        c = d[4];
        d[4] = c + 1;
        d[0x13C] = 0;
        return;
    }
    h = *(u16 *)(s + 0x168);
    if (h != 0x1506 && h != 0x1507) {
        c = d[4];
        d[4] = c + 1;
        d[0x13C] = 0;
        return;
    }
    e = &D_0044C3C0[d[0x20]];
    func_00175580(d, 0x1B, e->b, *(s8 *)(s + 0x150) & 0xF);
    flag = *(s16 *)(s + 0x140);
    *(s16 *)(d + 0x140) = flag;
    if (flag == 0) {
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) + 1.6666666269302368f * (f32)e->x;
    } else {
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) - 1.6666666269302368f * (f32)e->x;
    }
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + 2.142857074737549f * (f32)e->y;
}
