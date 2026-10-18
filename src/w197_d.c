typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_004F20B0[];
extern void func_00186A60(u8 *, s32);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);

void func_00185870(u8 *p, u8 *q) {
    u8 *t = D_004F20B0 + p[0x1B8] * 0x5B8;
    u32 b;
    *(u8 **)(t + 0x1E0) = q;
    *(u8 **)(t + 0x1DC) = q;
    *(u8 **)(p + 0x1E0) = q;
    *(u8 **)(p + 0x1DC) = q;
    *(u8 **)(q + 0x1E0) = p;
    *(u8 **)(q + 0x1DC) = t;
    t[0x1FE] = 1;
    q[0x20B] = t[0x20B];
    q[5] = 2;
    q[0x1B1] = 0;
    q[0x201] = 2;
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
    q[0x24A] = 0x78;
    func_00175C00(q, 1);
    b = q[0x24F] + 2;
    q[0x24F] = b;
    if ((b & 0xFF) == 0) {
        q[0x24F] = 0xFF;
    }
}
