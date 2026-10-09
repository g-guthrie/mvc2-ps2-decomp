typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
/* func_0013BF80 selects this bank only when config field0x85 != 7. It loops selectors 0..6, advances by 12 bytes, and loads three floats per row; D_00440494 begins immediately after these seven vectors and remains raw. */
F32Vector3 data_f32v3_00440440[7] = {
    { { 1.7999999523162842f, 0.0f, -215.0f } },
    { { -73.5999984741211f, 0.0f, -202.0f } },
    { { -138.1999969482422f, 0.0f, -164.6999969482422f } },
    { { -186.1999969482422f, 0.0f, -107.5f } },
    { { -211.6999969482422f, 0.0f, -37.29999923706055f } },
    { { -211.6999969482422f, 0.0f, 37.29999923706055f } },
    { { -186.1999969482422f, 0.0f, 107.5f } },
};
