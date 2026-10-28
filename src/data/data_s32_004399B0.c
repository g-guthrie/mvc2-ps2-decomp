/* One-element array form keeps this zero-initialised object in .data (a zero scalar goes to .bss). */
/* Busy flag (polled by sony29_wait_idle.c): lw at 0x0010F188/0x0010F1B0, stored
 * at 0x0010E70C, 0x0010E758, 0x0010E7D8, 0x0010E828, 0x0010EA24, 0x0010FABC, 0x0010FAF8. */
volatile int data_s32_004399B0[1] = { 0 };
