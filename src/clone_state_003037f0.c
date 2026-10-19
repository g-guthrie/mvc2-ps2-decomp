typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_00303950(u8 *, u8 *);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_003038D0(u8 *, u8 *);

void func_003037F0(u8 *p, u8 *a1)
{
    if (p[533]) {
        func_00303950(p, a1);
        return;
    }
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[525] != 2)
        func_00183D10(p);
    p[533] = 1;
    *(s16 *)(a1 + 4) = 480;
    p[525] = 2;
    p[528] = 0;
    p[488] = 0;
    p[489] = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0x414DB6DB;
    *(u32 *)(p + 108) = 0xBE892492;
    func_001757E0(p, 26, 0);
    func_003038D0(p, a1);
}
