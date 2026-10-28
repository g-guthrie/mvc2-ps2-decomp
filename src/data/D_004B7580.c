typedef float f32;
/* Four-float rows indexed by p[0x1B7] (0..1) at 0x002B5358 and 0x002B5634
 * (q9_a.c E_10, y6_d.c T4: { f32 a, b, c, d; }). */
typedef struct { f32 a, b, c, d; } Mvc2VariantMotionCoeffs;
Mvc2VariantMotionCoeffs D_004B7580[2] = {
    { -6.6666665f, 0.0f, 12.857142f, -1.0714285f },
    { -8.333333f, 0.0f, 7.5f, -0.3348214f },
};
