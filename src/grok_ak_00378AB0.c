typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00175700(u8 *);
extern int func_00174A40(u8 *, int);
extern int func_00174240(u8 *);
extern void func_00378CA0(u8 *);
extern void func_001E7F60(u8 *);
extern s16 *D_004C298C;
extern u8 *D_004C2794;

void func_00378AB0(u8 *p)
{
    func_00175700(p);
    func_00174A40(p, D_004C298C[0]);
    D_004C298C[0] += 0x32;
    if (!func_00174240(p)) {
        func_00378CA0(p);
        return;
    }
    *(s16 *)(p + 0x1C) += 1;
    p[0x20]++;
    if (p[0x20] < 5) {
        p[0x1B5] = (u8)(*(s8 *)(p + 0x20) + 0x3E);
        *(s16 *)(p + 0x1C0) = 0;
        p[0x1B2] = (u8)(0 & 0xFFFF);
        *(unsigned int *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001E7F60(p);
    }
}
