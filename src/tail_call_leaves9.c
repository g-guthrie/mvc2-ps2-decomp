typedef unsigned char u8;

extern void func_001757E0();
extern void func_00179160();
extern void func_00185640();
extern void func_00175700();

void func_0026CA90(u8 *p) { func_001757E0(p, 19, 2); }

void func_0026CAA0(u8 *p) { func_001757E0(p, 19, 0); }

void func_00272AD0(void **pp) { func_00179160(pp[119], pp); }

void func_0027F6E0(u8 *p) { p[510] = 1; func_00175700(p); }

void func_00282540(u8 *p) { p[7]++; func_001757E0(p, 21, 24); }

void func_002886D0(u8 *p) { p[826] = 255; func_00175700(p); }

void func_00276230(u8 *p) {
    void *arg = *(void **)(p + 452);
    u8 *q = *(u8 **)(p + 544);
    q[523] = 194;
    p[523] = 194;
    func_00185640(p, arg);
}
