/* GCC 2.96 libgcc2.c signed remainder wrapper at 0x00117B58. */
#define L_moddi3 1
#define GCC_LIBGCC_CLZ_TABLE gLeadingByteIndexTable1_004AC3E8
#include "gcc_libgcc_signed_divmod_core.h"

DWtype func_00117B58(DWtype u, DWtype v)
{
    word_type c = 0;
    DWunion uu, vv;
    DWtype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        vv.ll = __negdi2(vv.ll);

    (void)__udivmoddi4(uu.ll, vv.ll, &w);
    if (c)
        w = __negdi2(w);

    return w;
}
