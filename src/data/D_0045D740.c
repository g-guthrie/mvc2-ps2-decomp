typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_00316D30(void);
extern void func_00317390(void);
extern void func_00317430(void);
extern void func_00317760(void);
extern void func_00317930(void);
extern void func_00317AD0(void);
extern void func_00317BF0(void);
extern void func_00317EA0(void);
extern void func_003180C0(void);
extern void func_00318320(void);
extern void func_003184E0(void);
extern void func_0031A180(void);
extern void func_0031A350(void);
extern void func_0031A450(void);
extern void func_0031A6E0(void);
extern void func_0031AF90(void);
extern void func_0031AFA0(void);
extern void func_0031B000(void);
extern void func_0031B060(void);
extern void func_0031B0D0(void);
extern void func_0031B140(void);
extern void func_0031B1A0(void);
extern void func_0031B210(void);
const Mvc2Callback D_0045D740[28] = {
    func_00317430,
    func_00316D30,
    func_00317760,
    func_00317930,
    func_00317BF0,
    func_00317EA0,
    func_003180C0,
    func_00318320,
    func_003184E0,
    func_0031A350,
    func_0031A450,
    func_0031A6E0,
    func_0031AF90,
    func_00317390,
    func_0031A180,
    func_00317AD0,
    func_0031AFA0,
    func_0031B000,
    func_0031B060,
    func_0031B0D0,
    0,
    0,
    0,
    0,
    func_0031B140,
    func_0031B1A0,
    func_0031B210,
    0,
};
