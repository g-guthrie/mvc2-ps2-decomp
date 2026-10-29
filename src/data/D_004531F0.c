typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0024D800(void);
extern void func_0024DFD0(void);
extern void func_0024E170(void);
extern void func_0024E240(void);
extern void func_0024EA30(void);
extern void func_0024F000(void);
extern void func_0024F190(void);
extern void func_0024F4B0(void);
extern void func_0024F700(void);
extern void func_0024F800(void);
extern void func_0024FA90(void);
extern void func_00252FA0(void);
extern void func_00253180(void);
extern void func_002532C0(void);
extern void func_002535D0(void);
extern void func_00254170(void);
extern void func_002541F0(void);
extern void func_00254250(void);
extern void func_002542B0(void);
extern void func_00254320(void);
extern void func_00254390(void);
const Mvc2Callback D_004531F0[28] = {
    func_0024E170,
    func_0024D800,
    func_0024E240,
    func_0024EA30,
    func_0024F190,
    func_0024F4B0,
    func_0024F700,
    func_0024F800,
    func_0024FA90,
    func_00253180,
    func_002532C0,
    func_002535D0,
    func_00254170,
    func_0024DFD0,
    func_00252FA0,
    func_0024F000,
    func_002541F0,
    func_00254250,
    func_002542B0,
    func_00254320,
    0,
    0,
    0,
    func_00254390,
    0,
    0,
    0,
    0,
};
