typedef float f32;
/* func_001ACBE0 reads row [s2] (stride 12, lwc1 +0/+4/+8) into +0x50..+0x58;
 * the same index selects D_0044B8B8[s2]. Known callers pass 0; rows 1..2 are
 * typed from the stride. */
f32 D_0044B8D0[3][3] = {
    { 1.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f },
    { 0.30000001192092896f, 0.30000001192092896f, 0.30000001192092896f },
};
