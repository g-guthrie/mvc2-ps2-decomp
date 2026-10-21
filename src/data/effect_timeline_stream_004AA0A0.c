/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA0A0; /* native record count 0x01 */
    u8 record_base_004AA0A1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA0A2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA0A3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA0A4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA0A5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA0A7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA0A8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA0A9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA0AA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA0AB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA0AC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA0AD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA0AE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA0AF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA0B0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA0B1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA0B2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA0B3; /* native-read BE16 header A 0xBB */
    u8 preamble_header_B_be16_byte_0_004AA0B4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA0B5; /* native-read BE16 header B 0xB0 */
    u8 preamble_header_u8_004AA0B6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA0B7_004AA0BE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA0BF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA0C0_004AA0C7[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA0C8; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA0C9; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA0CA; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA0CB; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA0CC; /* native-read BE16 command parameter 0xC8 */
    u8 body_opcode_01_skipped_payload_004AA0CD[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA0D0_004AA0D7[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA0D8; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA0D9_004AA0DC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA0DD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA0DE_004AA0DF[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA0E0; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA0E1; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA0E2; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA0E3; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA0E4; /* native-read BE16 command parameter 0xEB */
    u8 body_opcode_01_skipped_payload_004AA0E5[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA0E8_004AA0ED[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA0EE; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA0EF_004AA0F2[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA0F3; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA0A0;
EffectTimelineStream_004AA0A0 data_effect_timeline_stream_004AA0A0 = {
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
    0xBB,
    0x00,
    0xB0,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1A, 0x48, 0x47, 0x42, 0x46, 0x34, 0x49, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xC8,
    { 0x00, 0xB0, 0x80 },
    { 0x39, 0x48, 0x41, 0x36, 0x47, 0x3C, 0x42, 0x41 },
    0x0D,
    { 0x4A, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x35, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xEB,
    { 0x00, 0xB0, 0x80 },
    { 0x47, 0x48, 0x45, 0x41, 0x38, 0x37 },
    0x0D,
    { 0x42, 0x39, 0x39, 0x8E },
    0x00,
};
