typedef short s16;
/* func_001861B0 reads lh [id*2] (0x00186358) and scales it into actor +0x60.
 * 59 entries, one per character id (the u8 at actor +1), like the other
 * per-character tables here (D_004470D0 is s8[59], data_s16_motion_variants_00447550
 * and _00447CC0 are [59] records read with the same id). */
s16 D_00448780[59] = {
    -160, -384, -160, -384, -64, -384, -160, -128, -128, -160,
    -128, -384, -160, -384, -160, -128, -160, -160, -128, -160,
    -160, -128, -160, -160, -160, -160, -160, -384, -384, -384,
    -160, -160, -160, -128, -160, -160, -128, -160, -160, -224,
    -384, -64, -128, -160, -192, -160, -384, -128, -160, -128,
    -128, -384, -128, -128, -128, -384, -384, -128, -160,
};
