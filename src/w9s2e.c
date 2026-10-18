typedef signed int s32;
typedef unsigned int u32;
union gh_u { double value; struct { u32 lsw; u32 msw; } parts; };
#define EXTRACT_WORDS(ix0,ix1,d) do { union gh_u ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
s32 func_00116928(double x) {
    s32 hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (s32)((u32)(hx | (-hx)) >> 31);
}
