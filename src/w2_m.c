typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 *func_00411130(s32 a, s32 b, s32 c)
{
    extern u8 D_00495BB8[];
    extern u8 D_004BEAE8[];
    extern void func_0011D8F8();
    extern s32 func_00409708();
    extern void func_0011EB60();
    u8 *p;
    s32 i;
    s32 buf[4];
    s32 r;
    p = D_00495BB8;
    i = 0;
    if (*(s8 *)p != 0) {
        u8 *q = p;
        u8 *r2 = p;
        do {
            i++;
            q += 0x14;
            r2 += 0x14;
            if (i >= 0x20) break;
            p = r2;
        } while (*(s8 *)q != 0);
    }
    if (i == 0x20) {
        return 0;
    }
    func_0011D8F8(p, 0, 0x14);
    *(s32 *)(p + 4) = a;
    *(s32 *)(p + 0xC) = c;
    *(s32 *)(p + 8) = b;
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = (s32)p;
    r = func_00409708(0, buf, 4, buf, 1);
    *(s32 *)(p + 0x10) = r;
    if (r == 0) {
        func_0011EB60(D_004BEAE8);
        return 0;
    }
    *(u8 *)p = 1;
    return p;
}
