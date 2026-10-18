typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00445840[];

s32 func_001688C0(u8 *p, u8 *s) {
    extern s32 func_00166D80();
    extern s32 func_00166DC0();
    extern s32 func_00167140();
    extern s32 func_001671E0();
    u8 *base;
    u8 *tab;
    u32 pos;
    s32 depth;
    s32 op;
    u32 t;
    p[0x451] = 1;
    depth = 0;
    tab = D_00445840;
    pos = *(u16 *)(s + 4);
    base = *(u8 **)s;
    do {
        t = s[7];
        s[7] = t + 1;
        op = base[pos];
        pos += tab[op];
        if (op >= 0x60) {
            depth++;
        } else {
            switch (op) {
            case 3:
                return func_00166D80();
            case 8:
                return func_00166DC0();
            case 0x16:
                return func_00167140();
            case 0x43:
                return func_001671E0();
            case 0x17:
                if (depth != 0) break;
            case 0x18:
            case 0x49:
                depth--;
                break;
            }
        }
    } while (depth >= 0);
    *(u16 *)(s + 4) = pos;
    p[0x472] = 0;
    return 1;
}
