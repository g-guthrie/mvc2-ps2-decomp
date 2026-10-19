typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00185490(u8 *);
extern s32 func_001879C0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00181D90(u8 *);

void func_00186F00(u8 *p)
{
    s32 a2;
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
    if (!*(s8 *)(p + 0x539)) {
        u16 v = *(u16 *)(p + 0x35E);
        if (!(v & 0xC00))
            *(s8 *)(p + 0x1E7) = -1;
        else if (v & 0x800)
            p[0x1E7] = 0;
        else
            p[0x1E7] = 1;
    }
    {
        s8 d = *(s8 *)(p + 0x1E7);
        switch (d) {
        case 1:
            a2 = 2;
            break;
        case 0:
            a2 = 1;
            break;
        default:
            a2 = 0;
            break;
        }
    }
    func_001757E0(p, 1, a2);
    func_00181D90(p);
}
