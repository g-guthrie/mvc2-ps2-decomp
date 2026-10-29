typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0022C970(void);
extern void func_0022D010(void);
extern void func_0022D070(void);
extern void func_0022D9F0(void);
extern void func_0022DE50(void);
extern void func_0022DFE0(void);
extern void func_0022E210(void);
extern void func_0022E630(void);
extern void func_0022F160(void);
extern void func_00232670(void);
extern void func_00232840(void);
extern void func_00232920(void);
extern void func_00232B50(void);
extern void func_00232E80(void);
extern void func_00232E90(void);
extern void func_00232EF0(void);
extern void func_00232F50(void);
extern void func_00232FC0(void);
extern void func_00233030(void);
extern void func_002330F0(void);
extern void func_00233200(void);
extern void residual_0022DE70(void);
extern void residual_0022EC70(void);
const Mvc2Callback D_00451D70[28] = {
    func_0022D070,
    func_0022C970,
    func_0022D9F0,
    func_0022DE50,
    func_0022DFE0,
    func_0022E210,
    func_0022E630,
    residual_0022EC70,
    func_0022F160,
    func_00232840,
    func_00232920,
    func_00232B50,
    func_00232E80,
    func_0022D010,
    func_00232670,
    residual_0022DE70,
    func_00232E90,
    func_00232EF0,
    func_00232F50,
    func_00232FC0,
    0,
    0,
    0,
    func_00233200,
    func_00233030,
    func_002330F0,
    0,
    0,
};
