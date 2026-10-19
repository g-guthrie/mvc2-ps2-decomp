typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001549B0(u8 *, f32 *);
extern void func_001E3710(u8 *, int);

void func_00232D50(u8 *p)
{
    u8 *q;
    f32 v[4];
    if ((s8)func_00175700(p) < 0) {
        *(s16 *)(p + 0x140) ^= 1;
        func_00184540(p);
        return;
    }
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x22;
        q[0x20D] = 2;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        p[0x1E6] = (s8)p[0x1E6] ^ 1;
        v[0] = 0.0f;
        *(unsigned int *)(v + 1) = 0x43474924;
        func_001549B0(p, v);
        func_001E3710(p, 1);
    }
}
