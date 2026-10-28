/* MW 3.0 build 22 (mwcps2-3.0b22-020926) -O3 -sdatathreshold 0: exact. (3.0/3.0.3 give a pure s0<->s1 swap, 31/81.) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00200BD0(u8 *p)
{
    u8 s0;
    u8 *e;
    u32 t;
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32, s32);
    extern void func_00198100(u8 *, s32);
    extern void func_00190D50(u8 *, u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_00200990(u8 *);

    e = p + 0x2B8;
    if ((s8)func_00175700(p) < 0) {
        e[0xE] = 0;
        t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        func_001757E0(p, 0x16, 0xD, t + 1);
        return;
    }
    s0 = p[0x151];
    if (!s0) return;
    p[0x151] = 0;
    if (s0 == 0x3E) {
        func_00198100(p, 0);
        e = *(u8 **)e;
        *(u8 **)(e + 0x1C8) = p;
        e[0x1B5] = s0;
        *(s16 *)(e + 0x140) = *(s16 *)(p + 0x140);
        e[0x20A] = 0x11;
        e[0x20D] = 2;
        func_00190D50(e, p);
        func_00190D50(e, p);
    } else {
        e = *(u8 **)e;
        *(u8 **)(e + 0x1C8) = p;
        p[0x1B5] = s0;
        e[0x1B5] = s0;
        func_0018FDB0(p);
        func_00190D50(e, p);
        func_0018FDB0(p);
        func_00190D50(e, p);
    }
    func_00200990(p);
}
