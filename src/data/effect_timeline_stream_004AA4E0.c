/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA4E0; /* native record count 0x01 */
    u8 record_base_004AA4E1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA4E2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA4E3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA4E4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA4E5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA4E7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA4E8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA4E9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA4EA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA4EB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA4EC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA4ED; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA4EE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA4EF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA4F0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA4F1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA4F2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA4F3; /* native-read BE16 header A 0x9E */
    u8 preamble_header_B_be16_byte_0_004AA4F4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA4F5; /* native-read BE16 header B 0xD0 */
    u8 preamble_header_u8_004AA4F6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA4F7_004AA4FC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA4FD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA4FE_004AA503[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA504; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA505_004AA50B[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA50C; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA4E0;
EffectTimelineStream_004AA4E0 data_effect_timeline_stream_004AA4E0 = {
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
    0x9E,
    0x00,
    0xD0,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x1F, 0x42, 0x45, 0x40, 0x34, 0x47 },
    0x0D,
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x8E },
    0x00,
};
