/* Stage argv, initialize kernel execution state, and return ExecPS2 status. */
#include "sony29_exec_arguments.h"
extern void func_0010CFD0(void);
extern int func_00103A30(void *,void *,int,char **);
extern char D_004AB260[];
extern char *D_004386A0;
int func_0010CFD8(void *entry,void *global_pointer,int argc,char **argv)
{
    func_0010CEB8(D_004AB260,argc,argv);
    func_0010CFD0();
    return func_00103A30(entry,global_pointer,argc,(char **)(D_004386A0+4));
}
