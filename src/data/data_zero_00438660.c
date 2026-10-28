/* Handler table: reader code stores a handler at [n] and calls through
 * (jalr) the entry picked by (n & 0x7C). Null at load. */
typedef void (*Handler)(void);
Handler data_zero_00438660[1] = { 0 };
