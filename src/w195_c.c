typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_001E3210(u8 *, s32);
extern s32 func_0027C570(u8 *);
extern void func_00175910(u8 *, s32, s32, s32);
extern void func_00176160(u8 *, s32, s32, s32);
extern void func_00176090(u8 *, s32, s32, s32);

void func_0027C3F0(u8 *p) {
    extern void func_00175700(u8 *);
    u8 t;
    u32 u;
    p[0x33C] = 5;
    func_00175700(p);
    t = p[0x22];
    if (t != 0) {
        t = t - 1;
        p[0x22] = t;
        if (t == 0) {
            func_001E3210(p, 0xA);
        }
    }
    if (func_0027C570(p) < 0) {
        u = p[6];
        p[6] = u + 1;
        func_00175910(p, 0x15, 5, *(s8 *)(p + 0x150));
    }
    u = p[7];
    p[7] = u + 1;
    if (p[7] == 2) {
        func_00176160(p, 5, 0, 1);
    }
    if (p[7] == 4) {
        p[7] = 0;
        func_00176090(p, 5, 5, 1);
    }
}

extern void func_001843A0(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_001D91E0(u8 *, s32, s32);

void func_002FD1D0(u8 *p) {
    extern s8 func_00175700(u8 *);
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (*(s8 *)(p + 0x150) != 0) {
            func_00176160(p, 0, (s8)(*(s8 *)(p + 0x150)) + 0x16 + (s32)((u32)p[0x25] << 5), 1);
        } else {
            func_00175C00(p, 0);
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_001D91E0(p, 1, 0);
        }
        break;
    }
}
