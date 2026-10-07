/* Advance three keyframe cursors and integrate their scale deltas per axis. */
typedef unsigned char u8;
typedef struct ScaleKey { int frame; float value; } ScaleKey;
extern void func_003DAA40(u8 *);
extern ScaleKey D_00444D30[], D_00444D50[], D_00444D70[];
extern ScaleKey D_00444D90[], D_00444DA0[], D_00444DC0[];
extern ScaleKey D_00444DD0[], D_00444DE0[], D_00444DF0[];
extern ScaleKey D_00444E00[], D_00444E10[], D_00444E40[];

#define THREE_AXIS_KEY_STEP(name, x, y, z) \
void name(u8 *p) { \
    ++*(short *)(p + 0x1c); \
    if (*(short *)(p + 0x1c) > 15) func_003DAA40(p); \
    else { \
        if (*(short *)(p + 0x1c) >= (x)[p[4] + 1].frame) ++p[4]; \
        if (*(short *)(p + 0x1c) >= (y)[p[5] + 1].frame) ++p[5]; \
        if (*(short *)(p + 0x1c) >= (z)[p[6] + 1].frame) ++p[6]; \
        *(float *)(p + 0x50) += ((x)[p[4] + 1].value - (x)[p[4]].value) / \
            (float)((x)[p[4] + 1].frame - (x)[p[4]].frame); \
        *(float *)(p + 0x54) += ((y)[p[5] + 1].value - (y)[p[5]].value) / \
            (float)((y)[p[5] + 1].frame - (y)[p[5]].frame); \
        *(float *)(p + 0x58) += ((z)[p[6] + 1].value - (z)[p[6]].value) / \
            (float)((z)[p[6] + 1].frame - (z)[p[6]].frame); \
    } \
}

THREE_AXIS_KEY_STEP(func_00158CD0, D_00444D30, D_00444D50, D_00444D70)
THREE_AXIS_KEY_STEP(func_00158F90, D_00444D90, D_00444DA0, D_00444DC0)
THREE_AXIS_KEY_STEP(func_00159250, D_00444DD0, D_00444DE0, D_00444DF0)
THREE_AXIS_KEY_STEP(func_00159510, D_00444E00, D_00444E10, D_00444E40)
