typedef unsigned char u8;
typedef void (*StateCallback)(u8 *);

extern void func_0013ED90(u8 *);
extern void func_0013EE10(u8 *);
extern void func_0013EE90(u8 *);

/* func_0013EAD0 is called only with selectors 0 and 2; the dispatcher indexes
 * this 3-entry callback table with the saved selector at object offset 0x20. */
const StateCallback jtbl_00440678[3] = {
    func_0013ED90,
    func_0013EE10,
    func_0013EE90,
};
