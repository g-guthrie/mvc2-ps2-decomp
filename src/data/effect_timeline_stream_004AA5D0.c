/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA5D0; /* native record count 0x01 */
    u8 record_base_004AA5D1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA5D2; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA5D3; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA5D4; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA5D5[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA5D7; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA5D8; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA5D9; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA5DA; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA5DB; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA5DC; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA5DD; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA5DE; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA5DF; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA5E0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA5E1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA5E2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA5E3; /* native-read BE16 header A 0x77 */
    u8 preamble_header_B_be16_byte_0_004AA5E4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA5E5; /* native-read BE16 header B 0xA0 */
    u8 preamble_header_u8_004AA5E6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA5E7_004AA5EC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5ED; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5EE_004AA5F9[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA5FA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA5FB_004AA600[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA601; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA602; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA603; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA604; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA605; /* native-read BE16 command parameter 0x7B */
    u8 body_opcode_01_skipped_payload_004AA606[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA609_004AA60E[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA60F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA610_004AA610[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA611; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA612_004AA617[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA618; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA619_004AA61C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA61D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA61E_004AA622[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA623; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA624; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA625; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA626; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA627; /* native-read BE16 command parameter 0x6A */
    u8 body_opcode_01_skipped_payload_004AA628[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA62B_004AA62E[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA62F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA630_004AA63D[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA63E; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA63F_004AA642[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA643; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA644; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA645; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA646; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA647; /* native-read BE16 command parameter 0xA8 */
    u8 body_opcode_01_skipped_payload_004AA648[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA64B_004AA64C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA64D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA64E_004AA652[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA653; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA654_004AA657[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA658; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA659_004AA65A[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA65B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA65C_004AA65F[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA660; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA661; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA662; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA663; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA664; /* native-read BE16 command parameter 0x7F */
    u8 body_opcode_01_skipped_payload_004AA665[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA668_004AA66C[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA66D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA66E_004AA66F[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA670; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA671_004AA678[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA679; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA67A_004AA67B[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA67C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA67D_004AA681[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA682; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA5D0;
EffectTimelineStream_004AA5D0 data_effect_timeline_stream_004AA5D0 = {
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
    0x77,
    0x00,
    0xA0,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x22, 0x41, 0x46, 0x48, 0x39, 0x39, 0x3C, 0x36, 0x3C, 0x38, 0x41, 0x47 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7B,
    { 0x00, 0xA0, 0x80 },
    { 0x46, 0x43, 0x34, 0x36, 0x38, 0x8E },
    0x0D,
    { 0x1A },
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
    0x6A,
    { 0x00, 0xA0, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA8,
    { 0x00, 0xA0, 0x80 },
    { 0x34, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x15, 0x17, 0x24, 0x1B },
    0x0D,
    { 0x42, 0x39 },
    0x0D,
    { 0x39, 0x45, 0x38, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7F,
    { 0x00, 0xA0, 0x80 },
    { 0x46, 0x43, 0x34, 0x36, 0x38 },
    0x0D,
    { 0x3C, 0x46 },
    0x0D,
    { 0x45, 0x38, 0x44, 0x48, 0x3C, 0x45, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x8E },
    0x00,
};
