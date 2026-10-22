/* 12 float 3-vectors (x, y, z). Layout confirmed by the byte pattern; reader not yet traced. */
typedef struct Vec3f { float x; float y; float z; } Vec3f;
typedef char data_raw_0043DDC8_size_check[(sizeof(Vec3f) * 12 == 144) ? 1 : -1];
Vec3f data_raw_0043DDC8[12] = {
    { -220.5f, 82.1999969f, -130.0f },
    { 220.5f, 82.1999969f, -130.0f },
    { -271.0f, 103.5f, -190.5f },
    { 271.0f, 103.5f, -190.5f },
    { -271.0f, 90.6999969f, -190.5f },
    { 271.0f, 90.6999969f, -190.5f },
    { -20.5f, 182.199997f, -130.0f },
    { 20.5f, 182.199997f, -130.0f },
    { -71.0f, 203.5f, -190.5f },
    { 71.0f, 203.5f, -190.5f },
    { -71.0f, 190.699997f, -190.5f },
    { 71.0f, 190.699997f, -190.5f },
};
