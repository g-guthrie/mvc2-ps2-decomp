typedef unsigned char u8;
typedef signed short s16;
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern void func_003BFD30(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_0030ED20(u8 *);
void func_0030ECA0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[6]++;
    *(s16 *)(p + 0x1C) = 420;
    func_003BFD30(p);
    func_001E3710(p, 79);
    D_004F1F45 = 2;
    D_004F1F46 = 1;
    func_0030ED20(p);
}
