typedef unsigned char u8;

extern void func_00414A40(void);
extern void func_00416AB0(int);
extern void func_004171E0(void);
extern void func_004177A0(int, float, float, float);

void func_00143370(void)
{
    func_00414A40();
    func_00416AB0(3);
    func_004171E0();
    func_004177A0(0x4000, 1.0f, 0.1f, 12000.0f);
    func_00416AB0(1);
}
