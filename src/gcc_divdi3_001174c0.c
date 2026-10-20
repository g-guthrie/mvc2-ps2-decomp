/* GCC 2.96 libgcc2.c signed divide wrapper at 0x001174C0. */
#define L_divdi3 1
#define GCC_LIBGCC_CLZ_TABLE gLeadingByteIndexTable0_004AC2E8
#include "gcc_libgcc_signed_divmod_core.h"

DWtype func_001174C0(DWtype u, DWtype v)
{
    word_type c = 0;
    DWunion uu, vv;
    DWtype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        c = ~c, vv.ll = __negdi2(vv.ll);

    w = __udivmoddi4(uu.ll, vv.ll, (UDWtype *)0);
    if (c)
        w = __negdi2(w);

    return w;
}
