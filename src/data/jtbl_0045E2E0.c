typedef void (*PhaseStateHandler)(void);

extern void func_0032C320(void);
extern void func_0032C390(void);
extern void func_0032C3F0(void);
extern void func_0032C4E0(void);
extern void func_0032C520(void);
extern void func_0032C560(void);
extern void func_0032C5D0(void);
extern void func_0032C630(void);
extern void func_0032C680(void);
extern void func_0032C750(void);

/* func_0032C230 dispatches the initialized 0..9 substate. */
const PhaseStateHandler jtbl_0045E2E0[10] = {
    func_0032C320,
    func_0032C390,
    func_0032C3F0,
    func_0032C4E0,
    func_0032C520,
    func_0032C560,
    func_0032C5D0,
    func_0032C630,
    func_0032C680,
    func_0032C750
};
