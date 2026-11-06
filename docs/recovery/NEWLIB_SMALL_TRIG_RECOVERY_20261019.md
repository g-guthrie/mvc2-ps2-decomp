# Remaining small trigonometric routines

Three complete genuine fdlibm routines match 904 native bytes: float cosine kernel 00115358 (336 bytes), float sine kernel 00115D10 (260 bytes), and double sine dispatcher 00116B98 (308 bytes). Their original algorithms and Sun notices are retained from Newlib commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, `math/kf_cos.c`, `kf_sin.c` and `s_sin.c`.

The float kernels preserve their original scalar coefficient values as typed value macros; no coefficient has an address use. Whole native code checks pass both before and after removal of those unused static objects. Final objects have no data, BSS or readonly payload. No data credit is added.

Compile all with SNCPP and EE GCC 2.96 O2/G0 with no extra flags. Assemble float kernels with SNAS MIPS IV/G0 and double sine with SNAS G0. Actual interfaces are float(float,float), float(float,float,int), and double(double), respectively. The double dispatcher calls the already reconstructed real argument reducer and sine/cosine kernels.
