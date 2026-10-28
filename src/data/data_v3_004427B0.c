typedef float f32;
/* func_00146710 reads D_004427B0/B4/B8 + p[0x21]*12 (lbu 0x21, stride 12); func_001467E0 loads rows 1 and 2 directly (D_004427BC..D_004427D0). Row count bounded by the next referenced object D_00442828; rows 3..9 have no direct reader, typed by the same stride. */
typedef struct { f32 x, y, z; } V3;
V3 data_v3_004427B0[10] = {
    { 1.0f, 1.0f, 1.0f },
    { 0.97f, 0.57f, 0.67f },
    { 0.97f, 0.57f, 0.67f },
    { 0.37f, 0.13f, 1.0f },
    { 1.0f, 0.6f, 0.0f },
    { 1.0f, 0.6f, 0.0f },
    { 1.0f, 0.6f, 0.0f },
    { 1.0f, 0.2f, 0.2f },
    { 1.0f, 1.0f, 1.0f },
    { 0.95f, 0.55f, 0.65f },
};
