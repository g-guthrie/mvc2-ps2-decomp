typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern void func_00185490(u8 *);
extern s32 func_001879C0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00181D90(u8 *);

void func_00186F00(u8 *p)
{
    int a2;

    if (*(s8 *)(p + 0x539))
        func_00185490(p);
    p[0x20D] = 0;
    p[0x1EC] = 0;
    p[0x210] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    p[0x1EA] = 0x11;
    p[0x1ED] = 0;
    if (func_001879C0(p))
        return;
    if (*(s8 *)(p + 0x539) == 0) {
        u16 w = *(u16 *)(p + 0x35E);
        if ((w & 0xC00) == 0)
            *(s8 *)(p + 0x1E7) = -1;
        else if (w & 0x800)
            *(s8 *)(p + 0x1E7) = 0;
        else
            *(s8 *)(p + 0x1E7) = 1;
    }
    {
        s8 d = *(s8 *)(p + 0x1E7);
        a2 = 2;
        if (d != 1) {
            a2 = 1;
            if (d != 0)
                a2 = 0;
        }
    }
    func_001757E0(p, 1, a2);
    func_00181D90(p);
}
