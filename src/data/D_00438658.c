/* One-element array form keeps this zero-initialised object in .data (a zero scalar goes to .bss). */
/* Handler pointer: func_0010C1A8 stores its argument here (sw at 0x0010C1C4); the exception
 * stub at 0x0010C7C0 (src/ee_exception.S) loads it and calls it (jalr). Null at load. */
typedef void (*Handler)(void);
Handler D_00438658[1] = { 0 };
