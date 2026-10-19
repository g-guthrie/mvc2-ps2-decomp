typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void (*D_00471B58[])(u8 *);
extern void func_00390CB0(u8 *);
extern void func_003DAA40(u8 *);
extern void func_001E7F60(u8 *);

void func_00391540(u8 *p, u8 *q)
{
    if ((D_004D18DC & (1 << D_004D18DB)) != 0)
        return;
    if (q[0x425] && p[4] < 2) {
        func_00390CB0(p);
        func_003DAA40(p);
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    D_00471B58[p[5]](p);
    func_001E7F60(p);
}
