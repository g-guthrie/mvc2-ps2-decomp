typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00445840[];

s32 func_001689F0(u8 *o, u8 *s)
{
    extern s32 func_00166D80(u8 *, u8 *);
    extern s32 func_00166DC0(u8 *, u8 *);
    extern s32 func_00167140(u8 *, u8 *);
    extern s32 func_001671E0(u8 *, u8 *);
    u8 *buf;
    u8 *tab;
    u32 pos;
    s32 depth;
    o[0x451] = 1;
    depth = 0;
    tab = D_00445840;
    pos = *(u16 *)(s + 4);
    buf = *(u8 **)s;
    do {
        u32 t = s[7];
        u32 op;
        s[7] = t + 1;
        op = buf[pos];
        pos += tab[op];
        switch (op) {
        case 3:
            return func_00166D80(o, s);
        case 8:
            return func_00166DC0(o, s);
        case 0x16:
            return func_00167140(o, s);
        case 0x43:
            return func_001671E0(o, s);
        case 0x49:
            depth--;
            break;
        }
    } while (depth >= 0);
    *(u16 *)(s + 4) = pos;
    o[0x472] = 0;
    return 1;
}
