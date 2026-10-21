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

extern void func_00183D50(u8 *);
extern void func_001843A0(u8 *);
extern void func_001E3A40(u8 *);

void func_002B7DA0(u8 *p)
{
    if (p[7] == 0) {
        if (*(s8 *)(p + 0x151) >= 0)
            (void)func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
            p[7]++;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x151] = 0;
            func_00183D50(p);
        }
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x60) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 0.0f;
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        *(u8 **)(*(u8 **)(p + 0x220) + 0x1C8) = p;
        *(*(u8 **)(p + 0x220) + 0x20A) = 0x0B;
        *(*(u8 **)(p + 0x220) + 0x1E6) = p[0x1E6];
        *(*(u8 **)(p + 0x220) + 0x1B5) = 0x21;
        func_00126400();
        func_001E3A40(p);
    }
}

typedef signed short s16;
extern void func_001E3710(u8 *, int);
extern int func_001757E0(u8 *, int, int);
void func_002B4710(u8 *p)
{
    (void)func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (*(s16 *)(p + 0x140) != 0)
            *(f32 *)(p + 0x34) += -106.66666412353516f;
        else
            *(f32 *)(p + 0x34) += 106.66666412353516f;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3710(p, 0x49);
        func_001CDE40(p, 1, 0);
        func_001CDE40(p, 1, 1);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001757E0(p, 0xD, 0x22);
    }
}
