typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_001C93F0(u8 *);
extern void func_00175700(u8 *);

void func_001C9230(u8 *p)
{
    u8 *q;
    s8 depth;
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    depth = 7;
    if (*(s8 *)(p + 0x151) >= 0)
        p[0x24] = depth;
    else
        p[0x24] = 0;
    q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x15) {
        p[4]++;
        func_001C93F0(p);
        return;
    }
    if (q[0x168] == 9 || q[0x168] == 8 || q[0x168] == 6)
        func_00175700(p);
    else {
        p[4]++;
        func_001C93F0(p);
    }
}
