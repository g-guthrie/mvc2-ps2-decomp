/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9BA0; /* native record count 0x01 */
    u8 record_base_004A9BA1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9BA2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9BA3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9BA4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9BA5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9BA7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9BA8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9BA9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9BAA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9BAB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9BAC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9BAD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9BAE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9BAF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9BB0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9BB1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9BB2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9BB3; /* natively read BE16 header A byte 0x8B */
    u8 preamble_header_B_be16_byte_0_004A9BB4; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9BB5; /* natively read BE16 header B byte 0x7C */
    u8 preamble_header_u8_004A9BB6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9BB7_004A9BBC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BBD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BBE_004A9BC1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BC2; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BC3_004A9BCA[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BCB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BCC_004A9BCE[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9BCF; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9BD0; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9BD1; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9BD2; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9BD3; /* natively read BE16 command parameter byte 0xBF */
    u8 body_opcode_01_skipped_operand_004A9BD4[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9BD7_004A9BDD[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BDE; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BDF_004A9BE3[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BE4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BE5_004A9BE7[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9BE8; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9BE9; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9BEA; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9BEB; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9BEC; /* natively read BE16 command parameter byte 0x84 */
    u8 body_opcode_01_skipped_operand_004A9BED[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9BF0_004A9BF9[10]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BFA; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BFB_004A9BFC[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9BFD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9BFE_004A9C01[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C02; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C03_004A9C08[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9C09; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9C0A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9C0B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9C0C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9C0D; /* natively read BE16 command parameter byte 0xA3 */
    u8 body_opcode_01_skipped_operand_004A9C0E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9C11_004A9C15[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C16; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C17_004A9C1B[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C1C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C1D_004A9C1F[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C20; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C21_004A9C25[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9C26; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9C27; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9C28; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9C29; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9C2A; /* natively read BE16 command parameter byte 0xAB */
    u8 body_opcode_01_skipped_operand_004A9C2B[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9C2E_004A9C33[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C34; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C35_004A9C36[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C37; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C38_004A9C3A[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C3B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C3C_004A9C41[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9C42; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9BA0;
EffectTimelineStream_004A9BA0 data_effect_timeline_stream_004A9BA0 = {
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
    0x8B,
    0x00,
    0x7C,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x1F, 0x3C, 0x3F, 0x38 },
    0x0D,
    { 0x36, 0x45, 0x38, 0x34, 0x47, 0x3C, 0x42, 0x41 },
    0x0D,
    { 0x3B, 0x34, 0x46 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xBF,
    { 0x00, 0x7C, 0x80 },
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x9B },
    0x0D,
    { 0x1C, 0x3B, 0x38, 0x36, 0x3E },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x84,
    { 0x00, 0x7C, 0x80 },
    { 0x36, 0x42, 0x41, 0x41, 0x38, 0x36, 0x47, 0x3C, 0x42, 0x41 },
    0x0D,
    { 0x42, 0x39 },
    0x0D,
    { 0x4C, 0x42, 0x48, 0x45 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA3,
    { 0x00, 0x7C, 0x80 },
    { 0x36, 0x34, 0x45, 0x37, 0x8E },
    0x0D,
    { 0x29, 0x45, 0x38, 0x46, 0x46 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x2C, 0x2D, 0x1A, 0x2B, 0x2D },
    0x04,
    0x00,
    0x01,
    0x00,
    0xAB,
    { 0x00, 0x7C, 0x80 },
    { 0x35, 0x48, 0x47, 0x47, 0x42, 0x41 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x47, 0x45, 0x4C },
    0x0D,
    { 0x34, 0x3A, 0x34, 0x3C, 0x41, 0x8E },
    0x00,
};
