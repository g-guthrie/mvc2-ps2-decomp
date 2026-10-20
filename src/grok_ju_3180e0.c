typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);
void residual_003180E0(u8 *p)
{
    int t;
    int pair;
    u16 anim;
    u8 arg;
    p[6]++;
    p[0x13C] = 1;
    t = p[0x25];
    pair = t << 1;
    anim = pair + 6;
    arg = 0xD;
    if (*(s8 *)(p + 0x539) == 0) {
        if ((*(u16 *)(p + 0x4F0) & 0x60) == 0) {
            anim = pair + 5;
            arg = 0;
        }
    }
    func_001757E0(p, 0x12, arg);
    func_00176160(p, 2, anim & 0xFFFF, 1);
}
