typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002B81F0(void);
extern void func_002B8940(void);
extern void func_002B8AC0(void);
extern void func_002B8AD0(void);
extern void func_002B93B0(void);
extern void func_002B97C0(void);
extern void func_002B98E0(void);
extern void func_002B9A20(void);
extern void func_002B9B30(void);
extern void func_002B9C00(void);
extern void func_002BA0B0(void);
extern void func_002BE340(void);
extern void func_002BE530(void);
extern void func_002BE700(void);
extern void func_002BECC0(void);
extern void func_002BF760(void);
extern void func_002BF8D0(void);
extern void func_002BF930(void);
extern void func_002BF990(void);
extern void func_002BFA00(void);
const Mvc2Callback D_00459300[28] = {
    func_002B8AC0,
    func_002B81F0,
    func_002B8AD0,
    func_002B93B0,
    func_002B98E0,
    func_002B9A20,
    func_002B9B30,
    func_002B9C00,
    func_002BA0B0,
    func_002BE530,
    func_002BE700,
    func_002BECC0,
    func_002BF760,
    func_002B8940,
    func_002BE340,
    func_002B97C0,
    func_002BF8D0,
    func_002BF930,
    func_002BF990,
    func_002BFA00,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
