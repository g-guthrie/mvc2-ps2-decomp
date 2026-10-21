/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA160; /* native record count 0x01 */
    u8 record_base_004AA161; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA162; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA163; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA164; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA165[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA167; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA168; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA169; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA16A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA16B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA16C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA16D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA16E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA16F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA170; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA171; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA172; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA173; /* native-read BE16 header A 0x7F */
    u8 preamble_header_B_be16_byte_0_004AA174; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA175; /* native-read BE16 header B 0x60 */
    u8 preamble_header_u8_004AA176; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA177_004AA17C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA17D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA17E_004AA189[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA18A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA18B_004AA18F[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA190; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA191; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA192; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA193; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA194; /* native-read BE16 command parameter 0x94 */
    u8 body_opcode_01_skipped_payload_004AA195[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA198_004AA199[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA19A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA19B_004AA1A0[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1A1; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1A2_004AA1A5[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1A6; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1A7_004AA1AB[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1AC; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1AD_004AA1AE[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA1AF; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA1B0; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA1B1; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA1B2; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA1B3; /* native-read BE16 command parameter 0x9F */
    u8 body_opcode_01_skipped_payload_004AA1B4[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA1B7_004AA1BC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1BD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1BE_004AA1C1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1C2; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1C3_004AA1C6[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1C7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1C8_004AA1C9[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1CA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1CB_004AA1CC[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA1CD; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA1CE; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA1CF; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA1D0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA1D1; /* native-read BE16 command parameter 0x90 */
    u8 body_opcode_01_skipped_payload_004AA1D2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA1D5_004AA1D9[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1DA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1DB_004AA1DE[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1DF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1E0_004AA1E1[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1E2; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1E3_004AA1E6[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1E7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1E8_004AA1EC[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA1ED; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA1EE; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA1EF; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA1F0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA1F1; /* native-read BE16 command parameter 0x87 */
    u8 body_opcode_01_skipped_payload_004AA1F2[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA1F5_004AA1F6[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA1F7; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA1F8_004AA1FF[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA200; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA201_004AA202[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA203; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA204_004AA208[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA209; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA20A_004AA20D[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA20E; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA20F; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA210; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA211; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA212; /* native-read BE16 command parameter 0xB3 */
    u8 body_opcode_01_skipped_payload_004AA213[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA216_004AA218[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA219; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA21A_004AA21E[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA21F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA220_004AA222[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA223; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA224_004AA228[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA229; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA22A; /* native-read command operand 0x18 */
    u8 body_opcode_01_004AA22B; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA22C; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA22D; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_skipped_payload_004AA22E[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA231_004AA233[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004AA234; /* native body command opcode 0x05 */
    u8 body_opcode_05_004AA235; /* native body command opcode 0x05 */
    u8 body_glyph_native_codes_004AA236_004AA237[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA238; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA160;
EffectTimelineStream_004AA160 data_effect_timeline_stream_004AA160 = {
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
    0x90,
    { 0x00, 0x60, 0x80 },
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
