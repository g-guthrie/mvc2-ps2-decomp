/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9ED0; /* native record count 0x01 */
    u8 record_base_004A9ED1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9ED2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9ED3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004A9ED4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9ED5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004A9ED7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9ED8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004A9ED9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9EDA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004A9EDB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9EDC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004A9EDD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9EDE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004A9EDF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9EE0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004A9EE1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9EE2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9EE3; /* native-read BE16 header A 0x8A */
    u8 preamble_header_B_be16_byte_0_004A9EE4; /* native-read BE16 header B 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9EE5; /* native-read BE16 header B 0x44 */
    u8 preamble_header_u8_004A9EE6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004A9EE7_004A9EEE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EEF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EF0_004A9EF7[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EF8; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EF9_004A9EFA[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EFB; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EFC_004A9EFE[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9EFF; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004A9F00; /* native-read command operand 0x00 */
    u8 body_opcode_01_004A9F01; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9F02; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9F03; /* native-read BE16 command parameter 0x9C */
    u8 body_opcode_01_skipped_payload_004A9F04[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004A9F07_004A9F0C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F0D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F0E_004A9F10[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F11; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F12_004A9F17[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F18; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F19_004A9F1C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9F1D; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004A9F1E; /* native-read command operand 0x00 */
    u8 body_opcode_01_004A9F1F; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9F20; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9F21; /* native-read BE16 command parameter 0x59 */
    u8 body_opcode_01_skipped_payload_004A9F22[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004A9F25_004A9F2D[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F2E; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F2F_004A9F3D[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9F3E; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004A9F3F; /* native-read command operand 0x00 */
    u8 body_opcode_01_004A9F40; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9F41; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9F42; /* native-read BE16 command parameter 0x7F */
    u8 body_opcode_01_skipped_payload_004A9F43[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004A9F46_004A9F47[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F48; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F49_004A9F4E[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F4F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F50_004A9F52[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F53; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F54_004A9F56[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F57; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F58_004A9F5F[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9F60; /* native body command opcode 0x00 */
} EffectTimelineStream_004A9ED0;
EffectTimelineStream_004A9ED0 data_effect_timeline_stream_004A9ED0 = {
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
    0x8A,
    0x01,
    0x44,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x25, 0x42, 0x34, 0x37, 0x3C, 0x41, 0x3A, 0x96 },
    0x0D,
    { 0x1D, 0x42 },
    0x0D,
    { 0x41, 0x42, 0x47 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9C,
    { 0x01, 0x44, 0x80 },
    { 0x45, 0x38, 0x40, 0x42, 0x49, 0x38 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x59,
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x95 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7F,
    { 0x01, 0x44, 0x80 },
    { 0x42, 0x45 },
    0x0D,
    { 0x46, 0x4A, 0x3C, 0x47, 0x36, 0x3B },
    0x0D,
    { 0x42, 0x39, 0x39 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
