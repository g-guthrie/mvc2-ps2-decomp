typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0030E440(u8 *, int);
extern int func_00175700(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001E3210(u8 *, int);
extern void func_00176090(u8 *, int, int, int);
extern void func_0030F650(u8 *);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_0030E6B0(u8 *p)
{
    s16 mode;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(u32 *)(p + 0x2D8) = 0xFF;
    func_0030E440(p, 21);
    mode = *(s16 *)(p + 0x1E);
    mode += 0x2000;
    *(s16 *)(p + 0x1E) = mode;
    if (mode == 0) {
        D_004F1F45 = 2;
        D_004F1F46 = 1;
    }
    func_00175700(p);
    {
        s16 timer = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = timer;
        if (timer >= 0)
            return;
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    func_001E3710(p, 59);
    func_001E3210(p, 43);
    func_00176090(p, 0, 0, 1);
    func_0030F650(p);
}
