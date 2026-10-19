typedef unsigned char u8;
typedef signed int s32;

extern s32 func_0012DE70(void *);
extern s32 func_0012DF30(void *);
extern void func_0012E1A0(void *);
extern u8 D_004CAB70[];
extern u8 D_004CAB40[];
extern u8 D_004CAAF0[];
extern u8 D_004CAB20[];
extern u8 D_004CAB0C;
extern u8 D_004CAB5A;
extern u8 D_004CAB5B;
extern u8 D_004CAB7A;
extern u8 D_004CAB7B;
extern u8 D_004CAB0A;
extern u8 D_004CAB0B;
extern u8 D_004C2610 __attribute__((section(".sdata")));
extern u8 D_004C260C __attribute__((section(".sdata")));

void func_0012DD90(void)
{
    s32 r;
    if (func_0012DE70(D_004CAB70))
        return;
    if (func_0012DF30(D_004CAB40))
        return;
    r = func_0012DF30(D_004CAAF0);
    if (r) {
        if (r >= 0)
            return;
        if (D_004CAB0C)
            return;
        D_004C2610 |= D_004C260C;
        return;
    }
    if (D_004CAB5A != D_004CAB5B)
        return;
    if (D_004CAB7A != D_004CAB7B)
        return;
    if (D_004CAB0A != D_004CAB0B)
        return;
    func_0012E1A0(D_004CAB20);
}
