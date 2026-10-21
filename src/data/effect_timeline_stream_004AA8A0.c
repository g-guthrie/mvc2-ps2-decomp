/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA8A0; /* native record count 0x01 */
    u8 record_base_004AA8A1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA8A2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA8A3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA8A4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA8A5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA8A7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA8A8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA8A9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA8AA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA8AB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA8AC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA8AD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA8AE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA8AF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA8B0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA8B1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA8B2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA8B3; /* native-read BE16 header A 0x7F */
    u8 preamble_header_B_be16_byte_0_004AA8B4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA8B5; /* native-read BE16 header B 0x90 */
    u8 preamble_header_u8_004AA8B6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA8B7_004AA8BC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8BD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8BE_004AA8C9[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8CA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8CB_004AA8CF[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA8D0; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA8D1; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA8D2; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA8D3; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA8D4; /* native-read BE16 command parameter 0x9F */
    u8 body_opcode_01_skipped_payload_004AA8D5[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA8D8_004AA8D9[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8DA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8DB_004AA8E0[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8E1; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8E2_004AA8E5[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8E6; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8E7_004AA8EC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA8ED; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA8EE; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA8EF; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA8F0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA8F1; /* native-read BE16 command parameter 0x7C */
    u8 body_opcode_01_skipped_payload_004AA8F2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA8F5_004AA8F6[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8F7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8F8_004AA8FC[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA8FD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA8FE_004AA901[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA902; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA903_004AA904[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA905; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA906_004AA909[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA90A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA90B_004AA90F[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA910; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA911; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA912; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA913; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA914; /* native-read BE16 command parameter 0x87 */
    u8 body_opcode_01_skipped_payload_004AA915[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA918_004AA919[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA91A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA91B_004AA922[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA923; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA924_004AA925[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA926; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA927_004AA92B[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA92C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA92D_004AA930[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA931; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA932; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA933; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA934; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA935; /* native-read BE16 command parameter 0x83 */
    u8 body_opcode_01_skipped_payload_004AA936[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA939_004AA93B[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA93C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA93D_004AA941[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA942; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA943_004AA949[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA94A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA94B_004AA951[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA952; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA953; /* native-read command operand 0x18 */
    u8 body_opcode_01_004AA954; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA955; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA956; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_skipped_payload_004AA957[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA95A_004AA95C[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004AA95D; /* native body command opcode 0x05 */
    u8 body_opcode_05_004AA95E; /* native body command opcode 0x05 */
    u8 body_glyph_native_codes_004AA95F_004AA960[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA961; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA8A0;
EffectTimelineStream_004AA8A0 data_effect_timeline_stream_004AA8A0 = {
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
    0x7F,
    0x00,
    0x90,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x22, 0x41, 0x46, 0x48, 0x39, 0x39, 0x3C, 0x36, 0x3C, 0x38, 0x41, 0x47 },
    0x0D,
    { 0x46, 0x43, 0x34, 0x36, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x90, 0x80 },
    { 0x42, 0x41 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x29, 0x2C, 0x12, 0x94, 0x8E },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7C,
    { 0x00, 0x90, 0x80 },
    { 0x1A, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x15, 0x17, 0x24, 0x1B },
    0x0D,
    { 0x42, 0x39 },
    0x0D,
    { 0x39, 0x45, 0x38, 0x38 },
    0x0D,
    { 0x46, 0x43, 0x34, 0x36, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x87,
    { 0x00, 0x90, 0x80 },
    { 0x3C, 0x46 },
    0x0D,
    { 0x45, 0x38, 0x44, 0x48, 0x3C, 0x45, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x8E },
    0x0D,
    { 0x30, 0x3C, 0x3F, 0x3F },
    0x04,
    0x00,
    0x01,
    0x00,
    0x83,
    { 0x00, 0x90, 0x80 },
    { 0x4C, 0x42, 0x48 },
    0x0D,
    { 0x46, 0x47, 0x34, 0x45, 0x47 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B, 0x42, 0x48, 0x47 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x3C, 0x41, 0x3A, 0x8F },
    0x04,
    0x18,
    0x01,
    0x01,
    0x00,
    { 0x00, 0x90, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
