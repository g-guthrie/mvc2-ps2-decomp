/* Four native unary contact-lane phases. */
typedef unsigned char u8;
typedef void (*ContactLanePhase)(u8 *);
extern void func_00325120(u8 *);
extern void func_00325230(u8 *);
extern void func_00325380(u8 *);
extern void func_003253F0(u8 *);
ContactLanePhase const jtbl_0045E020[4] = {
    func_00325120,
    func_00325230,
    func_00325380,
    func_003253F0,
};
