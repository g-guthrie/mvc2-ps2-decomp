typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF678[2];
extern DispatchFn jtbl_004BF688[2];
extern DispatchFn jtbl_004BF808[2];
extern DispatchFn jtbl_004BF838[2];
extern DispatchFn jtbl_004BF84C[2];
extern DispatchFn jtbl_004BF850[2];
extern DispatchFn jtbl_004BF858[2];
extern DispatchFn jtbl_004BF9A8[2];
extern void func_001AC3F0(u8 *);
extern void func_00175C00(u8 *, int);

void func_001A3780(u8 *p, u8 *q)
{
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xd0))
        p[4]++;
    else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        p[0x24] = 7;
        jtbl_004BF678[p[5]](p);
    }
}

void func_001A3950(u8 *p, u8 *q)
{
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xd0))
        p[4]++;
    else {
        p[0x24] = (s8)q[0x24] + (s8)p[0x31];
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        jtbl_004BF688[p[5]](p);
    }
}

void func_001AB550(u8 *p, u8 *q)
{
    if (q[0x1e4] != 0x16)
        func_001AC3F0(p);
    else
        jtbl_004BF808[p[7]](p);
}

void func_001B0970(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    jtbl_004BF838[p[5]](p);
    if (q[0x1e4] != 0x1E) {
        p[4]++;
        p[0x13c] = 0;
    }
}

void func_001B0D60(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    jtbl_004BF84C[p[5]](p);
    if (q[0x1e4] != 0x16) {
        p[4]++;
        p[0x13c] = 0;
        func_00175C00(q, 0);
    }
}

void func_001B0DE0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    jtbl_004BF850[p[5]](p);
    if (q[0x1e4] != 0x16) {
        p[4]++;
        p[0x13c] = 0;
        func_00175C00(q, 0);
    }
}

void func_001B0E60(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    jtbl_004BF858[p[5]](p);
    if (q[0x1e4] != 0x16) {
        p[4]++;
        p[0x13c] = 0;
        func_00175C00(q, 0);
    }
}

void func_001BE640(u8 *p, u8 *q)
{
    if ((q = *(u8 **)(p + 0x18))[4] >= 2) {
        p[4] = 2;
        p[0x13c] = 0;
    } else
        jtbl_004BF9A8[p[5]](p);
}
