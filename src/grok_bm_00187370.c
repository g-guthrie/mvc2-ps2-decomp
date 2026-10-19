typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_001879C0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00181D90(u8 *);

void func_00187370(u8 *p)
{
    int a2;

    p[0x20D] = 0;
    p[0x210] = 1;
    p[0x1EC] = 0;
    p[0x1EB] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    p[0x1ED] = 0;
    if (func_001879C0(p))
        return;
    if (*(s8 *)(p + 0x539) == 0) {
        u16 w = *(u16 *)(p + 0x35E);
        if ((w & 0xC00) == 0) {
            *(s8 *)(p + 0x1E7) = -1;
            p[0x168] = 6;
        } else if (w & 0x800) {
            *(s8 *)(p + 0x1E7) = 0;
            p[0x168] = 7;
        } else {
            *(s8 *)(p + 0x1E7) = 1;
            p[0x168] = 8;
        }
    }
    {
        s8 d = *(s8 *)(p + 0x1E7);
        a2 = 8;
        if (d != 1) {
            a2 = 7;
            if (d != 0)
                a2 = 6;
        }
    }
    func_001757E0(p, 1, a2);
    func_00181D90(p);
}
