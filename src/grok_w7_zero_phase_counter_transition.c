typedef unsigned char u8;
typedef unsigned int u32;
extern int func_00174170(void);
extern int func_001757E0(u8 *, int, int);
extern int func_001DD470(u8 *, int);
extern int func_001E3210(u8 *, int);
extern int func_00175700(u8 *);
void func_0030DCD0(u8 *p)
{
    u32 result;
    if (p[6] != 0)
        goto nonzero_state;
    p[6]++;
    result = (u32)func_00174170();
    func_001757E0(p, 19, result & 1);
    func_001DD470(p, 1);
    result = (u32)func_00174170();
    func_001E3210(p, (u8)(result % 3 + 15));
    return;
nonzero_state:
    func_00175700(p);
}
