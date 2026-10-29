typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00273680(void);
extern void func_00273C70(void);
extern void func_00273DE0(void);
extern void func_00273E20(void);
extern void func_00274530(void);
extern void func_00274DA0(void);
extern void func_00274ED0(void);
extern void func_00275100(void);
extern void func_00275330(void);
extern void func_002756A0(void);
extern void func_00275A20(void);
extern void func_00277900(void);
extern void func_00277A40(void);
extern void func_00277BA0(void);
extern void func_00277ED0(void);
extern void func_00277F30(void);
extern void func_00277F90(void);
extern void func_00278000(void);
extern void func_00278070(void);
extern void func_002780B0(void);
const Mvc2Callback D_00454B00[28] = {
    func_00273DE0,
    func_00273680,
    func_00273E20,
    func_00274530,
    func_00274ED0,
    func_00275100,
    func_00275330,
    func_002756A0,
    func_00275A20,
    func_00277900,
    func_00277A40,
    func_00277BA0,
    func_00278070,
    func_00273C70,
    func_002780B0,
    func_00274DA0,
    func_00277ED0,
    func_00277F30,
    func_00277F90,
    func_00278000,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
