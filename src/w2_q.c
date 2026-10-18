typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
s32 func_00407928(s32 a0, s32 a1, s32 a2)
{
    extern u8 D_004BD3A8[], D_004BD3D8[], D_004BD408[];
    extern u8 *func_00406128();
    extern void func_0011D8F8();
    extern void func_00405DC8();
    s32 buf[5];
    u8 *h;
    s32 (*fn)();
    if (a0 == 0) {
        func_00405DC8(D_004BD3A8);
        return -1;
    }
    if (a1 == 0) {
        func_00405DC8(D_004BD3D8);
        return -1;
    }
    h = func_00406128(a0);
    if (h == 0) {
        func_00405DC8(D_004BD408);
        return -1;
    }
    func_0011D8F8(buf, 0, 0x14);
    fn = *(s32 (**)())(h + 0x60);
    buf[1] = a1;
    buf[2] = a2;
    if (fn != 0) return fn(buf, 5, 0, 0);
    return -1;
}
