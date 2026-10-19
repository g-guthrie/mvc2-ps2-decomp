typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_00186A60(u8 *, s32);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_00190D50(u8 *, u8 *);
extern u8 D_004D18A4;

void func_00185770(u8 *p, u8 *q)
{
    *(u8 **)(p + 0x1DC) = q;
    *(u8 **)(p + 0x1E0) = q;
    *(u8 **)(q + 0x1DC) = p;
    *(u8 **)(q + 0x1E0) = p;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    q[0x20B] = p[0x20B];
    q[5] = 2;
    func_00186A60(q, 0x1F);
    q[0x20A] = 0;
    q[7] = 0;
    q[6] = 0;
    *(s8 *)(q + 0x16A) = -1;
    q[0x1B4] = 0;
    q[0x1F7] = 0;
    q[0x215] = 0;
    q[0x23F] = q[0x23E];
    q[0x23E] = 0;
    func_0011D8F8(q + 0x370, 0, 8);
    q[0x24A] = 120;
    D_004D18A4 |= (u8)(1 << *(s8 *)(q + 0x1B8));
    func_00175C00(q, 1);
    func_00190D50(q, p);
    {
        unsigned int n = q[0x24F];
        n += 2;
        q[0x24F] = n;
        if ((n & 0xFF) == 0)
            q[0x24F] = 0xFF;
    }
}
