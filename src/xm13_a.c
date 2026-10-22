typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840[1];

s32 func_00184720(u8 *p) {
    extern void func_00191210();
    extern s32 func_00185E40(u8 *);
    extern s32 func_00185630(u8 *);
    extern void func_00185640(u8 *, s32);
    extern void func_00184AA0(u8 *);
    extern void func_00185490(u8 *);
    extern void func_00186440(u8 *);
    u16 b;
    u16 a1;
    u32 t;
    u8 *q;
    u16 s0;
    s8 s1;
    u32 a0;

    if (*(s8 *)(p + 0x203) != 0 || *(s8 *)(p + 0x207) != 0) return 0;
    func_00191210();
    if (p[0x20D] == 2) {
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) return 0;
    }
    t = p[0x1E4];
    a0 = *(u16 *)(p + 0x35C);
    if (t == 0x14) a0 = (u16)(a0 | *(u16 *)(p + 0x366));
    a0 = (u16)(a0 & 0x360);
    if (a0 == 0) return 0;
    if (t == 0x14) {
        q = *(u8 **)(p + 0x408);
        if (q == 0) return 0;
        if ((p[0x15A] & 0x20) != 0 || *(s8 *)(p + 0x1B2) == 0) return 0;
        a1 = a0;
        if ((a1 & 0x200) != 0) {
            if (*(u16 *)(((p[2] << 1) + (u32)D_004C2840[0]) + 0x106) != 0) {
                if (p[0x1FC] == 1) {
                    s1 = ((s8 *)q)[1];
                    s0 = 0x100;
                } else {
                    s1 = ((s8 *)q)[0];
                    s0 = 0x200;
                }
            } else {
                s1 = ((s8 *)q)[0];
                s0 = 0x200;
            }
        }
        if ((a1 & 0x100) != 0) {
            s1 = ((s8 *)q)[1];
            s0 = 0x100;
        }
        if ((a1 & 0x40) != 0) {
            if (*(u16 *)(((p[2] << 1) + (u32)D_004C2840[0]) + 0x106) != 0) {
                if (p[0x1FC] == 1) {
                    s1 = ((s8 *)q)[3];
                    s0 = 0x20;
                } else {
                    s1 = ((s8 *)q)[2];
                    s0 = 0x40;
                }
            } else {
                s1 = ((s8 *)q)[2];
                s0 = 0x40;
            }
        }
        if ((a1 & 0x20) != 0) {
            s1 = ((s8 *)q)[3];
            s0 = 0x20;
        }
        if (s1 == -1) return 0;
        *(s8 *)(p + 0x1EA) |= 0x11;
    } else {
        b = a0;
        if ((b & 0x200) != 0) {
            s1 = 0;
            s0 = 0x200;
        }
        if ((b & 0x40) != 0) {
            s1 = 0;
            s0 = 0x40;
        }
        if ((b & 0x100) != 0) {
            s1 = 2;
            s0 = 0x100;
        }
        if ((b & 0x20) != 0) {
            s1 = 2;
            s0 = 0x20;
        }
    }
    if (func_00185E40(p) == 0) return 0;
    p[0x1FC] = s1;
    a0 = s0;
    *(u16 *)(p + 0x20E) = *(s16 *)(p + 0x35E) & 0x3C00;
    if ((a0 & 0x300) != 0) p[0x212] = 0;
    else p[0x212] = 1;
    if (*(u16 *)(((p[2] << 1) + (u32)D_004C2840[0]) + 0x106) != 0) {
        if ((a0 & 0x240) != 0) { t = p[0x1B7]; p[0x1B7] = t + 1; }
        else p[0x1B7] = 1;
    } else {
        if ((a0 & 0x240) != 0) p[0x1B7] = 0;
        else p[0x1B7] = 1;
    }
    if (p[0x1B7] > 1) p[0x1B7] = 1;
    t = p[0x1E4];
    if (t != 0xA) {
        if (t == 0xB || p[0x214] != 0) {
        } else {
            s32 r = func_00185630(p);
            if (r != 0) {
                func_00185640(p, r);
                return 1;
            }
        }
    }
    func_00184AA0(p);
    if (p[0x20D] != 2 || (p[0x20D] == 2 && p[0x210] != 0)) func_00185490(p);
    func_00186440(p);
    return 1;
}
