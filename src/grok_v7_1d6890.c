typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;

extern int func_00175700(u8 *);

void func_001D6890(u8 *p, u8 *q)
{
    u8 *self = p;
    u8 *other = q;
    u16 *slot = (u16 *)(self + 0xD0);
    s8 t;
    t = (s8)other[0x24] + (s8)self[0x31];
    self[0x24] = t;
    if ((s8)self[0x24] >= 8)
        self[0x24] = 7;
    if ((s8)self[0x24] < 0)
        self[0x24] = 0;
    func_00175700(self);
    *(f32 *)(self + 0x34) = *(f32 *)(other + 0x34);
    *(f32 *)(self + 0x38) = *(f32 *)(other + 0x38);
    *(f32 *)(self + 0x34) += *(f32 *)(self + 0x5C);
    if (*(u16 *)(other + 0x168) != *slot)
        self[4]++;
}
