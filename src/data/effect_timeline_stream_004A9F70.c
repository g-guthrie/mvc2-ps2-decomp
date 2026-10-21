/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9F70; /* native record count 0x01 */
    u8 record_base_004A9F71; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9F72; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9F73; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004A9F74; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9F75[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004A9F77; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9F78; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004A9F79; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9F7A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004A9F7B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9F7C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004A9F7D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9F7E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004A9F7F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9F80; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004A9F81; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9F82; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9F83; /* native-read BE16 header A 0x9B */
    u8 preamble_header_B_be16_byte_0_004A9F84; /* native-read BE16 header B 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9F85; /* native-read BE16 header B 0x44 */
    u8 preamble_header_u8_004A9F86; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004A9F87_004A9F8C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F8D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F8E_004A9F90[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F91; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F92_004A9F97[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9F98; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9F99_004A9F9C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9F9D; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004A9F9E; /* native-read command operand 0x00 */
    u8 body_opcode_01_004A9F9F; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9FA0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9FA1; /* native-read BE16 command parameter 0x62 */
    u8 body_opcode_01_skipped_payload_004A9FA2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004A9FA5_004A9FAD[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9FAE; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9FAF_004A9FBC[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9FBD; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004A9FBE; /* native-read command operand 0x00 */
    u8 body_opcode_01_004A9FBF; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9FC0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9FC1; /* native-read BE16 command parameter 0xCB */
    u8 body_opcode_01_skipped_payload_004A9FC2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004A9FC5_004A9FC6[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9FC7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004A9FC8_004A9FD3[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9FD4; /* native body command opcode 0x00 */
} EffectTimelineStream_004A9F70;
EffectTimelineStream_004A9F70 data_effect_timeline_stream_004A9F70 = {
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
    0x9B,
    0x01,
    0x44,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x2D, 0x3B, 0x38 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x62,
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xCB,
    { 0x01, 0x44, 0x80 },
    { 0x3C, 0x46 },
    0x0D,
    { 0x48, 0x41, 0x39, 0x42, 0x45, 0x40, 0x34, 0x47, 0x47, 0x38, 0x37, 0x8E },
    0x00,
};
