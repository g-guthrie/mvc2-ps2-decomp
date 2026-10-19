/* Metrowerks 3.0: ./try.sh src/grok_nopg_247630.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_00247790(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00247710(u8 *, int);

void residual_00247630(u8 *p, int a1)
{
    if (p[533]) {
        func_00247790(p, a1);
        return;
    }
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[525] != 2)
        func_00183D10(p);
    p[533] = 1;
    *(s16 *)(a1 + 10) = 480;
    p[525] = 2;
    p[528] = 0;
    p[488] = 0;
    p[489] = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0x414DB6DB;
    *(u32 *)(p + 108) = 0xBE892492;
    func_001757E0(p, 26, 0);
    func_00247710(p, a1);
}
