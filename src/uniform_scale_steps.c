/* Apply the same scale increment to three axes until the frame limit. */
typedef unsigned char u8;
extern void func_003DAA40(u8 *);

#define UNIFORM_SCALE_STEP(name, increment) \
void name(u8 *p) { \
    *(float *)(p + 0x50) += (increment); \
    *(float *)(p + 0x54) += (increment); \
    *(float *)(p + 0x58) += (increment); \
    if (*(short *)(p + 0x1c) >= 10) func_003DAA40(p); \
    else ++*(short *)(p + 0x1c); \
}

UNIFORM_SCALE_STEP(func_00156BE0, 0.80000001192092895508f)
UNIFORM_SCALE_STEP(func_00156D00, 0.80000001192092895508f)
UNIFORM_SCALE_STEP(func_00156EE0, 0.80000001192092895508f)
UNIFORM_SCALE_STEP(func_00157010, 0.80000001192092895508f)
