typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004F7FB4[];
extern u32 D_004F7FB8[];

void func_001317F0(s32 a) {
    u32 *p;
    u32 bit = 1 << a;
    if (a >= 0x20) p = D_004F7FB8;
    else p = D_004F7FB4;
    *p |= bit;
}

s32 func_00269CD0(u8 *p, s32 f) {
    u16 v;
    if (f) v = *(u16 *)(p + 0x35C);
    else v = *(u16 *)(p + 0x354);
    if (!(v & 0xC00)) return 0;
    return 1;
}
