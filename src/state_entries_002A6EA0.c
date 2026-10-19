typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

extern int func_001757E0(void *, int, int);
extern void func_002A6F10(u8 *);

void func_002A6EA0(u8 *p)
{
    u32 t = p[6];
    p[6] = t + 1;
    p[0x1E9] = p[0x1E9] + 1;
    p[0x1E8] = 0;
    p[0x1EA] = 17;
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 60;
    *(s16 *)(p + 0x140) = (p[0x1E6] ^ 1);
    func_001757E0(p, 20, 2);
    func_002A6F10(p);
}
