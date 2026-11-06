/* Infrastructure fixture. Never contributes to game progress. */
extern unsigned int imported;
void smoke(void) {}
void (*const hook)(void) = smoke;
unsigned int *const imported_hook = &imported;
unsigned int value = 0x12345678u;
unsigned int scratch;
