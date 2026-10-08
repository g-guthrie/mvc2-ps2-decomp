/* Six per-particle scale vectors; the initializer reads x/y/z via the AF0/AF4/AF8 aliases. */
typedef struct { float x, y, z; } Vector3;
Vector3 gMvc2ParticleScaleVectors_00444AF0[6] = {
    {0.0500000007f, 0.0250000004f, 0.0500000007f},
    {0.0250000004f, 0.0500000007f, 0.0500000007f},
    {0.0500000007f, 0.0250000004f, 0.0500000007f},
    {0.0250000004f, 0.0500000007f, 0.0500000007f},
    {0.0500000007f, 0.0250000004f, 0.0500000007f},
    {0.0250000004f, 0.0500000007f, 0.0500000007f},
};
