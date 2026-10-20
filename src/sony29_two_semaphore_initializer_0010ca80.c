/* Native two-semaphore initializer for the Sony IOP runtime. */
#include "sony29_kernel_semaphore_calls.h"

extern int D_00438990;
extern int D_00438994;

void func_0010CA80(void)
{
    SonyEeSemaParams first;
    SonyEeSemaParams second;

    first.max_count = 1;
    first.init_count = 1;
    second.max_count = 1;
    second.init_count = 1;
    D_00438990 = func_00103DE0(&first);
    D_00438994 = func_00103DE0(&second);
}
