typedef unsigned char u8;
typedef void (*CallbackWithOwner)(u8 *, u8 *);
typedef void (*CallbackObject)(u8 *);
typedef void (*CallbackNoArgs)(void);
/* Native consumer uses this second-root alias at owner offset +0x10. */
extern const CallbackObject jtbl_0044ECC0[3];
extern void func_001DCF50(u8 *, u8 *);
extern void func_001DD3A0(u8 *, u8 *);
extern void func_001DD440(void);
extern void func_001DD450(u8 *);
extern void func_001DD020(u8 *);
extern void func_001DD130(u8 *);
extern void func_001DD270(u8 *);
typedef struct {
    CallbackWithOwner initialize;
    CallbackWithOwner update;
    CallbackNoArgs no_op;
    CallbackObject finish;
    CallbackObject random_modes[3];
} DispatchOwner;
const DispatchOwner jtbl_0044ECB0 = {
    func_001DCF50,
    func_001DD3A0,
    func_001DD440,
    func_001DD450,
    { func_001DD020, func_001DD130, func_001DD270 },
};
