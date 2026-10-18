typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00275FD0(u8 *p) {
    extern void func_00175700();
    extern void func_001843A0();
    extern void func_001830D0();
    extern void func_001BAD80();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s32 *)(p + 0x2E0) == 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[0x151] = 0;
    }
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        p[0x405] = (p[0x269] == 6) ? 2 : 0;
        v[0] = 0xC1855555;
        v[1] = 0x43520000;
        func_001830D0(p, v, 1);
        func_001BAD80(p, 0);
        func_001BAD80(p, 1);
    }
}

void func_002E3240(u8 *p) {
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_00183D10();
    if (*(u16 *)(p + 0x1C2) & 0x80) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(u16 *)(p + 0x1C2) = 0;
            func_001757E0(p, 0x15, 0x15);
            return;
        }
        func_00175700(p);
    } else {
        u32 t = p[6];
        u8 *q;
        p[6] = t + 1;
        *(u16 *)(p + 0x1C2) = 0;
        if (p[0x1B7] != 0) {
            p[6] = 4;
            p[0x201] = 2;
            q = *(u8 **)(p + 0x1C8);
            if (q != 0) q[0x1B4] = 0x10;
            func_001757E0(p, 0x16, 0xD);
            func_00183D10(p);
        } else {
            func_001757E0(p, 0x15, 0x14);
        }
    }
}

extern void (*D_00463840[])();

void func_00367830(u8 *p) {
    extern void func_00176160();
    extern void func_00176090();
    s16 v;
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0x22] != 0) {
        if (*(s16 *)(p + 0x1C) & 2) {
            func_00176160(q, 2, 2, 1);
        } else {
            func_00176090(q, 2, 2, 1);
        }
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[0x22] = 0;
            *(s16 *)(p + 0x1C) = 0x3C;
        }
    } else {
        func_00176090(q, 2, 2, 1);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[0x22] = 1;
            *(s16 *)(p + 0x1C) = 10;
        }
    }
    D_00463840[p[5]](p);
}
