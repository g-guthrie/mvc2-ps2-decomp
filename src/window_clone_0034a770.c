typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_0034B040(u8 *, u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_0015E630(u8 *);
/* Native handler forwards the owner in A1; the matched callee consumes A0. */
extern void func_0034AFC0(u8 *, u8 *);

void func_0034A770(u8 *p, u8 *q) {
    *(u8 **)(q + 0x2BC) = p;
    *(u32 *)(p + 0x14C) = 0x80403030;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s16 *)(p + 0x140) ^= 1;
    func_0034B040(p, q);
    func_001757E0(p, 0x16, 8);
    func_0015E630(p);
    p[0] = 1;
    func_0034AFC0(p, q);
}
