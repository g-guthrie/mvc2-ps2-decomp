typedef float f32;
typedef struct { f32 x, y, z; } V3;
/* The exact caller iterates selectors 0..3; consumers load this V3 table
 * at selectors 0, 2, and 3 (selector 1 uses the separate fixed vector). */
V3 D_00443DF0[4] = {
    { 1.0f, 0.300000012f, 1.0f },
    { 1.0f, 0.300000012f, 1.0f },
    { 1.0f, 0.300000012f, 1.0f },
    { 0.600000024f, 0.300000012f, 1.0f },
};
