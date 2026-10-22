typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
/* Eight-word block of globals, each field read at the width shown:
 * func_0040D638 (volatile s32 + counter), func_0040E288 / func_0040DBB0 / func_0040DE60 (word, s32, s8). */
typedef struct {
    volatile s32 f00;   /* D_004C2470 */
    s32 f04;            /* D_004C2474 */
    u32 f08;            /* D_004C2478 */
    s32 f0C;            /* D_004C247C */
    s32 f10;            /* D_004C2480 */
    s32 f14;            /* D_004C2484 */
    u32 f18;            /* D_004C2488 */
    s8 f1C;             /* D_004C248C */
    u8 pad1D[3];
} data_u32_004C2470_layout;
typedef char data_u32_004C2470_layout_size_check[(sizeof(data_u32_004C2470_layout) == 32) ? 1 : -1];
data_u32_004C2470_layout data_u32_004C2470 = {
    0x004BE3B0, 0, 0x004BE448, 0x10, 0x00041000, 0, 0, 0, { 0, 0, 0 }
};
