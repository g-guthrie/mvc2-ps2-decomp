typedef float f32;

typedef struct {
    f32 value[2];
} RenderCoordinatePair;

/* func_0016E080 reads the first two pairs directly, then five pairs
 * at base + 0x10 with an 8-byte stride. The next label begins at 0x004B5328. */
RenderCoordinatePair data_render_coordinate_pairs_004B52F0[7] = {
    {{118.0f, 208.0f}},
    {{208.0f, 298.0f}},
    {{90.0f, 96.0f}},
    {{124.0f, 148.0f}},
    {{156.0f, 180.0f}},
    {{188.0f, 212.0f}},
    {{228.0f, 252.0f}},
};
