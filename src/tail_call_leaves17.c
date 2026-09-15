typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_00350FE0(u8 *);
extern void func_00368FC0(u8 *);
extern void func_0036A8C0(u8 *);
extern void func_003DAA40();
extern void func_00359140();
extern void func_00175C00();

void func_00350FD0(u8 *p) { p[4] = 3; p[316] = 0; func_00350FE0(p); }

void func_00368FB0(u8 *p) { p[4] = 3; p[316] = 0; func_00368FC0(p); }

void func_0036A8B0(u8 *p) { p[4] = 3; p[316] = 0; func_0036A8C0(p); }

void func_003556C0(u8 *p) {
    (*(u8 **)(p + 24))[706] = 0;
    p[316] = 0;
    func_003DAA40(p);
}

void func_00359220(u8 *p, u8 *q) {
    p[5]++;
    *(u16 *)(q + 8) = 0xFFFF;
    func_00359140(p, q);
}

void func_00372B30(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    (*(s16 *)(q + 726))--;
    func_003DAA40(p);
}

void func_00374E10(u8 *p) {
    p[4]++;
    p[316] = 0;
    func_00175C00(*(void **)(p + 24), 0);
}
