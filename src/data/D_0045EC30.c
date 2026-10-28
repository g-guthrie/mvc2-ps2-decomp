typedef float f32;
typedef struct { f32 x, y, z; } V3;
/* Rotation triples (degrees) for the same four spawns: func_0033B6E0 reads
 * .y as D_0045EC34[a * 3] (lwc1) and converts it to a 16-bit angle. All zero in retail. */
V3 D_0045EC30[4] = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
