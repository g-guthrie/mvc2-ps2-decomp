typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004C2ABC;

void func_001538B0(u8 *a0, u8 *a1, u8 *a2) {
    extern void func_003DE3A0();
    extern void func_003DE160();
    extern void func_003DF850(s32, s32);
    extern void func_001537D0(s32, s32, f32, f32);
    extern void func_003F0500(s32, s32);
    u8 buf[0x40];
    u8 *t;
    u8 *e;
    u32 first;
    u32 c;
    u8 *n;
    u8 *o;
    u8 *q;
    u32 k;
    q = a2;
    o = a0;
    n = a1;
    first = 0;
    t = *(u8 **)(o + 0x84);
    do {
        if (first == 0) {
            first = 1;
            func_003DE3A0(buf, a2);
        } else {
            func_003DE160(buf, n + 0x54);
        }
        func_003DF850(0x19, (s32)buf);
        k = *(s32 *)(n + 0x180);
        if (k != -1) {
            e = *(u8 **)(t + 0x14) + k * 180;
            if (*(s32 *)e != -1) {
                c = D_004C2ABC;
                if (*(u32 *)(e + 4) & 0x200) {
                    func_003DF850(0x66, ((((c >> 24) & 0xFF) >> 1) << 24) | (((c >> 16) & 0xFF) << 16) | (((c >> 8) & 0xFF) << 8) | (c & 0xFF));
                }
                func_001537D0(*(s32 *)(o + 0xD0), *(s32 *)(e + 4), *(volatile f32 *)(o + 0xE0), *(f32 *)(o + 0xE4));
                func_003F0500(*(s32 *)e, 0);
                if (*(u32 *)(e + 4) & 0x200) {
                    func_003DF850(0x66, c);
                }
            }
        }
        if (*(u8 **)(n + 0x10) != 0) {
            n = *(u8 **)(n + 0x10);
            a2 = buf;
        } else {
            n = *(u8 **)(n + 0xC);
            if (n == 0) break;
            a2 = q;
        }
    } while (1);
}
