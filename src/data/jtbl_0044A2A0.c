typedef unsigned char u8;
typedef void (*Mvc2OwnerCallback)(u8 *, u8 *);

extern void func_00195750(u8 *, u8 *);
extern void func_001956E0(u8 *, u8 *);
extern void func_00195690(u8 *, u8 *);

/* Native func_00195920 dispatches with p and owner q; each target reads A1. */
const Mvc2OwnerCallback jtbl_0044A2A0[3] = {
    func_00195750,
    func_001956E0,
    func_00195690,
};
