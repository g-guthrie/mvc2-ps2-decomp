typedef float f32;
/* Signed 4-bit value n (0..7, then -8..-1 for nibbles 8..15) scaled by 65536 as f32, laid out
 * directly before the byte-indexed 256-entry f32 tables data_f32_004BB688 (high nibble * 65536,
 * read with lwc1 by func_003FA040/func_003FA1B0/func_003FA448) and D_004BBA88. No direct reader
 * of this 16-entry table was found; every word is an exact float of that series. */
f32 data_u8_004BB648[16] = {
    0.0f, 65536.0f, 131072.0f, 196608.0f, 262144.0f, 327680.0f, 393216.0f, 458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f, -65536.0f,
};
