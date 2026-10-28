typedef signed short s16;

/* Time/angle half of an angle+scale track key (RotScaleKey: s16 time, s16 angle in degrees,
 * f32 scale x, f32 scale y, read by func_001415B0 for event category 6). key 4 of the track at 0x004415A0 (event 0x08);
 * its two scale floats are the 1.0/1.0 pair in data_f32_one_004415D4. */
typedef struct { s16 time; s16 angle; } data_u32_004415D0_key;
typedef char data_u32_004415D0_key_size_check[(sizeof(data_u32_004415D0_key) == 4) ? 1 : -1];

data_u32_004415D0_key data_u32_004415D0 = { 360, 1170 };
