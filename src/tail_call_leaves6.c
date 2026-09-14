typedef unsigned char u8;
typedef signed int s32;

extern void func_001E3D20();
extern void func_001E3710();
extern void func_001757E0();
extern void func_001843A0();

void func_001E3CC0(int x) { func_001E3D20(5, x & 255, 8, -1); }

void func_001E3CE0(int x) { func_001E3D20(7, x & 255, 8, -1); }

void func_001F72E0(void **pp) { func_001E3710(pp[119], 49); }

void func_001FE9B0(u8 *p) { p[708] = 9; func_001757E0(p, 19, 7); }

void func_001FE9D0(u8 *p) { p[708] = 9; func_001757E0(p, 19, 8); }

void func_00202EB0(u8 *p) { p[6]++; func_001757E0(p, 20, 2); }

void func_0020AB10(u8 *p) { func_001757E0(p, 19, 2); }

void func_00203340(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}
