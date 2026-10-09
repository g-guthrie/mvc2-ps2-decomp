typedef unsigned char u8;
extern void func_003BE5F0(u8 *);
extern void func_00176160(u8 *, int, int, int);
extern void func_001E3710(u8 *, int);
extern void func_0030E3A0(u8 *);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_0030E330(u8 *p)
{
    p[6]++;
    func_003BE5F0(p);
    func_00176160(p, 2, 9, 1);
    func_001E3710(p, 77);
    D_004F1F45 = 3;
    D_004F1F46 = 1;
    func_0030E3A0(p);
}
