/* ./try.sh src/grok_as_00313840.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_003C1250(u8 *, s32, s32);
extern void func_00176160(u8 *, s32, s32, s32);

void func_00313840(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x13C] = 0;
    q[0xE] = 1;
    func_003C1250(p, 4, 0);
    func_003C1250(p, 5, 0);
    func_003C1250(p, 6, 0);
    func_003C1250(p, 6, 1);
    func_003C1250(p, 8, 0);
    func_003C1250(p, 8, 1);
    func_00176160(p, 0, p[0x25] * 3 + 0x48, 3);
    *(s16 *)(p + 0x1C) = 0x60;
    p[7]++;
}
