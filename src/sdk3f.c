typedef signed int s32;
typedef signed long long s64;
extern s32 D_004C2238, D_004C220C;
extern char D_0062CFE0[], D_00478E78[];
extern s64 D_004C2338, D_004C2340;
extern volatile s64 D_004C22F0;
extern void func_0011D8F8(void *p, s32 v, s32 n);
extern void func_003FDE38(void);
extern void func_00103C20(void);

void func_003F5F40(void) {
    if (--D_004C220C == 0) func_0011D8F8(D_00478E78, 0, 0x180);
}
void func_003FDE40(void) {
    while (!D_004C2338) {
        D_004C22F0++;
        func_003FDE38();
    }
    D_004C2340 = 1;
    func_00103C20();
}
s32 func_003F7970(void) {
    if (--D_004C2238 == 0) func_0011D8F8(D_0062CFE0, 0, 0x800);
}
