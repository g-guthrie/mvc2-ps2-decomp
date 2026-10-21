/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9FE0; /* native record count 0x01 */
    u8 record_base_004A9FE1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9FE2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9FE3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004A9FE4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9FE5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004A9FE7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9FE8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004A9FE9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9FEA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004A9FEB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9FEC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004A9FED; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9FEE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004A9FEF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9FF0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004A9FF1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9FF2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9FF3; /* native-read BE16 header A 0xA3 */
    u8 preamble_header_B_be16_byte_0_004A9FF4; /* native-read BE16 header B 0xFC */
    u8 preamble_header_B_be16_byte_1_004A9FF5; /* native-read BE16 header B 0xDB */
    u8 preamble_header_u8_004A9FF6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004A9FF7_004A9FFE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9FFF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA000_004AA00A[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA00B; /* native body command opcode 0x00 */
} EffectTimelineStream_004A9FE0;
EffectTimelineStream_004A9FE0 data_effect_timeline_stream_004A9FE0 = {
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
    0xFC,
    0xDB,
    0x80,
    { 0x1A, 0x48, 0x47, 0x42, 0x3F, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x46, 0x48, 0x36, 0x36, 0x38, 0x46, 0x46, 0x39, 0x48, 0x3F, 0x8E },
    0x00,
};
