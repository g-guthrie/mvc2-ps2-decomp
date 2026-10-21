/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA570; /* native record count 0x01 */
    u8 record_base_004AA571; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA572; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA573; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA574; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA575[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA577; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA578; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA579; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA57A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA57B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA57C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA57D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA57E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA57F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA580; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA581; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA582; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA583; /* native-read BE16 header A 0x80 */
    u8 preamble_header_B_be16_byte_0_004AA584; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA585; /* native-read BE16 header B 0xD0 */
    u8 preamble_header_u8_004AA586; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA587_004AA58E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA58F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA590_004AA591[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA592; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA593_004AA599[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA59A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA59B_004AA59D[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA59E; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA59F; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA5A0; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA5A1; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA5A2; /* native-read BE16 command parameter 0x70 */
    u8 body_opcode_01_skipped_payload_004AA5A3[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA5A6_004AA5AB[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5AC; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5AD_004AA5AE[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5AF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5B0_004AA5B3[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5B4; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5B5_004AA5B8[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5B9; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5BA_004AA5BF[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA5C0; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA570;
EffectTimelineStream_004AA570 data_effect_timeline_stream_004AA570 = {
    0x01,
    0x00,
    0x0B,
    0x00,
    0x0C,
    { 0x00, 0x00 },
    0x05,
    0x18,
    0x06,
    0xFF,
    0x07,
    0xFF,
    0x08,
    0xFF,
    0x09,
    0xFF,
    0x01,
    0x00,
    0x80,
    0x00,
    0xD0,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x27, 0x42 },
    0x0D,
    { 0x98, 0x66, 0x5A, 0x6B, 0x6F, 0x5E, 0x65 },
    0x0D,
    { 0x6F, 0x6C, 0x8E },
    0x04,
    0x00,
    0x01,
    0x00,
    0x70,
    { 0x00, 0xD0, 0x80 },
    { 0x5C, 0x5A, 0x69, 0x5C, 0x68, 0x66 },
    0x0D,
    { 0x52, 0x99 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38 },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x39, 0x42, 0x48, 0x41, 0x37, 0x8E },
    0x00,
};
