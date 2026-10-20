typedef unsigned char u8;
typedef void (*Mvc2OwnerPhaseCallback)(u8 *, u8 *);

extern void func_001AB210(u8 *, u8 *);
extern void func_001AB2E0(u8 *, u8 *);
extern void func_001AB360(u8 *, u8 *);
extern void func_001AB430(u8 *, u8 *);
extern void func_001AB630(u8 *, u8 *);
extern void func_001AB6E0(u8 *, u8 *);
extern void func_001AB780(u8 *, u8 *);
extern void func_001AB840(u8 *, u8 *);
extern void func_001AB8B0(u8 *, u8 *);
extern void func_001AB970(u8 *, u8 *);
extern void func_001ABA00(u8 *, u8 *);
extern void func_001ABAD0(u8 *, u8 *);
extern void func_001ABB50(u8 *, u8 *);
extern void func_001ABBE0(u8 *, u8 *);
extern void func_001ABC40(u8 *, u8 *);

/* func_001AB160 preserves owner q in A1 across this indexed dispatch. */
const Mvc2OwnerPhaseCallback jtbl_0044B770[15] = {
    func_001AB210,
    func_001AB2E0,
    func_001AB360,
    func_001AB430,
    func_001AB630,
    func_001AB6E0,
    func_001AB780,
    func_001AB840,
    func_001AB8B0,
    func_001AB970,
    func_001ABA00,
    func_001ABAD0,
    func_001ABB50,
    func_001ABBE0,
    func_001ABC40,
};
