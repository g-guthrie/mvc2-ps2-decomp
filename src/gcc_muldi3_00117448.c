/* GCC 2.96 libgcc2.c __muldi3; upstream db2e2f480c906879dad6930e4fe0784a52814426.
 * GPL-2.0-or-later WITH GCC-exception-2.0. The original complete notices
 * and unmodified MIPS primitive are retained in the included existing header. */
#define GCC_LIBGCC_CLZ_TABLE gLeadingByteIndexTable3_004AC5E8
#include "gcc_libgcc_udivmod_core.h"
/* Original generic longlong.h __umulsidi3 macro, same upstream revision. */
#define __umulsidi3(u,v) ({ DWunion __w; umul_ppmm(__w.s.high,__w.s.low,u,v); __w.ll; })
DWtype
func_00117448 (DWtype u, DWtype v)
{
  DWunion w;
  DWunion uu, vv;

  uu.ll = u,
  vv.ll = v;

  w.ll = __umulsidi3 (uu.s.low, vv.s.low);
  w.s.high += ((UWtype) uu.s.low * (UWtype) vv.s.high
               + (UWtype) uu.s.high * (UWtype) vv.s.low);

  return w.ll;
}
