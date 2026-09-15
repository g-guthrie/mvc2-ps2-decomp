typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_003DAA40();
extern void func_003928C0(u8 *);
extern void func_00394770(u8 *);
extern void func_001757E0();

void func_0037D920(void *p, u8 *q) { q[517] = 0; func_003DAA40(p, q); }

void func_003928B0(u8 *p) { p[4] = 3; p[316] = 0; func_003928C0(p); }

void func_00394760(u8 *p) { p[4] = 3; p[316] = 0; func_00394770(p); }

void func_00395160(u8 *p) { p[4]++; func_001757E0(p, 20, 6); }

void func_00395870(u8 *p) { p[4]++; func_001757E0(p, 20, 1); }

void func_00390630(u8 *p) {
    *(s32 *)(*(u8 **)(p + 24) + 780) = 0;
    p[5]++;
    func_001757E0(p, 23, 10);
}

void func_0038F2D0(u8 *p) {
    p[5]++;
    *(s16 *)(p + 318) = *(s16 *)(*(u8 **)(p + 24) + 318);
    func_001757E0(p, 21, 18);
}
