typedef unsigned char u8;

extern void func_00175C00();
extern void func_00139900();
extern void func_00137FD0();
extern void func_003DAA40();

void func_00328B90(void *a, void *b) { func_00175C00(b, 7); }

void func_00328DE0(void *a, void *b) { func_00175C00(b, 3); }

void func_00329030(void *a, void *b) { func_00175C00(b, 4); }

void func_00329680(void *a, void *b) { func_00175C00(b, 5); }

void func_00329430(u8 *p) {
    p[4] = 3;
    func_00175C00(*(void **)(*(u8 **)(p + 24) + 476), 1);
}

void func_0032AF40(u8 *p) { p[4] = 5; func_00139900(p, 0); }

void func_0032AF50(u8 *p) { p[4] = 6; func_00137FD0(p); }

void func_0034B030(void *p, u8 *q) { q[709] = 1; func_003DAA40(p, q); }
