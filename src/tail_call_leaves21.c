typedef unsigned char u8;

extern void func_003A3880();

void func_003A37F0(u8 *p, u8 *q) {
    u8 *r = *(u8 **)(p + 476);
    q[510] = 0;
    *(u8 **)(r + 456) = q;
    r[522] = 1;
    r[437] = 37;
    func_003A3880(p, q);
}
