/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9890; /* native record count 0x01 */
    u8 record_base_004A9891; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9892; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9893; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9894; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9895[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9897; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9898; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9899; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A989A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A989B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A989C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A989D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A989E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A989F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A98A0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A98A1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A98A2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A98A3; /* natively read BE16 header A byte 0x78 */
    u8 preamble_header_B_be16_byte_0_004A98A4; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A98A5; /* natively read BE16 header B byte 0xB0 */
    u8 preamble_header_u8_004A98A6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A98A7_004A98AE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A98AF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A98B0_004A98B5[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A98B6; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A98B7_004A98BA[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A98BB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A98BC_004A98C0[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A98C1; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A98C2; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A98C3; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A98C4; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A98C5; /* natively read BE16 command parameter byte 0x85 */
    u8 body_opcode_01_skipped_operand_004A98C6[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A98C9_004A98CC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A98CD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A98CE_004A98DC[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A98DD; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9890;
EffectTimelineStream_004A9890 data_effect_timeline_stream_004A9890 = {
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
    0x00,
    0xB0,
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
    { 0x00, 0xB0, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x8E },
    0x00,
};
