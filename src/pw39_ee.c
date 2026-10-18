typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_0062FEC0[];
extern s32 D_0062FFC0[];
extern u8 D_00487FA0[];
extern void func_00411288(void);
extern void func_004112B0(void);
extern void func_00106E68();
extern char D_004BC6C8[];
extern char D_004BC6F8[];
extern void func_003FB128();
extern void func_00401868();
extern void func_003F9630(void);
extern s32 func_0040F0B8();
extern void func_00401640();
extern void func_003F9660(void);
extern char D_004BDDD8[];
extern char D_004BDDB0[];
extern s32 func_001089F0();
extern s32 func_0011EB60();
extern char D_004BE0E0[];
extern char D_004BE0F8[];
extern s32 D_004895D4;
extern void func_0040AF58();
extern void func_00408078();
extern void func_004084E8(void);
extern void func_0040B2E8(void);
extern void func_0040BCB8();

s32 func_00409708(s32 a, s32 *src, s32 n, s32 *out, s32 m) {
    s32 i;
    func_00411288();
    for (i = 0; i < n; i++) {
        D_0062FEC0[i] = src[i];
    }
    func_00106E68(D_00487FA0, a + 0x400, 0, D_0062FEC0, n * 4, D_0062FFC0, m * 4, 0, 0);
    for (i = 0; i < m; i++) {
        out[i] = D_0062FFC0[i];
    }
    func_004112B0();
    return D_0062FFC0[0];
}

s32 func_0011DE18(u32 *p) {
    u32 v = *p;
    s32 n;
    if ((v & 7) != 0) {
        if ((v & 1) != 0) return 0;
        if ((v & 2) != 0) {
            *p = v >> 1;
            return 1;
        }
        *p = v >> 2;
        return 2;
    }
    n = 0;
    if ((v & 0xFFFF) == 0) {
        n = 16;
        v >>= 16;
    }
    if ((v & 0xFF) == 0) {
        n += 8;
        v >>= 8;
    }
    if ((v & 0xF) == 0) {
        n += 4;
        v >>= 4;
    }
    if ((v & 3) == 0) {
        n += 2;
        v >>= 2;
    }
    if ((v & 1) == 0) {
        v >>= 1;
        n += 1;
        if (v == 0) return 32;
    }
    *p = v;
    return n;
}

void func_00402DE0(u8 *a, s32 b, s32 c) {
 s32 r;
 if (a == 0 || b == 0 || c < 0) {
  func_003FB128(D_004BC6C8);
  return;
 }
    func_00401868(a);
    func_003F9630();
    r = func_0040F0B8(b, c);
    if (r == 0) {
        func_003F9660();
        func_003FB128(D_004BC6F8);
        return;
    }
    func_00401640(a, r);
    a[2] = 2;
    a[0x98] = 0;
    func_003F9660();
}

s32 func_0040B110(s32 h) {
    u32 i = 0;
    s32 buf;
    s32 r;
    while (1) {
        r = func_001089F0(h, 1, &buf);
        if (r < 0) {
            func_0011EB60(D_004BDDB0, h, r);
            return 0;
        }
        if (buf == 0) break;
        if (i > 0x29810) func_0011EB60(D_004BDDD8);
        i++;
    }
    return 1;
}

void func_0040BBB8(u8 *p) {
    s32 i = 0;
    s32 t;
    if (p == 0) {
        func_0040AF58(p, D_004BE0E0);
        return;
    }
    if (p[2] < 2) return;
    if (*(s32 *)(p + 0x2C) != 0) func_00408078(*(s32 *)(p + 0x2C));
    for (;;) {
        func_004084E8();
        func_0040B2E8();
        func_0040BCB8(p);
        t = (s8)p[2];
        if (t != 2) {
            *(s32 *)(p + 0x28) = 0;
            break;
        }
        i++;
        if (i > 0x9FFFF) {
            if (D_004895D4 != t) func_0011EB60(D_004BE0F8);
            *(s32 *)(p + 0x28) = 0;
            break;
        }
    }
    p[2] = 0;
}
