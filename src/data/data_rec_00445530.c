typedef float f32;
/* Per-frame scale/alpha table: func_00160E50 reads one f32 per step through
 * lwc1 0($v1 + (s16 index << 2)) for indices 0..0x28 (wave1x.c); the stored
 * span runs to 44 entries. Zero lead-in, 1.0 plateau, then a 0.8..0.1 fade. */
f32 data_rec_00445530[44] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    0.8f, 0.6f, 0.4f, 0.3f, 0.2f, 0.1f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
