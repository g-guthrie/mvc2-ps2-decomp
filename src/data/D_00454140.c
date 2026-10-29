typedef void (*Mvc2Callback)(void);
/* One 112-byte character action record: the bulk_copy_112.c reader copies
 * all 28 words to the actor at +0x43C. Every nonzero word is a state
 * callback. */
extern void func_002621F0(void);
extern void func_00262A90(void);
extern void func_00262C20(void);
extern void func_00262CB0(void);
extern void func_002635C0(void);
extern void func_00263DB0(void);
extern void func_00263EF0(void);
extern void func_00264110(void);
extern void func_00264300(void);
extern void func_00264860(void);
extern void func_00264B80(void);
extern void func_00269DE0(void);
extern void func_00269F20(void);
extern void func_0026A160(void);
extern void func_0026A9B0(void);
extern void func_0026AC00(void);
extern void func_0026AC60(void);
extern void func_0026ACC0(void);
extern void func_0026AD20(void);
extern void func_0026AD90(void);
extern void func_0026AE00(void);
extern void func_0026AFE0(void);
const Mvc2Callback D_00454140[28] = {
    func_00262C20,
    func_002621F0,
    func_00262CB0,
    func_002635C0,
    func_00263EF0,
    func_00264110,
    func_00264300,
    func_00264860,
    func_00264B80,
    func_00269DE0,
    func_00269F20,
    func_0026A160,
    func_0026AC00,
    func_00262A90,
    func_0026AE00,
    func_00263DB0,
    func_0026AC60,
    func_0026ACC0,
    func_0026AD20,
    func_0026AD90,
    0,
    func_0026A9B0,
    0,
    func_0026AFE0,
    0,
    0,
    0,
    0,
};
