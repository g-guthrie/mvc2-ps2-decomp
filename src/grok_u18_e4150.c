typedef signed int s32;

extern void *D_004C2B50;
extern s32 func_00401920(void *);
extern void func_004026B0(void *, s32);
extern void func_00401868(void *);

void func_001E4150(void)
{
    s32 r;

    r = func_00401920(D_004C2B50);
    if (r == 0 || r == 5)
        return;
    if (D_004C2B50 == 0)
        return;
    func_004026B0(D_004C2B50, 1);
    func_00401868(D_004C2B50);
}
