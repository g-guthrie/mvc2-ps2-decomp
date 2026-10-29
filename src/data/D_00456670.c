typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00286280(void);
extern void func_00286AF0(void);
extern void func_00286C70(void);
extern void func_00286D00(void);
extern void func_002874C0(void);
extern void func_00287AF0(void);
extern void func_00287C10(void);
extern void func_00287E20(void);
extern void func_00288020(void);
extern void func_00288330(void);
extern void func_00288FE0(void);
extern void func_0028CF50(void);
extern void func_0028D110(void);
extern void func_0028D250(void);
extern void func_0028D3F0(void);
extern void func_0028D660(void);
extern void func_0028D670(void);
extern void func_0028D6D0(void);
extern void func_0028D730(void);
extern void func_0028D7A0(void);
extern void func_0028D940(void);
extern void func_0028D9B0(void);
extern void func_0028D9F0(void);
const Mvc2Callback D_00456670[28] = {
    func_00286C70,
    func_00286280,
    func_00286D00,
    func_002874C0,
    func_00287C10,
    func_00287E20,
    func_00288020,
    func_00288330,
    func_00288FE0,
    func_0028D110,
    func_0028D250,
    func_0028D3F0,
    func_0028D660,
    func_00286AF0,
    func_0028CF50,
    func_00287AF0,
    func_0028D670,
    func_0028D6D0,
    func_0028D730,
    func_0028D7A0,
    0,
    0,
    0,
    func_0028D9F0,
    func_0028D940,
    func_0028D9B0,
    0,
    0,
};
