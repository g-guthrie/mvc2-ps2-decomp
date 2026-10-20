/* GCC 2.96 libgcc2.c __umoddi3 entry at 0x00118768. */
#define L_umoddi3 1
#define GCC_LIBGCC_CLZ_TABLE gLeadingByteIndexTable3_004AC5E8
#include "gcc_libgcc_udivmod_core.h"

UDWtype func_00118768(UDWtype u, UDWtype v)
{
    UDWtype w; (void) __udivmoddi4(u, v, &w); return w;
}
