/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA7B0; /* native record count 0x01 */
    u8 record_base_004AA7B1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA7B2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA7B3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA7B4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA7B5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA7B7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA7B8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA7B9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA7BA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA7BB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA7BC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA7BD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA7BE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA7BF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA7C0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA7C1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA7C2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA7C3; /* native-read BE16 header A 0x78 */
    u8 preamble_header_B_be16_byte_0_004AA7C4; /* native-read BE16 header B 0x01 */
    u8 preamble_header_B_be16_byte_1_004AA7C5; /* native-read BE16 header B 0x44 */
    u8 preamble_header_u8_004AA7C6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA7C7_004AA7CE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7CF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7D0_004AA7D5[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7D6; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7D7_004AA7DA[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7DB; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7DC_004AA7E0[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA7E1; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA7E2; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA7E3; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA7E4; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA7E5; /* native-read BE16 command parameter 0x85 */
    u8 body_opcode_01_skipped_payload_004AA7E6[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA7E9_004AA7EC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7ED; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7EE_004AA7FC[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA7FD; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA7B0;
EffectTimelineStream_004AA7B0 data_effect_timeline_stream_004AA7B0 = {
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
    0x78,
    0x01,
    0x44,
    0x80,
    { 0x1C, 0x3B, 0x38, 0x36, 0x3E, 0x3C, 0x41, 0x3A },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x18, 0x26, 0x1B, 0x94 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x85,
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x8E },
    0x00,
};
