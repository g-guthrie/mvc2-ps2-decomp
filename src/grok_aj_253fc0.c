typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_001AD170(u8 *, int, int);
extern void func_0018FDB0(u8 *);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_00191480(u8 *, u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_00253FC0(u8 *p)
{
    u8 *s1;
    u8 *s0;
    f32 v[3];
    f32 d;
    u32 bits;

    s1 = p;
    s1[0x22]++;
    s0 = *(u8 **)(s1 + 0x1DC);
    func_001AD170(s1, 0, 0);
    func_001AD170(s1, 2, 0);
    s0[0x1B5] = 0x22;
    func_0018FDB0(s1);
    d = *(f32 *)(s0 + 0x34) - *(f32 *)(s1 + 0x34);
    v[0] = d;
    if (d <= 0.0f) {
    } else {
        v[0] = -d;
    }
    v[2] = 0.0f;
    bits = 0x40092492;
    d = *(f32 *)&bits * (f32)s0[0x14C];
    bits = 0x3FE66666;
    v[1] = d / *(f32 *)&bits;
    func_001548D0(s1, v, 1);
    func_00191480(s0, s1, 1);
    func_001E3710(s1, 7);
    func_001757E0(s0, 0xD, (s1[0x22] & 1) ? 3 : 0);
}
