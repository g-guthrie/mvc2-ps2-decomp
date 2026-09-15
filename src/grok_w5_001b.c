typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

typedef void (*DispatchFn)(u8 *);

extern s8 func_00175670(u8 *);
extern void func_001BD670(u8 *);

extern DispatchFn jtbl_004BF8C8[2];
extern DispatchFn jtbl_004BF8E0[2];
extern DispatchFn jtbl_004BF8E8[2];
extern DispatchFn jtbl_004BF8F8[2];
extern DispatchFn jtbl_004BF900[2];
extern DispatchFn jtbl_004BF908[2];
extern DispatchFn jtbl_004BF910[2];
extern DispatchFn jtbl_004BF918[2];
extern DispatchFn jtbl_004BF930[2];
extern DispatchFn jtbl_004BF938[2];
extern DispatchFn jtbl_004BF948[2];
extern DispatchFn jtbl_004BF9C0[2];

void func_001BD630(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) == 0) {
        p[5]++;
        func_001BD670(p);
    }
}

void func_001B2A80(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[0x1e4] != 22)
        p[5]++;
    else if ((s8)p[0x153] >= 0)
        func_00175670(p);
}

void func_001B4230(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF8E0[p[6]](p);
}

void func_001B4320(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF8E8[p[6]](p);
}

void func_001B4530(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF8F8[p[6]](p);
}

void func_001B4630(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF900[p[6]](p);
}

void func_001B4720(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF908[p[6]](p);
}

void func_001B4D20(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF910[p[6]](p);
}

void func_001B4E40(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169])
        p[4] = 2;
    else
        jtbl_004BF918[p[6]](p);
}

void func_001B55C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xd0) != *(u16 *)(q + 0x168))
        p[4] = 2;
    else
        jtbl_004BF938[p[6]](p);
}

void func_001B5B80(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xd0) != *(u16 *)(q + 0x168))
        p[4] = 2;
    else
        jtbl_004BF948[p[6]](p);
}

void func_001B3A60(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169]) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0x13c] = 0;
    } else
        jtbl_004BF8C8[p[6]](p);
}

void func_001B5230(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0xd1] != q[0x169]) {
        p[0x13c] = 0;
        p[4] = 2;
    } else
        jtbl_004BF930[p[6]](p);
}

void func_001BF800(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[4] >= 2) {
        p[4]++;
        p[0x13c] = 0;
    } else
        jtbl_004BF9C0[p[5]](p);
}
