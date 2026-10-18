typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001CAD00(u8 *p) {
    extern void func_001754A0();
    extern u8 D_0044DA60[];
    u8 v;
    s32 t = p[0x22];
    if (t == 0 || (u8)t >= 0x10) { *(s16 *)(p + 0x140) = 0; } else { *(s16 *)(p + 0x140) = 1; }
    if (p[7] != (v = D_0044DA60[p[0x22]])) {
        p[7] = v;
        func_001754A0(p, 0x1B, (u8)(p[7] + 0x13));
    }
}

