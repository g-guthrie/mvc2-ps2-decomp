typedef unsigned char u8;
/* Zero word after data_raw_004AC8A0. func_0011E120 loads lw %lo(D_004AC8B4)(4*i)
 * only for nonzero i = k & 3, i.e. it addresses gPowerOfFiveFactors_004AC8B8[i - 1];
 * this word itself is never read. */
u8 data_raw_004AC8B4[4] = { 0 };
