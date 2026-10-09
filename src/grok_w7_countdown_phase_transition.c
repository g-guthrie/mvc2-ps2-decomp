typedef unsigned char u8;
typedef signed short s16;
extern void func_0030E440(u8 *, int);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern int func_00175700(u8 *);
extern void func_003BD930(u8 *);
extern void func_00176160(u8 *, int, int, int);
extern int func_001757E0(u8 *, int, int);
void func_0030E940(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(unsigned int *)(p + 0x2D8) = 0xFF;
    func_0030E440(p, 20);
    func_00175700(p);
    {
        s16 timer = *(s16 *)(p + 0x1C);
        timer--;
        *(s16 *)(p + 0x1C) = timer;
        if (timer <= 0) {
            D_004F1F45 = 2;
            D_004F1F46 = 1;
            func_003BD930(p);
            func_00176160(p, 3, 8, 1);
            p[6]++;
            *(s16 *)(p + 0x1C) = 17;
            func_001757E0(p, 22, 12);
        }
    }
}
