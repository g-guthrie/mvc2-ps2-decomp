/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9E10; /* native record count 0x01 */
    u8 record_base_004A9E11; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9E12; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9E13; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9E14; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9E15[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9E17; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9E18; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9E19; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9E1A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9E1B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9E1C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9E1D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9E1E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9E1F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9E20; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9E21; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9E22; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9E23; /* natively read BE16 header A byte 0xA3 */
    u8 preamble_header_B_be16_byte_0_004A9E24; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9E25; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9E26; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9E27_004A9E2C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9E2D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9E2E_004A9E2F[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9E30; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9E31_004A9E36[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9E37; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9E38_004A9E3B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9E3C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9E3D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9E3E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9E3F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9E40; /* natively read BE16 command parameter byte 0x62 */
    u8 body_opcode_01_skipped_operand_004A9E41[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9E44_004A9E4C[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9E4D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9E4E_004A9E5B[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9E5C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9E5D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9E5E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9E5F; /* natively read BE16 command parameter byte 0x01 */
    u8 body_opcode_01_be16_byte_1_004A9E60; /* natively read BE16 command parameter byte 0x0F */
    u8 body_opcode_01_skipped_operand_004A9E61[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9E64_004A9E69[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9E6A; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9E10;
EffectTimelineStream_004A9E10 data_effect_timeline_stream_004A9E10 = {
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
    0xA3,
    0x01,
    0x44,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x27, 0x42 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x62,
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x04,
    0x00,
    0x01,
    0x01,
    0x0F,
    { 0x01, 0x44, 0x80 },
    { 0x39, 0x42, 0x48, 0x41, 0x37, 0x8E },
    0x00,
};
