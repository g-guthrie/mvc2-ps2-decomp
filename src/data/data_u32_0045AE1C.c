typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* Tail of the jump table at jtbl_0045AE10 (null entry) followed by the first
   4-byte cell of the byte table at D_0045AE20 (indexed by [row*12 + col*4]). */
typedef struct {
    void (*entry)(void);
    u8 cell[4];
} AE1C_Tail;
typedef char AE1C_Tail_size_check[(sizeof(AE1C_Tail) == 8) ? 1 : -1];
AE1C_Tail data_u32_0045AE1C = { 0, { 1, 2, 1, 2 } };
