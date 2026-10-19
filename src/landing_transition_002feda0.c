typedef unsigned char u8;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00183D50(u8 *);
extern void func_001E3710(u8 *, int);
extern u8 D_004F1F45, D_004F1F46;

void func_002FEDA0(u8 *p, void *context)
{
    float *vx = (float *)(p + 0x5C);
    float *vy = (float *)(p + 0x60);
    float *ax = (float *)(p + 0x68);
    float *ay = (float *)(p + 0x6C);

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_00175700(p);
    if (!(*(float *)(p + 0x430) - 68.57142639160156f <= *(float *)(p + 0x38))) {
        p[6]++;
        p[0x20D] = 0;
        *(float *)(p + 0x38) = *(float *)(p + 0x430);
        ((u8 *)context)[7] = 0;
        func_00175C00(p, 0);
        *vx = 0;
        *vy = 0;
        *ax = 0;
        *ay = 0;
        func_00183D50(p);
        func_001757E0(p, 22, 2);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3710(p, 0x31);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}
