typedef unsigned int u32;
typedef signed char s8;
/* Mixed 68-byte table. ids[] is read as u32 by func_00196D00 (wave31.c) at ids[q[0x25]];
   flags[] is read as s8 by wave7.c at flags[b[0x1E4]]. lead has no reader. */
typedef struct {
    u32 lead;
    u32 ids[8];
    s8 flags[32];
} data_u32_0044A2BC_t;
typedef char data_u32_0044A2BC_size_check[(sizeof(data_u32_0044A2BC_t) == 68) ? 1 : -1];
data_u32_0044A2BC_t data_u32_0044A2BC = {
    0x00000000u,
    { 0x0000007Eu, 0x0000007Fu, 0x00000080u, 0x00000081u, 0x00000082u, 0x00000083u, 0x00000000u, 0x00000000u },
    { 1, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0 },
};
