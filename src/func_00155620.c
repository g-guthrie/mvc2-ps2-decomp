typedef unsigned char u8;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00444AB0[];
extern void func_00155AB0(u8 *);

void func_00155620(u8 *p) {
    p[4]++;
    jtbl_00444AB0[p[0x20]](p);
    func_00155AB0(p);
}
