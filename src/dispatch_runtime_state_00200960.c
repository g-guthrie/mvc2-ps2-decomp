typedef unsigned char u8;
extern void (*jtbl_004BFD50[2])(u8 *);

void func_00200960(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    jtbl_004BFD50[p[7]](p);
}
