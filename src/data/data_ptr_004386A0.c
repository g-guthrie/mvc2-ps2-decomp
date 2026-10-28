/* One-element array form keeps this zero-initialised object in .data (a zero scalar goes to .bss). */
/* Saved kernel handler pointer: func_0010C2F8 stores func_0010C2D8(3) here (sw at 0x0010C3B0);
 * func_0010CEB8 (0x0010CEC8), func_0010CFD8 (0x0010D01C) and func_0010D048 (0x0010D070)
 * load it with lw and use it as a base address.  Null at load. */
char *data_ptr_004386A0[1] = { 0 };
