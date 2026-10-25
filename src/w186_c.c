typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0015B7F0(u8 *p, u8 *q) {
    extern s32 func_0015BA00(u8 *,u8 *);
    extern void func_0015B8B0(u8 *,u8 *);
    double degrees;
    p[0x13C] = 1;
    if (func_0015BA00(p,q) != 0) {
        { u32 t = p[4]; p[4] = t + 1; }
        func_0015B8B0(p, q);
    } else {
        *(s16 *)(p + 0x1C) = (*(s16 *)(q + 0x140) != 0) ? 0 : -180;
        degrees = *(s16 *)(p + 0x1C);
        *(s32 *)(p + 0x48) = (u16)((u32)(s32)(0.5 + 65536.0 * degrees / 360.0));
    }
}
