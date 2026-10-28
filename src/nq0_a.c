typedef unsigned char u8;
typedef unsigned int u32;

void func_00372620(void) {
}

void func_00389E20(u8 *p, u8 *q) {
    extern void func_00389E60(u8 *, u8 *);
    u32 t = p[5];
    p[5] = t + 1;
    p[0x14C] = 0x18;
    p[0x14D] = 0x18;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    func_00389E60(p, q);
}

void func_0038DA10(u8 *p, u8 *q) {
    extern void func_0038DA40(u8 *, u8 *);
    u32 t = p[5];
    p[5] = t + 1;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    func_0038DA40(p, q);
}
