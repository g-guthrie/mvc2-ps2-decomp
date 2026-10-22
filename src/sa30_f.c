typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003F5090(u8 *p) {
    u32 t;
    u8 d;
    u32 f = p[0];
    if (!(f == 'T' && p[1] == 'I' && p[2] == 'M' && p[3] == '2')) {
        if (f == 'C' && p[1] == 'L' && p[2] == 'T' && p[3] == '2') return 0;
        return 0;
    }
    d = p[5];
    t = p[4];
    if (t == 3) goto ok;
    if (t == 4) {
        if (d == 0) goto ok;
        if (d == 1) goto ok;
    }
    return 0;
ok:
    return !(*(u16 *)(p + 6) != 1);
}
