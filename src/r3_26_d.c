typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G56c;
extern G56c *D_004C2794;

typedef struct { u8 pad[0x434]; s16 h434; s16 h436; s16 h438; } P18;

void func_0018FAA0(P18 *p, s32 a) {
    extern void func_0018FB70();
    extern void func_00190540();
    extern void func_001902F0();
    s16 v, b, n;
    if (*(u8 *)D_004C2794 != 4 || (v = p->h434) == 0) return;
    b = a;
    if (b == 0) return;
    if (b < 0) {
        func_0018FB70(p, a);
        func_00190540(p, a);
    } else {
        p->h434 = n = v + a;
        if (n > 0x90) p->h434 = 0x90;
        if (p->h434 > p->h438) p->h434 = p->h438;
    }
    func_001902F0(p);
}
