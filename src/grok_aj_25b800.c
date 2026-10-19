typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

extern s8 func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001548D0(u8 *, u32 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001843A0(u8 *);

void residual_0025B800(u8 *p)
{
    u32 v[4];
    u8 *q;

    if (func_00175700(p) >= 0) {
        if ((s8)p[0x151] == 6) {
            func_001266A0(p, 0, 0);
            v[0] = 0xC3055555;
            v[1] = 0x43092492;
            func_001548D0(p, v, 0xF);
            func_001E3710(p, 6);
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            p[0x1E6] = (s8)*(s16 *)(p + 0x140);
            *(s16 *)(q + 0x140) = p[0x1E6] ^ 1;
            q[0x1E6] = (s8)*(s16 *)(q + 0x140);
            q[0x1B5] = 0x20;
            q[0x20A] = 1;
        }
    } else {
        func_001843A0(p);
    }
}
