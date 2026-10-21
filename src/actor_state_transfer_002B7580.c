typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001CDE40(u8 *, u8, u8);
extern void func_00175C00(u8 *, int);
extern void func_00126400(void);
extern void func_0018FDE0(u8 *);
extern void func_0015B200(u8 *, f32 *, int, int);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_002B7580(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x209] = 2;
    p[0x201] = 2;
    if (p[7] == 0) {
        p[7] = p[7] + 1;
        (void)func_00175700(p);
        if (*(s8 *)(p + 0x151) & 1) {
            *(s8 *)(p + 0x151) ^= 1;
            func_001CDE40(p, 2, 0);
        }
        if (*(s8 *)(p + 0x151) & 2) {
            *(s8 *)(p + 0x151) ^= 2;
            func_00175C00(p, 8);
        }
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        *(u8 **)(*(u8 **)(p + 0x220) + 0x1C8) = p;
        *(*(u8 **)(p + 0x220) + 0x20A) = 1;
        *(*(u8 **)(p + 0x220) + 0x1E6) = p[0x1E6];
        *(*(u8 **)(p + 0x220) + 0x1B5) = 0x23;
        func_00126400();
        *(*(u8 **)(p + 0x220) + 0x1E6) ^= 1;
        p[0x1B5] = 0x24;
        p[0x1FE] = 0;
        func_0018FDE0(p);
        func_00175C00(p, 0);
        return;
    }
    if (*(s8 *)(p + 0x151) & 2) {
        *(s8 *)(p + 0x151) ^= 2;
        func_0015B200(p, (f32 *)(p + 0x34), 1, 0x108);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
    }
}
