/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A96B0; /* native record count 0x01 */
    u8 record_base_004A96B1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A96B2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A96B3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A96B4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A96B5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A96B7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A96B8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A96B9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A96BA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A96BB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A96BC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A96BD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A96BE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A96BF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A96C0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A96C1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A96C2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A96C3; /* natively read BE16 header A byte 0x9C */
    u8 preamble_header_B_be16_byte_0_004A96C4; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A96C5; /* natively read BE16 header B byte 0x3E */
    u8 preamble_header_u8_004A96C6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A96C7_004A96CC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A96CD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A96CE_004A96D3[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A96D4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A96D5_004A96D5[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A96D6; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A96D7_004A96DC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A96DD; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A96DE; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A96DF; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A96E0; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A96E1; /* natively read BE16 command parameter byte 0xCD */
    u8 body_opcode_01_skipped_operand_004A96E2[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A96E5_004A96E8[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A96E9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A96EA_004A96F2[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A96F3; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A96F4; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A96F5; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A96F6; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A96F7; /* natively read BE16 command parameter byte 0x74 */
    u8 body_opcode_01_skipped_operand_004A96F8[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A96FB_004A9708[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9709; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A970A_004A970B[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A970C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A970D_004A9711[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9712; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A96B0;
EffectTimelineStream_004A96B0 data_effect_timeline_stream_004A96B0 = {
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
    0x9C,
    0x01,
    0x3E,
    0x80,
    { 0x29, 0x3F, 0x38, 0x34, 0x46, 0x38 },
    0x0D,
    { 0x46, 0x38, 0x3F, 0x38, 0x36, 0x47 },
    0x0D,
    { 0x34 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x04,
    0x00,
    0x01,
    0x00,
    0xCD,
    { 0x01, 0x3E, 0x80 },
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x74,
    { 0x01, 0x3E, 0x80 },
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x3F, 0x42, 0x34, 0x37, 0x8E },
    0x00,
};
