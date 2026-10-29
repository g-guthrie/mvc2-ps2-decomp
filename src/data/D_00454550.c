typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_0026B0D0(void);
extern void func_0026B4F0(void);
extern void func_0026B6C0(void);
extern void func_0026B700(void);
extern void func_0026BF00(void);
extern void func_0026C3D0(void);
extern void func_0026C540(void);
extern void func_0026C720(void);
extern void func_0026C930(void);
extern void func_0026C9E0(void);
extern void func_0026CB20(void);
extern void func_0026CD00(void);
extern void func_0026E810(void);
extern void func_0026E950(void);
extern void func_0026EA70(void);
extern void func_0026EC80(void);
extern void func_0026ECC0(void);
extern void func_0026ECE0(void);
extern void func_0026ED00(void);
extern void func_0026ED60(void);
extern void func_0026EDC0(void);
const Mvc2Callback D_00454550[28] = {
    func_0026B6C0,
    func_0026B0D0,
    func_0026B700,
    func_0026BF00,
    func_0026C540,
    func_0026C720,
    func_0026C930,
    func_0026C9E0,
    func_0026CD00,
    func_0026E810,
    func_0026E950,
    func_0026EA70,
    func_0026EC80,
    func_0026B4F0,
    func_0026CB20,
    func_0026C3D0,
    func_0026ECC0,
    func_0026ECE0,
    func_0026ED00,
    func_0026ED60,
    0,
    0,
    0,
    func_0026EDC0,
    0,
    0,
    0,
    0,
};
