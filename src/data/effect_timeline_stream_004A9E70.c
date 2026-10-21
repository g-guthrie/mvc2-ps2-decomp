/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9E70; /* native record count 0x01 */
    u8 record_base_004A9E71; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9E72; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9E73; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9E74; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9E75[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9E77; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9E78; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9E79; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9E7A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9E7B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9E7C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9E7D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9E7E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9E7F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9E80; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9E81; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9E82; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9E83; /* natively read BE16 header A byte 0xBB */
    u8 preamble_header_B_be16_byte_0_004A9E84; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9E85; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9E86; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9E87_004A9E8E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9E8F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9E90_004A9E97[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9E98; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9E99; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9E9A; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9E9B; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9E9C; /* natively read BE16 command parameter byte 0xC8 */
    u8 body_opcode_01_skipped_operand_004A9E9D[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9EA0_004A9EA7[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EA8; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EA9_004A9EAC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EAD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EAE_004A9EAF[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9EB0; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9EB1; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9EB2; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9EB3; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9EB4; /* natively read BE16 command parameter byte 0xEB */
    u8 body_opcode_01_skipped_operand_004A9EB5[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9EB8_004A9EBD[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9EBE; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9EBF_004A9EC2[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9EC3; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9E70;
EffectTimelineStream_004A9E70 data_effect_timeline_stream_004A9E70 = {
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
    0xBB,
    0x01,
    0x44,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1A, 0x48, 0x47, 0x42, 0x46, 0x34, 0x49, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xC8,
    { 0x01, 0x44, 0x80 },
    { 0x39, 0x48, 0x41, 0x36, 0x47, 0x3C, 0x42, 0x41 },
    0x0D,
    { 0x4A, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x35, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xEB,
    { 0x01, 0x44, 0x80 },
    { 0x47, 0x48, 0x45, 0x41, 0x38, 0x37 },
    0x0D,
    { 0x42, 0x39, 0x39, 0x8E },
    0x00,
};
