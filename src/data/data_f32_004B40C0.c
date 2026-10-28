typedef float f32;
/* func_00162D20 reads field1C indices 0..11 with lwc1 under its signed < 12
 * guard. The thirteenth float continues the table's held tail value and is
 * not reached by that bound; the 13-entry array is then padded to 16 bytes. */
f32 data_f32_004B40C0[13] = {
    1.0f, 1.25f, 1.5f, 1.75f, 2.0f, 2.2f, 2.4f, 2.6f, 2.8f, 3.0f, 3.0f, 3.0f, 3.0f,
};
