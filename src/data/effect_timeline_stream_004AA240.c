/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA240; /* native record count 0x01 */
    u8 record_base_004AA241; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA242; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA243; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA244; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA245[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA247; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA248; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA249; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA24A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA24B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA24C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA24D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA24E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA24F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA250; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA251; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA252; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA253; /* native-read BE16 header A 0x7F */
    u8 preamble_header_B_be16_byte_0_004AA254; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA255; /* native-read BE16 header B 0x60 */
    u8 preamble_header_u8_004AA256; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA257_004AA25C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA25D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA25E_004AA269[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA26A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA26B_004AA26F[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA270; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA271; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA272; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA273; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA274; /* native-read BE16 command parameter 0x94 */
    u8 body_opcode_01_skipped_payload_004AA275[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA278_004AA279[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA27A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA27B_004AA280[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA281; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA282_004AA285[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA286; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA287_004AA28B[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA28C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA28D_004AA28E[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA28F; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA290; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA291; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA292; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA293; /* native-read BE16 command parameter 0x9F */
    u8 body_opcode_01_skipped_payload_004AA294[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA297_004AA29C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA29D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA29E_004AA2A1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2A2; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2A3_004AA2A6[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2A7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2A8_004AA2A9[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2AA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2AB_004AA2AC[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA2AD; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA2AE; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA2AF; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA2B0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA2B1; /* native-read BE16 command parameter 0x88 */
    u8 body_opcode_01_skipped_payload_004AA2B2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA2B5_004AA2B9[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2BA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2BB_004AA2BF[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2C0; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2C1_004AA2C2[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2C3; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2C4_004AA2C7[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2C8; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2C9_004AA2CD[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA2CE; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA2CF; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA2D0; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA2D1; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA2D2; /* native-read BE16 command parameter 0x87 */
    u8 body_opcode_01_skipped_payload_004AA2D3[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA2D6_004AA2D7[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2D8; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2D9_004AA2E0[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2E1; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2E2_004AA2E3[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2E4; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2E5_004AA2E9[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2EA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2EB_004AA2EE[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA2EF; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA2F0; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA2F1; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA2F2; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA2F3; /* native-read BE16 command parameter 0xB3 */
    u8 body_opcode_01_skipped_payload_004AA2F4[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA2F7_004AA2F9[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA2FA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA2FB_004AA2FF[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA300; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA301_004AA303[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA304; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA305_004AA309[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA30A; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA30B; /* native-read command operand 0x18 */
    u8 body_opcode_01_004AA30C; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA30D; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA30E; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_skipped_payload_004AA30F[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA312_004AA314[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004AA315; /* native body command opcode 0x05 */
    u8 body_opcode_05_004AA316; /* native body command opcode 0x05 */
    u8 body_glyph_native_codes_004AA317_004AA318[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA319; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA240;
EffectTimelineStream_004AA240 data_effect_timeline_stream_004AA240 = {
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
    0x60,
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
    0x94,
    { 0x00, 0x60, 0x80 },
    { 0x42, 0x41 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x29, 0x2C, 0x12, 0x94 },
    0x0D,
    { 0x3C, 0x41 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x60, 0x80 },
    { 0x26, 0x1E, 0x26, 0x28, 0x2B, 0x32 },
    0x0D,
    { 0x1C, 0x1A, 0x2B, 0x1D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47 },
    0x0D,
    { 0x19, 0x8E },
    0x0D,
    { 0x1A, 0x47 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x88,
    { 0x00, 0x60, 0x80 },
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x11, 0x11, 0x19, 0x24, 0x1B },
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
    { 0x00, 0x60, 0x80 },
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
    0xB3,
    { 0x00, 0x60, 0x80 },
    { 0x4C, 0x42, 0x48 },
    0x0D,
    { 0x46, 0x47, 0x34, 0x45, 0x47 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x3A, 0x34, 0x40, 0x38, 0x8F },
    0x04,
    0x18,
    0x01,
    0x01,
    0x00,
    { 0x00, 0x60, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
