typedef unsigned char u8;
typedef void (*M15Handler)(u8 *);
extern void func_00145B10(u8 *);
extern void func_00145CD0(u8 *);
extern void func_00145E40(u8 *);

const M15Handler jtbl_00442580[3] = {
    func_00145B10,
    func_00145CD0,
    func_00145E40,
};
