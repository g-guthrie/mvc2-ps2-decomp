typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18D8[];
extern u8 D_004D18D9[];
extern u8 D_004D18E2[];

void func_003278C0(u8 *p, u8 *a, u8 *b)
{
    extern void func_00186A60(u8 *, s32);
    extern void func_00191210(u8 *);
    s32 cnt;
    u32 flags;
    s8 nv;
    s32 t;

    if (p[0] == 0) {
        p[0x205] = 60;
        p[0] = 1;
        p[4] = 1;
        p[5] = 0;
        func_00186A60(p, 0);
        return;
    }
    if (a[0] == 0 && b[0] == 0) {
        D_004D18D9[0] &= ~(1 << (s8)p[2]);
        if (p[0x269] != 4) {
            D_004D18D8[0] &= ~(1 << (s8)p[2]);
            D_004D18E2[p[2]] = 0;
            return;
        }
    }
    flags = D_004D18E2[p[2]];
    cnt = 0;
    if ((flags & 1) && p[5] == 0) {
        t = p[0x1E4];
        if (t != 0x1D && t != 0x15) cnt++;
    }
    if (a[0] != 0 && a[5] == 0) {
        t = a[0x1E4];
        if (t != 0x1C && t != 0x17 && t != 0x15 && t != 0x1D && a[0x20D] != 2) {
            if (flags & 2) cnt++;
            if (a[0x269] == 8) {
                a[0x26A] = 0xB;
            } else {
                a[0x26A] = 2;
                a[0x1B1] = 0;
                a[0x201] = 3;
            }
            func_00186A60(a, 0x1C);
            a[7] = 0;
            a[6] = 0;
            func_00191210(a);
        }
    }
    if (b[0] != 0 && b[5] == 0) {
        t = b[0x1E4];
        if (t != 0x1C && t != 0x17 && t != 0x15 && t != 0x1D && b[0x20D] != 2) {
            if (flags & 4) cnt++;
            if (b[0x269] == 8) {
                b[0x26A] = 0xB;
            } else {
                b[0x26A] = 2;
                b[0x1B1] = 0;
                b[0x201] = 3;
            }
            func_00186A60(b, 0x1C);
            b[7] = 0;
            b[6] = 0;
            func_00191210(b);
        }
    }
    nv = (s8)p[0x26D] - cnt;
    p[0x26D] = nv;
    if (nv == 0) {
        D_004D18D8[0] &= ~(1 << (s8)p[2]);
        D_004D18D9[0] &= ~(1 << (s8)p[2]);
    }
}
