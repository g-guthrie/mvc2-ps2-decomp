typedef unsigned char u8;
typedef void (*Mvc2Callback)(void);
extern void func_00231F60(void);
extern void func_00232020(void);
extern void func_002320D0(void);
extern void func_002322C0(u8 *, u8 *);
extern void func_002323D0(void);
const Mvc2Callback jtbl_00452020[5] = {
    func_00231F60,
    func_00232020,
    func_002320D0,
    (Mvc2Callback)func_002322C0,
    func_002323D0,
};
