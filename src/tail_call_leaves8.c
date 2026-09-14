typedef unsigned char u8;
typedef signed char s8;

extern void func_001757E0();
extern void func_002301C0();
extern void func_002320D0();

void func_0022EDE0(u8 *p) {
    p[33] = 3;
    p[361] = 19;
    p[360] = 2;
    func_001757E0(p, p[361], p[360]);
}

void func_0022EE10(u8 *p) {
    p[33] = 4;
    p[361] = 19;
    p[360] = 3;
    func_001757E0(p, p[361], p[360]);
}

void func_00230260(void *p, u8 *q) { q[21] = 1; func_002301C0(p, q); }

void func_00232460(void *p, s8 *q) { q[21] = -1; func_002320D0(p, q); }

void func_00267E20(u8 *p) { p[6] = 1; p[7] = 0; func_001757E0(p, 22, 28); }

void func_00269D10(u8 *p) { p[6] = 1; p[7] = 0; func_001757E0(p, 22, 28); }
