extern int D_004C2B10[2];
void func_00411898(int a, int b) { D_004C2B10[0] = a; D_004C2B10[1] = b; }
extern int D_004C2B20[2];
extern void func_00411288(void);
extern void func_004112B0(void);
void func_00411858(int a, int b) {
    func_00411288();
    D_004C2B20[0] = a;
    D_004C2B20[1] = b;
    func_004112B0();
}
