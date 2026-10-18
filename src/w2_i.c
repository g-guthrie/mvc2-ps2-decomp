typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00415A00(u32 flags)
{
    extern void func_003DF850();
    extern void func_003DD260();
    extern s32 D_004C2B34;
    extern s32 D_004C2B30;
    u8 buf[0x40];
    s32 a, b, v, r;
    func_003DF850(0x65, 1);
    a = (flags & 1) ? 1 : 2;
    func_003DF850(0x15, a);
    b = (flags & 2) ? 1 : 0;
    func_003DF850(0x61, b);
    func_003DD260(buf);
    func_003DF850(0x1A, (s32)buf);
    v = 0;
    if (D_004C2B34 & 4) {
        if (flags & 4) {
            v = 0x8000;
        }
        if (b == 0) {
            v = 0;
        }
    }
    func_003DF850(0x12, v);
    if (D_004C2B30 == 0) {
        r = 0;
    } else {
        r = 0;
        if (a == 1) {
            if (b == 1) {
                r = 1;
                func_003DF850(0x12, 0x8000);
            }
        }
    }
    func_003DF850(0xC, r);
}
