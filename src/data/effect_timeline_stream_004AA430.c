/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA430; /* native record count 0x01 */
    u8 record_base_004AA431; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA432; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA433; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA434; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA435[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA437; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA438; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA439; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA43A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA43B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA43C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA43D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA43E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA43F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA440; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA441; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA442; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA443; /* native-read BE16 header A 0x8E */
    u8 preamble_header_B_be16_byte_0_004AA444; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA445; /* native-read BE16 header B 0x98 */
    u8 preamble_header_u8_004AA446; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA447_004AA44E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA44F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA450_004AA45A[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA45B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA45C_004AA45D[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA45E; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA45F; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA460; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA461; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA462; /* native-read BE16 command parameter 0x80 */
    u8 body_opcode_01_skipped_payload_004AA463[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA466_004AA468[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA469; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA46A_004AA46F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA470; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA471_004AA473[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA474; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA475_004AA47A[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA47B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA47C_004AA47F[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA480; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA481; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA482; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA483; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA484; /* native-read BE16 command parameter 0x59 */
    u8 body_opcode_01_skipped_payload_004AA485[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA488_004AA490[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA491; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA492_004AA4A0[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA4A1; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA4A2; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA4A3; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA4A4; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA4A5; /* native-read BE16 command parameter 0x8F */
    u8 body_opcode_01_skipped_payload_004AA4A6[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA4A9_004AA4AE[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA4AF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA4B0_004AA4B1[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA4B2; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA4B3_004AA4B8[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA4B9; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA4BA_004AA4BC[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA4BD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA4BE_004AA4C0[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA4C1; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA4C2; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA4C3; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA4C4; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA4C5; /* native-read BE16 command parameter 0xFF */
    u8 body_opcode_01_skipped_payload_004AA4C6[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA4C9_004AA4D0[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA4D1; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA430;
EffectTimelineStream_004AA430 data_effect_timeline_stream_004AA430 = {
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
    0x8E,
    0x00,
    0x98,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1F, 0x42, 0x45, 0x40, 0x34, 0x47, 0x47, 0x3C, 0x41, 0x3A, 0x96 },
    0x0D,
    { 0x1D, 0x42 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x80,
    { 0x00, 0x98, 0x80 },
    { 0x41, 0x42, 0x47 },
    0x0D,
    { 0x45, 0x38, 0x40, 0x42, 0x49, 0x38 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x59,
    { 0x00, 0x98, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x95 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x8F,
    { 0x00, 0x98, 0x80 },
    { 0x45, 0x38, 0x46, 0x38, 0x47, 0x95 },
    0x0D,
    { 0x42, 0x45 },
    0x0D,
    { 0x46, 0x4A, 0x3C, 0x47, 0x36, 0x3B },
    0x0D,
    { 0x42, 0x39, 0x39 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xFF,
    { 0x00, 0x98, 0x80 },
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
