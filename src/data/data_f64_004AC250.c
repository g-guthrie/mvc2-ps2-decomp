/* A libm `static const double huge = 1.0e300;` (fdlibm) with the same bits as
   the copies at 0x004AC248 (read by atan) and 0x004AC258 (read by floor): the
   toolchain rounded the 1.0e300 literal one ulp low. This copy belongs to a
   translation unit between atan and floor whose code no longer loads it. */
typedef double f64;
const f64 data_f64_004AC250 = 9.999999999999999e+299;
