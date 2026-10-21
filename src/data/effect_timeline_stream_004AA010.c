/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA010; /* native record count 0x01 */
    u8 record_base_004AA011; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA012; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA013; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA014; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA015[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA017; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA018; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA019; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA01A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA01B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA01C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA01D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA01E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA01F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA020; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA021; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA022; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA023; /* native-read BE16 header A 0x87 */
    u8 preamble_header_B_be16_byte_0_004AA024; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA025; /* native-read BE16 header B 0x80 */
    u8 preamble_header_u8_004AA026; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA027_004AA02C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA02D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA02E_004AA033[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA034; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA035_004AA038[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA039; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA03A_004AA03E[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA03F; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA040; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA041; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA042; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA043; /* native-read BE16 command parameter 0x7A */
    u8 body_opcode_01_skipped_payload_004AA044[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA047_004AA04A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA04B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA04C_004AA059[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA05A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA05B_004AA05C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA05D; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA05E; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA05F; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA060; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA061; /* native-read BE16 command parameter 0x9F */
    u8 body_opcode_01_skipped_payload_004AA062[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA065_004AA070[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA071; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA072_004AA075[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA076; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA077_004AA079[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA07A; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA07B; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA07C; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA07D; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA07E; /* native-read BE16 command parameter 0xF3 */
    u8 body_opcode_01_skipped_payload_004AA07F[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA082_004AA087[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA088; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA089_004AA08B[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA08C; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA08D; /* native-read command operand 0x18 */
    u8 body_opcode_01_004AA08E; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA08F; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA090; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_skipped_payload_004AA091[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA094_004AA096[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004AA097; /* native body command opcode 0x05 */
    u8 body_opcode_05_004AA098; /* native body command opcode 0x05 */
    u8 body_glyph_native_codes_004AA099_004AA09A[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA09B; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA010;
EffectTimelineStream_004AA010 data_effect_timeline_stream_004AA010 = {
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
    0x87,
    0x00,
    0x80,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x26, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x18, 0x26, 0x1B, 0x94 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7A,
    { 0x00, 0x80, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x3C, 0x46 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x80, 0x80 },
    { 0x48, 0x41, 0x39, 0x42, 0x45, 0x40, 0x34, 0x47, 0x47, 0x38, 0x37, 0x8E },
    0x0D,
    { 0x30, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x4C, 0x42, 0x48 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xF3,
    { 0x00, 0x80, 0x80 },
    { 0x39, 0x42, 0x45, 0x40, 0x34, 0x47 },
    0x0D,
    { 0x3C, 0x47, 0x8F },
    0x04,
    0x18,
    0x01,
    0x01,
    0x00,
    { 0x00, 0x80, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
