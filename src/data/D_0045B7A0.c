typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002ED9F0(void);
extern void func_002EE110(void);
extern void func_002EE280(void);
extern void func_002EE790(void);
extern void func_002EED70(void);
extern void func_002EEEC0(void);
extern void func_002EEFF0(void);
extern void func_002EF1A0(void);
extern void func_002EF220(void);
extern void func_002EF2B0(void);
extern void func_002F1510(void);
extern void func_002F16F0(void);
extern void func_002F1780(void);
extern void func_002F1840(void);
extern void func_002F1D70(void);
extern void func_002F1E10(void);
extern void func_002F1E50(void);
extern void func_002F1EA0(void);
extern void func_002F1EF0(void);
extern void func_002F1F40(void);
extern void residual_002EED90(void);
const Mvc2Callback D_0045B7A0[28] = {
    func_002EE280,
    func_002ED9F0,
    func_002EE790,
    func_002EED70,
    func_002EEEC0,
    func_002EEFF0,
    func_002EF1A0,
    func_002EF220,
    func_002EF2B0,
    func_002F16F0,
    func_002F1780,
    func_002F1840,
    func_002F1E10,
    func_002EE110,
    func_002F1510,
    residual_002EED90,
    func_002F1E50,
    func_002F1EA0,
    func_002F1EF0,
    func_002F1F40,
    0,
    0,
    0,
    func_002F1D70,
    0,
    0,
    0,
    0,
};
