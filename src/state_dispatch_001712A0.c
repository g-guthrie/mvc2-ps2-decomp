typedef signed char s8;
typedef void (*Handler)(void);
extern s8 *D_004C2840;
extern const Handler jtbl_00446A80[7];

void func_001712A0(void)
{
    jtbl_00446A80[D_004C2840[3]]();
}

void func_001712D0(void)
{
}
