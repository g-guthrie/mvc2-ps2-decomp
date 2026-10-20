typedef unsigned char u8;

extern u8 *D_004C2840;
extern void func_00174150(void);

void residual_003D6B10(void)
{
    u8 *p = D_004C2840;
    u8 t = p[1];
    p[1] = t + 1;
    func_00174150();
}
