typedef signed int s32;
extern s32 D_004C22CC, D_004C232C, D_004C239C;
extern void func_003FE7F0(void), func_003FE860(void), func_003FE940(void);
extern void func_00103C70(s32, s32);
extern void func_00411898(s32, s32), func_004118A8(s32, s32), func_00411BC8(void);
void func_003FE710(void) {
    if (--D_004C22CC == 0) {
        func_003FE7F0();
        func_003FE860();
        func_003FE940();
        func_00103C70(D_004C232C, D_004C239C);
        func_00411898(0, 0);
        func_004118A8(0, 0);
        func_00411BC8();
    }
}
