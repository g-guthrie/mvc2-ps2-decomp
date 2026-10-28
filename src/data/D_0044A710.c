typedef signed short s16;
/* {x, y} offsets: func_0019A210 reads D_0044A710[s8 +0x161].x (lh at
 * D_0044A710 + i*4) and .y (via D_0044A712). The pairs run to 0x0044A784. */
typedef struct { s16 x; s16 y; } S16Offset;
typedef char S16Offset_size_check[(sizeof(S16Offset) == 4) ? 1 : -1];
S16Offset D_0044A710[29] = {
    { 0, 0 },
    { 8, 100 },
    { 8, 101 },
    { 29, 99 },
    { 27, 101 },
    { 27, 102 },
    { 27, 100 },
    { 29, 98 },
    { 27, 97 },
    { 27, 96 },
    { 3, 97 },
    { 3, 98 },
    { 3, 99 },
    { 3, 100 },
    { 6, 60 },
    { 6, 61 },
    { 6, 62 },
    { 8, 58 },
    { 8, 56 },
    { 8, 57 },
    { 7, 59 },
    { 16, 80 },
    { 9, 71 },
    { 2, 53 },
    { 6, 60 },
    { 18, 52 },
    { 22, 70 },
    { 7, 104 },
    { 8, 101 },
};
