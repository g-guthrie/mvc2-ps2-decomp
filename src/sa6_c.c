typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s16 D_0062CFE0[];

void func_003F79A8(s8 *buf, s16 *o1, s16 *o2, s16 *o3)
{
    extern s32 func_0011FFA0(char *);
    s32 n, i;
    s16 a, b, c;
    n = func_0011FFA0((char *)buf);
    if (n < 3) return;
    a = D_0062CFE0[0x200];
    for (i = 0; i < n; i++) a = D_0062CFE0[(a * buf[i]) % 1024];
    b = D_0062CFE0[0x280];
    for (i = 0; i < n; i++) b = D_0062CFE0[(b * buf[i]) % 1024];
    c = D_0062CFE0[0x300];
    for (i = 0; i < n; i++) c = D_0062CFE0[(c * buf[i]) % 1024];
    *o1 = a;
    *o2 = b;
    *o3 = c;
}
