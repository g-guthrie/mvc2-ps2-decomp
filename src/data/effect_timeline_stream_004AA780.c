/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA780; /* native record count 0x01 */
    u8 record_base_004AA781; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA782; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA783; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA784; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA785[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA787; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA788; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA789; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA78A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA78B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA78C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA78D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA78E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA78F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA790; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA791; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA792; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA793; /* native-read BE16 header A 0x93 */
    u8 preamble_header_B_be16_byte_0_004AA794; /* native-read BE16 header B 0x01 */
    u8 preamble_header_B_be16_byte_1_004AA795; /* native-read BE16 header B 0x44 */
    u8 preamble_header_u8_004AA796; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA797_004AA79A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA79B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA79C_004AA7A2[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7A3; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7A4_004AA7A6[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA7A7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA7A8_004AA7AD[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA7AE; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA780;
EffectTimelineStream_004AA780 data_effect_timeline_stream_004AA780 = {
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
    0x93,
    0x01,
    0x44,
    0x80,
    { 0x2D, 0x3B, 0x3C, 0x46 },
    0x0D,
    { 0x26, 0x38, 0x46, 0x46, 0x34, 0x3A, 0x38 },
    0x0D,
    { 0x41, 0x42, 0x47 },
    0x0D,
    { 0x1E, 0x4B, 0x3C, 0x46, 0x47, 0x8E },
    0x00,
};
