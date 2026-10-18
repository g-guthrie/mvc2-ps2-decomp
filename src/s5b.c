typedef signed int s32;
extern char D_00479CF8[];
extern void (*D_004C22A0)(s32, void *);
extern s32 D_004C22A4;
extern void func_00120440(void *, void *, s32);
extern void func_004112D8(void *);
void func_003FB128(void *s) {
    func_00120440(D_00479CF8, s, 0xFF);
    if (D_004C22A0) D_004C22A0(D_004C22A4, D_00479CF8);
    func_004112D8(D_00479CF8);
}
