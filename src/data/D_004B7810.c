typedef float f32;
/* func_0032EF10 picks row (random % 9) and scales it by 8 (0x0032EFD4), then loads both
 * floats through D_004B7810 (0x0032EFC8) and D_004B7814 (0x0032F00C) and converts them
 * with fptosi. */
f32 D_004B7810[9][2] = {
    { 0.0f, 180.0f },
    { 0.0f, 0.0f },
    { 0.0f, 0.0f },
    { 0.0f, 180.0f },
    { 0.0f, 0.0f },
    { 0.0f, -20.0f },
    { 0.0f, 0.0f },
    { 0.0f, 30.0f },
    { 180.0f, -30.0f },
};
