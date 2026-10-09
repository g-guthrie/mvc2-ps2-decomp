typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
/* func_00131B50 maps the six field0x425/field0x02 combinations to rows0..5, or rows18..23 when field0x428 has mask0x07000000; func_00132880 and func_00132950 also select rows0..5. The packed stream reader above stops at DD80 because field0x4DD is0..2. */
F32Vector3 data_f32v3_0043DD80[6] = {
    { { -20.5f, 82.19999694824219f, -130.0f } },
    { { 20.5f, 82.19999694824219f, -130.0f } },
    { { -71.0f, 103.5f, -190.5f } },
    { { 71.0f, 103.5f, -190.5f } },
    { { -71.0f, 90.69999694824219f, -190.5f } },
    { { 71.0f, 90.69999694824219f, -190.5f } },
};
