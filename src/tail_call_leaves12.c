typedef unsigned char u8;
typedef signed int s32;

extern void func_001757E0();
extern void func_001843A0();
extern void func_00178F20();

void func_002B6AF0(u8 *p) { p[1036] = 2; p[828] = 5; p[6]++; func_001757E0(p, 21, 24); }

void func_002B7CD0(u8 *p) { func_001757E0(p, 15, 3); }

void func_002D3110(u8 *p) { func_001757E0(p, 19, 3); }

void func_002D3120(u8 *p) { func_001757E0(p, 19, 2); }

void func_002E0CE0(void *a, void *b) { func_00178F20(b, a); }

void func_002DC1B0(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}
