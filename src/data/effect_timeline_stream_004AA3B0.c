/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA3B0; /* native record count 0x01 */
    u8 record_base_004AA3B1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA3B2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA3B3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA3B4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA3B5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA3B7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA3B8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA3B9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA3BA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA3BB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA3BC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA3BD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA3BE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA3BF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA3C0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA3C1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA3C2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA3C3; /* native-read BE16 header A 0xA3 */
    u8 preamble_header_B_be16_byte_0_004AA3C4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA3C5; /* native-read BE16 header B 0xA8 */
    u8 preamble_header_u8_004AA3C6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA3C7_004AA3CC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA3CD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA3CE_004AA3CF[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA3D0; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA3D1_004AA3D6[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA3D7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA3D8_004AA3DB[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA3DC; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA3DD; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA3DE; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA3DF; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA3E0; /* native-read BE16 command parameter 0x62 */
    u8 body_opcode_01_skipped_payload_004AA3E1[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA3E4_004AA3EC[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA3ED; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA3EE_004AA3FB[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA3FC; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA3FD; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA3FE; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA3FF; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA400; /* native-read BE16 command parameter 0x98 */
    u8 body_opcode_01_skipped_payload_004AA401[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA404_004AA408[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA409; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA40A_004AA40B[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA40C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA40D_004AA412[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA413; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA414_004AA417[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA418; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA419; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA41A; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA41B; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA41C; /* native-read BE16 command parameter 0x0B */
    u8 body_opcode_01_skipped_payload_004AA41D[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA420_004AA423[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA424; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA425_004AA426[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA427; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA3B0;
EffectTimelineStream_004AA3B0 data_effect_timeline_stream_004AA3B0 = {
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
    0x00,
    0xA8,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x27, 0x42 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x62,
    { 0x00, 0xA8, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x98,
    { 0x00, 0xA8, 0x80 },
    { 0x39, 0x42, 0x48, 0x41, 0x37 },
    0x0D,
    { 0x3C, 0x41 },
    0x0D,
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 },
    0x0D,
    { 0x5C, 0x5A, 0x6B, 0x5D },
    0x04,
    0x00,
    0x01,
    0x01,
    0x0B,
    { 0x00, 0xA8, 0x80 },
    { 0x46, 0x3F, 0x42, 0x47 },
    0x0D,
    { 0x19, 0x8E },
    0x00,
};
