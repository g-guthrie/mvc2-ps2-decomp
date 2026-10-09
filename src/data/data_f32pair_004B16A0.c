/* Six pair records are selected by fixed indices 0..5; each holds two 3D endpoints. */
typedef float f32;
typedef struct { f32 value[3]; } F32Vector3;
typedef struct { F32Vector3 endpoints[2]; } F32VectorPair;
F32VectorPair data_f32pair_004B16A0[6] = {
    { { { -260.0f, 330.0f, 700.0f }, { -130.0f, 243.0f, 400.0f } } },
    { { { -260.0f, 130.0f, 700.0f }, { -130.0f, 140.0f, 400.0f } } },
    { { { -81.0f, 30.0f, 700.0f }, { -40.5f, 90.0f, 400.0f } } },
    { { { 81.0f, 350.0f, 700.0f }, { 40.5f, 250.0f, 400.0f } } },
    { { { 260.0f, 250.0f, 700.0f }, { 130.0f, 200.0f, 400.0f } } },
    { { { 260.0f, 50.0f, 700.0f }, { 130.0f, 97.0f, 400.0f } } },
};
