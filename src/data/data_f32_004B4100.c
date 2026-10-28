typedef float f32;
/* func_00162D20 reads field1C indices 0..11 with lwc1 under its signed < 12
 * guard. The thirteenth float continues the table's held tail value and is
 * not reached by that bound; the 13-entry array is then padded to 16 bytes. */
f32 data_f32_004B4100[13] = {
    1.0f, 0.85f, 0.7f, 0.55f, 0.4f, 0.34f, 0.28f, 0.22f, 0.16f, 0.1f, 0.1f, 0.1f, 0.1f,
};
