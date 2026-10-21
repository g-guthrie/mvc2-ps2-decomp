/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9360; /* native record count 0x01 */
    u8 record_base_004A9361; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9362; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9363; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9364; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9365[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9367; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9368; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9369; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A936A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A936B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A936C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A936D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A936E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A936F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9370; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9371; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9372; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9373; /* natively read BE16 header A byte 0x9C */
    u8 preamble_header_B_be16_byte_0_004A9374; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9375; /* natively read BE16 header B byte 0x3E */
    u8 preamble_header_u8_004A9376; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9377_004A937C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A937D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A937E_004A9383[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9384; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9385_004A9385[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9386; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9387_004A938C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A938D; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A938E; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A938F; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9390; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9391; /* natively read BE16 command parameter byte 0xCD */
    u8 body_opcode_01_skipped_operand_004A9392[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9395_004A9398[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9399; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A939A_004A93A2[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A93A3; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A93A4; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A93A5; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A93A6; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A93A7; /* natively read BE16 command parameter byte 0x74 */
    u8 body_opcode_01_skipped_operand_004A93A8[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A93AB_004A93B8[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A93B9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A93BA_004A93BB[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A93BC; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A93BD_004A93C1[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A93C2; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9360;
EffectTimelineStream_004A9360 data_effect_timeline_stream_004A9360 = {
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
    { 0x46, 0x34, 0x49, 0x38, 0x8E },
    0x00,
};
