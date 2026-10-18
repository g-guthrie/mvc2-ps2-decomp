typedef signed int s32;

extern s32 D_004C2438;
extern char D_004BD898[], D_004BD8B0[], D_00487358[];
extern void func_0011EB60();
extern void func_0011D8F8(void *, s32, s32);
void func_00408D48(void) {
    func_0011EB60(D_004BD898, D_004C2438);
    if (D_004C2438 == 0) func_0011D8F8(D_00487358, 0, 0x800);
    D_004C2438++;
    func_0011EB60(D_004BD8B0);
}

extern char D_004BE478[], D_004BE4A8[], D_004BE4D8[];
extern s32 D_004C24A0, D_004C24A4, D_004C247C, D_004C2480;
void func_0040DB10(s32 a, s32 b) {
    s32 n;
    if (a < 0) { func_0011EB60(D_004BE478, a); return; }
    if (b < 0) { func_0011EB60(D_004BE4A8, b); return; }
    n = a * 2 + b;
    if (n > 16) { func_0011EB60(D_004BE4D8, 16); return; }
    D_004C24A0 = a;
    D_004C24A4 = b;
    D_004C247C = n;
    D_004C2480 = (n * 65) << 8;
}
