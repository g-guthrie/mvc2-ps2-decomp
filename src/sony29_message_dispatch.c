/* Native argv staging before LoadExecPS2 and ExecOSD. */
#include "sony29_exec_arguments.h"
extern char D_004AB260[];
extern char *D_004386A0;
extern void func_0010CFD0(void);
extern void func_00103A20(const char *, int, char **);
extern void func_00104200(int, char **);
void func_0010D048(const char *filename, int argc, char **argv)
{
    char *staged = func_0010CEB8(filename, argc, argv);
    func_0010CFD0();
    func_00103A20(staged, argc, (char **)(D_004386A0 + 4));
}
void func_0010D0B8(int argc, char **argv)
{
    func_0010CEB8(D_004AB260, argc, argv);
    func_0010CFD0();
    func_00104200(argc, (char **)(D_004386A0 + 4));
}
