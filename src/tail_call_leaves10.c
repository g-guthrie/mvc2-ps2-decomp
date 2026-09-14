typedef unsigned char u8;
typedef signed int s32;

extern void func_0028C620(u8 *);
extern void func_00293990(u8 *);
extern void func_00175700();
extern void func_001757E0();
extern void func_001843A0();

void func_0028C5F0(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    p[6]++;
    p[706] = 0;
    func_0028C620(p);
}

void func_00293960(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    p[6]++;
    p[706] = 0;
    func_00293990(p);
}

void func_00290210(u8 *p) { p[826] = 255; func_00175700(p); }

void func_00298AE0(u8 *p) { p[1036] = 2; p[828] = 5; p[6]++; func_001757E0(p, 22, 9); }

void func_00299780(u8 *p) { p[1036] = 2; p[828] = 5; p[6]++; func_001757E0(p, 22, 8); }

void func_0029B130(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}
