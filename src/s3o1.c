#include "sony_command_table_types.h"
typedef unsigned int u32;

void func_00106270(u32 id) {
    /* The system-ID high bit drops out of the native 32-bit byte offset. */
    u32 offset=id*8u;
    if ((int)id<0) id=(u32)D_004C3AE4; else id=(u32)D_004C3AEC;
    offset+=id;
    ((SonyCommandEntry *)offset)->handler=0;
}
