/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A95B0; /* native record count 0x01 */
    u8 record_base_004A95B1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A95B2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A95B3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A95B4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A95B5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A95B7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A95B8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A95B9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A95BA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A95BB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A95BC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A95BD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A95BE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A95BF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A95C0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A95C1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A95C2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A95C3; /* natively read BE16 header A byte 0xAE */
    u8 preamble_header_B_be16_byte_0_004A95C4; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A95C5; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A95C6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A95C7_004A95CC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A95CD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A95CE_004A95D1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A95D2; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A95D3_004A95D9[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A95DA; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A95B0;
EffectTimelineStream_004A95B0 data_effect_timeline_stream_004A95B0 = {
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
    { 0x2C, 0x34, 0x49, 0x38 },
    0x0D,
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x8E },
    0x00,
};
