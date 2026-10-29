typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0030F850(void);
extern void func_0030FCE0(void);
extern void func_0030FE60(void);
extern void func_0030FF70(void);
extern void func_00310830(void);
extern void func_00311A50(void);
extern void func_00311C50(void);
extern void func_00312260(void);
extern void func_00312730(void);
extern void func_00312930(void);
extern void func_00312950(void);
extern void func_00315370(void);
extern void func_003156B0(void);
extern void func_00316660(void);
extern void func_00316A70(void);
extern void func_00316AA0(void);
extern void func_00316B00(void);
extern void func_00316B60(void);
extern void func_00316BD0(void);
extern void func_00316C40(void);
extern void residual_00311A70(void);
const Mvc2Callback D_0045D2D0[28] = {
    func_0030FE60,
    func_0030F850,
    func_0030FF70,
    func_00310830,
    residual_00311A70,
    func_00311C50,
    func_00312260,
    func_00312730,
    func_00312950,
    func_00315370,
    func_003156B0,
    func_00316660,
    func_00316A70,
    func_0030FCE0,
    func_00312930,
    func_00311A50,
    func_00316AA0,
    func_00316B00,
    func_00316B60,
    func_00316BD0,
    0,
    0,
    0,
    func_00316C40,
    0,
    0,
    0,
    0,
};
