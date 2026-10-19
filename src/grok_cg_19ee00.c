typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;

extern void func_0019EDD0(void);
extern void func_00175700(u8 *);
extern void func_0019F3A0(u8 *, u8 *);

void func_0019EE00(u8 *p, u8 *q)
{
    u8 one = 1;
    u8 *g = *(u8 **)(p + 0x14);
    p[0x13C] = 0;
    if (g[4] != one) {
        p[4] = p[4] + 1;
        return;
    }
    if (p[0x21] == 0) {
        if (g[0x20] != one) {
            p[4] = p[4] + 1;
            return;
        }
        if (g[0x21] != 0) {
            p[4] = p[4] + 1;
            return;
        }
        if (*(u16 *)(g + 0x168) != 0x1718) {
            p[4] = p[4] + 1;
            return;
        }
        func_0019EDD0();
    } else {
        *(s8 *)(p + 0x31) = -1;
        *(f32 *)(p + 0x34) = *(f32 *)(g + 0x34);
        *(f32 *)(p + 0x38) = 21.428569793701172f + *(f32 *)(g + 0x38);
    }
    func_00175700(p);
    func_0019F3A0(p, q);
}
