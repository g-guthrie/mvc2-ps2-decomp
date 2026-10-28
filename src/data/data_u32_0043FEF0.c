typedef int s32;
typedef float f32;
/* 0x100 bytes of small signed ints (tail of the preceding small-int vector tables), then two f32 x/y/z
   vectors read by func_00139EE0 at 0x0043FFF0 (stride 12), then s32 triples read at 0x00440010 (stride 12). */
typedef struct {
    s32 small_ints[64];
    f32 pos[2][3];
    s32 pad0[2];
    s32 params[2][3];
    s32 pad1[2];
} SmallIntAndVecBlock;
typedef char SmallIntAndVecBlock_size_check[(sizeof(SmallIntAndVecBlock) == 0x140) ? 1 : -1];
SmallIntAndVecBlock data_u32_0043FEF0 = {
    {
        38, -2, -31, -13, 38, 347, -1, -24,
        -11, -25, -31, -24, -1, -35, 19, -13,
        -21, -24, 29, -24, 9, 324, 18, -35,
        -11, 325, -1, 32, 9, 32, 38, 20,
        -11, 42, 18, 31, -31, 19, -21, 31,
        -11, 31, 38, 8, 8, 42, 18, 42,
        28, 31, 38, 31, -1, 42, -31, 31,
        8, -24, -31, -2, -21, 20, 38, -24,
    },
    { { -115.0f, 400.0f, 310.0f }, { 115.0f, 400.0f, 310.0f } },
    { 0, 0 },
    { { 0, 0, 57345 }, { 0, 0, 8192 } },
    { 0, 0 },
};
