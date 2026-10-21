/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9A40; /* native record count 0x01 */
    u8 record_base_004A9A41; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9A42; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9A43; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9A44; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9A45[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9A47; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9A48; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9A49; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9A4A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9A4B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9A4C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9A4D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9A4E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9A4F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9A50; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9A51; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9A52; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9A53; /* natively read BE16 header A byte 0xAF */
    u8 preamble_header_B_be16_byte_0_004A9A54; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9A55; /* natively read BE16 header B byte 0x76 */
    u8 preamble_header_u8_004A9A56; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9A57_004A9A5E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A5F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A60_004A9A67[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A68; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A69_004A9A69[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9A6A; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9A6B; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9A6C; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9A6D; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9A6E; /* natively read BE16 command parameter byte 0x97 */
    u8 body_opcode_01_skipped_operand_004A9A6F[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9A72_004A9A76[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A77; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A78_004A9A79[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A7A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A7B_004A9A7D[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A7E; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A7F_004A9A84[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A85; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A86_004A9A88[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9A89; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9A8A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9A8B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9A8C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9A8D; /* natively read BE16 command parameter byte 0x99 */
    u8 body_opcode_01_skipped_operand_004A9A8E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9A91_004A9A96[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A97; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A98_004A9A9B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A9C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A9D_004A9AA5[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9AA6; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9AA7; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9AA8; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9AA9; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9AAA; /* natively read BE16 command parameter byte 0x63 */
    u8 body_opcode_01_skipped_operand_004A9AAB[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9AAE_004A9ABC[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9ABD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9ABE_004A9AC3[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9AC4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9AC5_004A9AC6[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9AC7; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9AC8; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9AC9; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9ACA; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9ACB; /* natively read BE16 command parameter byte 0x93 */
    u8 body_opcode_01_skipped_operand_004A9ACC[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9ACF_004A9AD4[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9AD5; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9AD6_004A9AD8[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9AD9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9ADA_004A9ADC[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9ADD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9ADE_004A9AE5[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9AE6; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9A40;
EffectTimelineStream_004A9A40 data_effect_timeline_stream_004A9A40 = {
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
    0xAF,
    0x00,
    0x76,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1C, 0x45, 0x38, 0x34, 0x47, 0x3C, 0x41, 0x3A },
    0x0D,
    { 0x34 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x97,
    { 0x00, 0x76, 0x80 },
    { 0x39, 0x3C, 0x3F, 0x38, 0x96 },
    0x0D,
    { 0x1D, 0x42 },
    0x0D,
    { 0x41, 0x42, 0x47 },
    0x0D,
    { 0x45, 0x38, 0x40, 0x42, 0x49, 0x38 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x99,
    { 0x00, 0x76, 0x80 },
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x63,
    { 0x00, 0x76, 0x80 },
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x95 },
    0x0D,
    { 0x45, 0x38, 0x46, 0x38, 0x47, 0x95 },
    0x0D,
    { 0x42, 0x45 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x93,
    { 0x00, 0x76, 0x80 },
    { 0x46, 0x4A, 0x3C, 0x47, 0x36, 0x3B },
    0x0D,
    { 0x42, 0x39, 0x39 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
