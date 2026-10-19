typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004C2720;
extern s32 func_001BF5C0(u8 *);
extern void func_001754A0(u8 *, int, int);
extern void func_001BF4E0(u8 *);

void func_001BF9E0(u8 *p)
{
    s32 r;
    if ((*(u8 **)(p + 0x18))[4] >= 2) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (p[0x23] == 0) {
        r = func_001BF5C0(p);
        p[0x13C] = (u8)r;
        if (*(s8 *)(p + 0x13C) != 0)
            func_001754A0(p, 0x1B, 8);
        func_001BF4E0(p);
        return;
    }
    if (*D_004C2720 < p[0x23]) {
        p[0x13C] = 0;
        return;
    }
    r = func_001BF5C0(p);
    p[0x13C] = (u8)r;
    if (*(s8 *)(p + 0x13C) != 0)
        func_001754A0(p, 0x1B, p[0x23] == *D_004C2720 ? 10 : 9);
    func_001BF4E0(p);
}
