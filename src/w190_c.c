typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w190_c.c "-O3 -sdatathreshold 0" */

static void func_002555E0(u8 *p) { *(s32 *)(p + 0x100) = 0; }
extern s32 func_00175700(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_0025A300(u8 *p) {
    func_002555E0(p);
    if (p[0x20D] != 2) {
        if (*(s8 *)(p + 0x153) < 0) {
            p[6] = 4;
            func_00175C00(p, 0);
            func_001757E0(p, 0x16, 3);
            return;
        }
    } else {
        if (*(s8 *)(p + 0x153) < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_00175C00(p, 0);
            func_001757E0(p, 0x16, 4);
            return;
        }
    }
    func_00175700(p);
    func_00175C00(p, 0);
    if (*(s8 *)(p + 0x151) == 3) func_00175C00(p, 4);
}

extern u8 D_00450EC0[];
extern void func_00219250(u8 *);
extern void func_002192B0(u8 *);
extern void func_00219490(u8 *);
extern void func_00184540(u8 *);


void func_00218F20(u8 *p) {
    u8 *q = (u8 *)((s32)p + 0x2B8);
    if ((s8)func_00175700(p) < 0) {
        if (q[1] != 0) {
            u16 m = *(s16 *)(p + 0x354) & 0x3C00;
            if (m != 0) {
                u16 i = (u32)m >> 10;
                u32 r;
                if (p[0x1E6] != 0) i += 0x10;
                r = D_00450EC0[i];
                if (r != 0) {
                    p[0x22] = r - 1;
                    p[0x20D] = 2;
                    p[7] = 0;
                    q[0] = 1;
                    q[1] = 0;
                    func_00219250(p);
                    func_002192B0(p);
                    func_00219490(p);
                    return;
                }
            }
        }
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x1E9] = 1;
        *(s8 *)(p + 0x1E7) = -1;
        func_00184540(p);
    } else {
        u16 w = *(s16 *)(p + 0x354) & 0x360;
        if (w != 0) q[1] = 1;
    }
}



extern void func_0035EE90(u8 *, u8 *);
extern void func_001E7F60(u8 *);

void func_0035ECF0(u8 *s, u8 *a) {
    u8 *q = (u8 *)((s32)a + 0x2B8);
    if (a[5] != 0 || a[0x1E4] != 0x1D || a[0x1FD] != 3) {
        s[4] = 3;
        s[0x13C] = 0;
    } else {
        if (s[0x20] == 0) {
            if (s[0x21] == 0 && *(s8 *)(s + 0x1B2) != 0) {
                func_0035EE90(s, a);
                return;
            }
            if ((s8)func_00175700(s) < 0) {
                if (*(s8 *)(q + 2) != 0 && *(s8 *)(q + 3) != 0) return;
                {
                    u32 t = s[4];
                    s[4] = t + 1;
                    q[3] = 0;
                    func_001757E0(s, 0x17, (u8)(s[0x20] + 0xE));
                }
            }
            func_001E7F60(s);
        } else {
            func_00175700(s);
            if (*(s8 *)(q + 3) == 0) {
                u32 t = s[4];
                s[4] = t + 1;
                func_001757E0(s, 0x17, (u8)(s[0x20] + 0xE));
            }
        }
    }
}
