typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w; s32 x; } E;
extern volatile s32 D_00633E20;
extern E D_00633E30[];
s32 func_00423480(u32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) {
    extern void func_00423370(s32, s32, s32, s32, s32, s32);
    s32 n, i, idx, t;
    if (a0 > 0xFFF) return -2;
    if (((a1 | a3 | t1) & 0xF) != 0) return -3;
    if (a2 > 0x1FFFF0 || t0 > 0x1FFFF0 || t2 > 0x1FFFF0) return -4;
    idx = D_00633E20;
    i = idx;
    n = 4;
    do {
        if (D_00633E30[i].w >= 0) return -1;
        i++;
        i = i % 64;
        n--;
    } while (n > 0);
    D_00633E30[idx].w = ((a0 << 8) & 0xFFFFFF) | 0x4D000000;
    t = D_00633E20 + 1;
    D_00633E20 = t;
    D_00633E20 = t % 64;
    func_00423370(a1, a2, a3, t0, t1, t2);
    return 0;
}
