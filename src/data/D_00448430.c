typedef short s16;
/* func_00182300 reads lh [id*2] and stores it scaled into actor +0x6C.
 * 59 entries, one per character id (the u8 at actor +1), like the other
 * per-character tables here (D_004470D0 is s8[59], data_s16_motion_variants_00447550
 * and _00447CC0 are [59] records read with the same id). */
s16 D_00448430[59] = {
    -80, -80, -80, -72, -80, -80, -80, -80, -80, -80,
    -80, -80, -80, -96, -80, -80, -80, -80, -80, -80,
    -80, -80, -80, -80, -80, -80, -80, -80, -64, -64,
    -80, -80, -80, -80, -80, -80, -80, -80, -80, -80,
    -80, -80, -80, -80, -80, -80, -80, -80, -80, -80,
    -80, -80, -80, -88, -96, -76, -88, -80, -80,
};
