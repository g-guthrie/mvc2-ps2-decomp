/* The seven entries are no-argument state callbacks, selected by the global state byte. */
typedef void (*StateHandler)(void);

extern void func_001712F0(void);
extern void func_00171640(void);
extern void func_001716C0(void);
extern void func_001716D0(void);
extern void func_00172310(void);
extern void func_001712D0(void);
extern void func_001712E0(void);

const StateHandler jtbl_00446A80[7] = {
    func_001712F0,
    func_00171640,
    func_001716C0,
    func_001716D0,
    func_00172310,
    func_001712D0,
    func_001712E0,
};
