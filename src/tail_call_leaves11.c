typedef unsigned char u8;

extern void func_002A2E80(u8 *);
extern void func_001757E0();

void func_002A3550(u8 *p) { p[7]++; func_002A2E80(p); }

void func_002B0FD0(u8 *p) {
    p[1037] = 0;
    p[1036] = 0;
    p[827] = 0;
    p[828] = 0;
    p[6]++;
    func_001757E0(p, 22, 10);
}

void func_002B4A00(u8 *p) { func_001757E0(p, 19, 2); }

void func_002B4A10(u8 *p) { func_001757E0(p, 19, 3); }

void func_002B4A20(u8 *p) { func_001757E0(p, 19, 3); }

void func_002B69D0(u8 *p) { p[6]++; p[1036] = 2; p[828] = 5; func_001757E0(p, 21, 20); }

void func_002B6A70(u8 *p) { p[1036] = 2; p[828] = 5; p[6]++; func_001757E0(p, 21, 21); }
