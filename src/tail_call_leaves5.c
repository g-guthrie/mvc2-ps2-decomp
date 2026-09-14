typedef unsigned char u8;
typedef signed int s32;

extern void func_003DAA40(u8 *);
extern void func_001757E0();
extern void func_001E3D20();
extern void func_00175C00();

void func_001D3470(u8 *p) { p[4] = 0; p[316] = 0; func_003DAA40(p); }

void func_001D6D00(u8 *p) { func_001757E0(p, 21, 6); }

void func_001DB0B0(u8 *p) { p[36] = 11; p[34] = 0; func_001757E0(p, 23, 7); }

void func_001DCDC0(u8 *p) { p[4]++; p[0] = 0; p[316] = 0; func_003DAA40(p); }

void func_001E3890(int x) { func_001E3D20(6, x & 255, 8, -1); }

void func_001E3CA0(int x) { func_001E3D20(5, x & 255, 8, -1); }

void func_001DF460(u8 *p, u8 *q) {
    p[4]++;
    p[316] = 0;
    q[704] = 0;
    q[731] = 1;
    func_00175C00(q, 0);
}
