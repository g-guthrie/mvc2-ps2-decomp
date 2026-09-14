typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00175700();
extern void func_00179160();
extern void func_00184540();
extern void func_001E3210();
extern void func_001266A0();
extern void func_001757E0();
extern void func_0011D8F8();

void func_00212230(u8 *p) { p[700] = 255; func_00175700(p); }

void func_0021C0E0(void *p, u8 *q) { *(s16 *)(q + 28) ^= 1; func_00179160(p, q); }

void func_00220F50(s8 *p) {
    p[492] = 0;
    p[528] = 0;
    p[488]++;
    p[489] = 0;
    p[493] = 0;
    func_00184540(p);
}

void func_002215B0(u8 *p) {
    p[6]++;
    p[1036] = 2;
    p[828] = 5;
    func_001E3210(p, 24);
}

void func_002220B0(u8 *p) { p[6] = 0; p[436] = 10; func_001266A0(p, 5, 5); }

void func_0022B7C0(u8 *p) { func_001757E0(p, 15, 3); }

void func_0022C690(u8 *p) {
    p[534] = 0;
    p[537] = 0;
    p[538] = 0;
    func_0011D8F8(p + 696, 0, 128);
}
