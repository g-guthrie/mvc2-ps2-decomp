typedef unsigned char u8;
typedef void (*M15Handler)(u8 *);
extern void func_00144F50(u8 *);
extern void func_00144FC0(u8 *);
extern void func_00145050(u8 *);

const M15Handler jtbl_00442570[3] = {
    func_00144F50,
    func_00144FC0,
    func_00145050,
};
