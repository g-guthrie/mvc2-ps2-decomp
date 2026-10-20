/* Mixed signed/unsigned control bytes for the bounded record row. */
typedef signed char s8;
typedef unsigned char u8;
typedef struct { s8 active; u8 state; u8 kind; } RuntimeRecordControl;
RuntimeRecordControl data_runtime_header_004888A0[1] = { { 0, 0, 0 } };
