typedef unsigned char u8;
typedef signed int s32;

extern void func_00175700();
extern void func_001757E0();
extern void func_00176160();
extern void func_0030AF90(u8 *);
extern void func_001843A0();

void func_002F5420(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    p[432] = 0;
    p[512] = 3;
    func_00175700(p);
}

void func_00306AA0(u8 *p) { func_001757E0(p, 19, 1); }

void func_00308A50(void *p, u8 *q) { q[8] = 1; func_00176160(p, 3, 2, 1); }

void func_0030AA20(u8 *p) { func_001757E0(p, 19, 2); }

void func_0030AA30(u8 *p) { func_001757E0(p, 19, 3); }

void func_0030AF60(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    p[828] = 5;
    p[6]++;
    func_0030AF90(p);
}

void func_0030F650(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}
