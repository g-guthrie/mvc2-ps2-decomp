typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *func_001E7FD0(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, f32 *);
extern void func_00185770(u8 *, u8 *);

void func_001F46C0(u8 *p)
{
    u8 *q;
    u32 bits;
    f32 off[2];
    *(s16 *)(p + 0x3F8) = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6] = 4;
        func_001757E0(p, 0xF, 0x36);
        return;
    }
    q = func_001E7FD0(p);
    if (q == 0)
        return;
    p[6] = p[6] + 1;
    p[7] = 0;
    func_001266A0(p, 5, 5);
    p[0x20B] = 0xCD;
    bits = 0xC312AAAA;
    off[0] = *(f32 *)&bits;
    bits = 0x432B6DB6;
    off[1] = *(f32 *)&bits;
    func_0015D010(p, off);
    func_001757E0(p, 0xF, 0x1D);
    func_00185770(p, q);
}
