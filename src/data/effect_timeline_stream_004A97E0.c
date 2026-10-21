/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A97E0; /* native record count 0x01 */
    u8 record_base_004A97E1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A97E2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A97E3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A97E4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A97E5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A97E7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A97E8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A97E9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A97EA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A97EB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A97EC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A97ED; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A97EE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A97EF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A97F0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A97F1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A97F2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A97F3; /* natively read BE16 header A byte 0xAE */
    u8 preamble_header_B_be16_byte_0_004A97F4; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A97F5; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A97F6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A97F7_004A97FC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97FD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A97FE_004A9801[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9802; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9803_004A9809[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A980A; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A97E0;
EffectTimelineStream_004A97E0 data_effect_timeline_stream_004A97E0 = {
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
    0xAE,
    0x01,
    0x44,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x25, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x8E },
    0x00,
};
