typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);

void residual_001B5120(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        return;
    }
    p[6]++;
    p[0x13C] = 1;
    p[0x24] = 0;
    func_001B5350(q, p);
    func_001754A0(p, 0x1B, p[0x20]);
    if (p[0x20] == 0x18)
        *(s32 *)(p + 0x48) = 0xD000;
    else if (p[0x20] == 0x17)
        *(s32 *)(p + 0x48) = 0xE000;
    else if (p[0x20] == 0x16)
        *(s32 *)(p + 0x48) = 0;
}
