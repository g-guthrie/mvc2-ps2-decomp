typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 D_00446DC0[];

void func_00182ED0(u8 *p) {
    extern s32 func_00174170();
    extern void func_00183C40(u8 *);
    extern void func_00175700(u8 *);
    s8 n;
    u16 h;
    s8 r;
    s8 t;
    s8 m;
    u8 c;
    if (*(s8 *)(p + 0x1F7) == 0 || (h = *(u16 *)(p + 0x35C)) == 0) return;
    n = 0;
    if (h & 0x3C00) n += 2;
    if (h & 0x3F0) n += 1;
    n += D_00446DC0[func_00174170() & 0xF];
    t = *(s8 *)(p + 0x1F7);
    m = t & 3;
    r = t - n;
    *(s8 *)(p + 0x1F7) = r;
    if (r < 0) *(s8 *)(p + 0x1F7) = 0;
    if ((s8)m < (s8)n) {
        c = p[5];
        if (c == 3 && p[0x247] == 9 && p[0x247] == 0x17) {
            p[0x152] = 1;
            func_00183C40(p);
        } else if (c == 0 && p[0x1E4] == 0x17) {
            p[0x152] = 1;
        } else if (c == 0 && p[0x1E4] == 0xC) {
            p[0x152] = 1;
            func_00175700(p);
            p[0x152] = 1;
        }
    }
}
