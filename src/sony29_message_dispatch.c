extern char D_004AB260[];
extern char *D_004386A0;
extern char *func_0010CEB8(char *, int, int);
extern void func_0010CFD0(void);
extern void func_00103A20(char *, int, char *);
extern void func_00104200(int, char *);
void func_0010D048(char *format, int value, int extra)
{
    char *message = func_0010CEB8(format, value, extra);
    func_0010CFD0();
    func_00103A20(message, value, D_004386A0 + 4);
}
void func_0010D0B8(int value, int extra)
{
    func_0010CEB8(D_004AB260, value, extra);
    func_0010CFD0();
    func_00104200(value, D_004386A0 + 4);
}
