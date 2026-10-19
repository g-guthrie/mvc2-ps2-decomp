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

extern const Handler jtbl_00446780[];
void func_0016E960(void)
{
    jtbl_00446780[D_004C2840[0x92]]();
}
