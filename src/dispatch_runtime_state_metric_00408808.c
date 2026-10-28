typedef signed char s8;
typedef signed int s32;

extern s8 D_004872F1;
extern s32 func_004087A0(void);
extern s32 func_004087B8(void);

s32 func_00408808(void)
{
    s8 mode = D_004872F1;
    if (mode == 1)
        return (s32)((unsigned int)func_004087A0() * 2u);
    if (mode == 2)
        return func_004087B8();
    return 0;
}

/* Follows func_00408808 so EE GCC 2.96 treats that call as non-throwing;
   reorg then fills the second bne's slot with the fall-through lui. */
extern volatile s32 D_0048732C;
extern volatile s32 D_00487344;
extern s8 D_004872F0[];
extern char D_004BD6A8[], D_004BD6B8[], D_004BD6D8[], D_004BD6F8[];
extern char D_004BD718[], D_004BD738[], D_004BD758[];
extern s32 func_0011EB60(const char *, ...);

s32 func_00408858(void)
{
    func_0011EB60(D_004BD6A8);
    func_0011EB60(D_004BD6B8, D_0048732C);
    func_0011EB60(D_004BD6D8, D_00487344);
    func_0011EB60(D_004BD6F8, D_004872F0[2]);
    if (D_004872F0[1] == 1)
        func_0011EB60(D_004BD718);
    if (D_004872F0[1] == 2)
        func_0011EB60(D_004BD738);
    func_0011EB60(D_004BD758, func_00408808());
    return 0;
}
