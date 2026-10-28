typedef float f32;
/* func_00132C70 (0x00132CA0) indexes this table by the signed byte D_004D18FA[p[0x20]] with a
 * 16-byte stride (sll 4) and loads four floats into p+0x74..0x80 when p[0x21]==0.  The
 * alternate table D_0043E080 (0x00132E10, same index) bounds it at nine records. */
f32 data_f32x4_0043DFF0[9][4] = {
    { 1.0f, 1.0f, 0.25f, 0.25f },
    { 1.0f, 0.125f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 0.600000024f, 0.266000003f },
    { 1.0f, 0.375f, 0.375f, 1.0f },
    { 1.0f, 1.0f, 1.0f, 0.133000001f },
    { 1.0f, 0.75f, 0.25f, 1.0f },
    { 1.0f, 0.375f, 1.0f, 0.25f },
    { 1.0f, 1.0f, 0.25f, 1.0f },
    { 1.0f, 0.25f, 1.0f, 0.875f },
};
