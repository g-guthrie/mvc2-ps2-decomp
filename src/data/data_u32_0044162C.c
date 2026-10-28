typedef signed short s16;

/* Time/angle half of an angle+scale track key (RotScaleKey: s16 time, s16 angle in degrees,
 * f32 scale x, f32 scale y, read by func_001415B0 for event category 6). key 1 of D_00441620 (channel 7);
 * its two scale floats are the 1.0/1.0 pair in data_f32_one_00441630. */
typedef struct { s16 time; s16 angle; } data_u32_0044162C_key;
typedef char data_u32_0044162C_key_size_check[(sizeof(data_u32_0044162C_key) == 4) ? 1 : -1];

data_u32_0044162C_key data_u32_0044162C = { 180, 630 };
