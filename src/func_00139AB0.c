typedef unsigned char u8;

extern void func_00139BA0(u8 *);
extern u8 D_00583B92[];

void func_00139AB0(u8 *p) {
    func_00139BA0(p);
    if (D_00583B92[p[0x20]] & (1 << p[0x21]))
        p[4]++;
}
