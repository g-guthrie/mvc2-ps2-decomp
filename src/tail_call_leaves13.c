typedef unsigned char u8;
typedef signed int s32;

extern void func_0011D8F8();
extern void func_001843A0();
extern void func_001757E0();
extern void func_00175700();

void func_002F1D70(u8 *p) {
    p[534] = 0;
    p[537] = 0;
    p[538] = 0;
    func_0011D8F8(p + 696, 0, 128);
}

void func_002F1DF0(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}

void func_002F3BF0(u8 *p) { func_001757E0(p, 19, 7); }

void func_002F3C00(u8 *p) { func_001757E0(p, 19, 8); }

void func_002F3D30(u8 *p) { p[7]++; func_001757E0(p, 19, 1); }

void func_002F52A0(u8 *p) { p[1036] = 2; p[828] = 5; func_00175700(p); }
