typedef unsigned char u8;

extern void func_003DAA40(u8 *);
extern void func_003D7310(void *);
extern u8 D_004D17C9;
extern void *D_00444520[];

void func_001516A0(u8 *p)
{
    if (p[4] != 0) {
        func_003DAA40(p);
        return;
    }
    if (D_004D17C9 != p[0x20]) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        func_003D7310(D_00444520[p[0x20]]);
    }
}
