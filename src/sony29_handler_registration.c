#include "sony29_handler_table.h"
typedef Sony29Handler Handler;
extern Handler D_00438658;
extern Handler D_00438660[];
extern void func_0010C6C0(void);
extern void func_0010C900(void);
extern void func_00103A90(int, Handler);
extern void func_00103AA0(int, Handler);
Handler func_0010C1A8(Handler handler)
{
    D_00438658 = handler;
    func_00103A90(1, func_0010C6C0);
    func_00103A90(2, func_0010C6C0);
    func_00103A90(3, func_0010C6C0);
    return handler;
}
unsigned int func_0010C208(unsigned int index, Handler handler)
{
    Handler old;
    if (index - 1 >= 13) return ~0u;
    old = D_00438660[index];
    D_00438660[index] = handler;
    if (index - 1 < 3)
        func_00103A90(index, func_0010C900);
    else
        func_00103AA0(index, func_0010C900);
    return (unsigned int)old;
}
