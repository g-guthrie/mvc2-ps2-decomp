typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
#include "cri_sj_ring_buffer_types.h"

extern void *func_0011D8F8(void *destination, s32 value, u32 size);

void func_0040FEA8(SJ_OBJ *object)
{
    u8 *state = (u8 *)object;
    if (state != 0)
    {
        func_0011D8F8(state, 0, 48);
        state[4] = 0;
    }
}
