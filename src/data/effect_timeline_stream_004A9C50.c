/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9C50; /* native record count 0x01 */
    u8 record_base_004A9C51; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9C52; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9C53; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9C54; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9C55[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9C57; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9C58; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9C59; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9C5A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9C5B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9C5C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9C5D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9C5E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9C5F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9C60; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9C61; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9C62; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9C63; /* natively read BE16 header A byte 0xA3 */
    u8 preamble_header_B_be16_byte_0_004A9C64; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9C65; /* natively read BE16 header B byte 0x78 */
    u8 preamble_header_u8_004A9C66; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9C67_004A9C6C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C6D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C6E_004A9C6F[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C70; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C71_004A9C76[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C77; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C78_004A9C7B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9C7C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9C7D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9C7E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9C7F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9C80; /* natively read BE16 command parameter byte 0x7B */
    u8 body_opcode_01_skipped_operand_004A9C81[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9C84_004A9C88[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C89; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C8A_004A9C8F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C90; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C91_004A9C91[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C92; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C93_004A9C98[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9C99; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9C9A_004A9C9D[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9C9E; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9C9F; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9CA0; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9CA1; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9CA2; /* natively read BE16 command parameter byte 0x8C */
    u8 body_opcode_01_skipped_operand_004A9CA3[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9CA6_004A9CAA[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CAB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CAC_004A9CAF[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CB0; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CB1_004A9CB2[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CB3; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CB4_004A9CB8[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CB9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CBA_004A9CBD[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9CBE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9CBF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9CC0; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9CC1; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9CC2; /* natively read BE16 command parameter byte 0x88 */
    u8 body_opcode_01_skipped_operand_004A9CC3[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9CC6_004A9CC7[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CC8; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CC9_004A9CCC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CCD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CCE_004A9CD2[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CD3; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CD4_004A9CD5[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CD6; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CD7_004A9CDE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9CDF; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9CE0; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9CE1; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9CE2; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9CE3; /* natively read BE16 command parameter byte 0x97 */
    u8 body_opcode_01_skipped_operand_004A9CE4[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9CE7_004A9CE8[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CE9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CEA_004A9CEE[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CEF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CF0_004A9CF3[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CF4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CF5_004A9CF7[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9CF8; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9CF9_004A9CFD[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9CFE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9CFF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9D00; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9D01; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9D02; /* natively read BE16 command parameter byte 0xCB */
    u8 body_opcode_01_skipped_operand_004A9D03[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9D06_004A9D0C[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D0D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D0E_004A9D14[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9D15; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9D16; /* natively read command operand 0x18 */
    u8 body_opcode_01_004A9D17; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9D18; /* natively read BE16 command parameter byte 0x01 */
    u8 body_opcode_01_be16_byte_1_004A9D19; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_skipped_operand_004A9D1A[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9D1D_004A9D1F[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004A9D20; /* native body control/command opcode 0x05 */
    u8 body_opcode_05_004A9D21; /* native body control/command opcode 0x05 */
    u8 body_glyph_native_codes_004A9D22_004A9D23[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9D24; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9C50;
EffectTimelineStream_004A9C50 data_effect_timeline_stream_004A9C50 = {
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
    0x78,
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
    0x7B,
    { 0x00, 0x78, 0x80 },
    { 0x93, 0x29, 0x2C, 0x12, 0x94 },
    0x0D,
    { 0x39, 0x42, 0x48, 0x41, 0x37, 0x8E },
    0x0D,
    { 0x1A },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x8C,
    { 0x00, 0x78, 0x80 },
    { 0x93, 0x29, 0x2C, 0x12, 0x94 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B },
    0x0D,
    { 0x34, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x15, 0x17, 0x24, 0x1B },
    0x04,
    0x00,
    0x01,
    0x00,
    0x88,
    { 0x00, 0x78, 0x80 },
    { 0x42, 0x39 },
    0x0D,
    { 0x39, 0x45, 0x38, 0x38 },
    0x0D,
    { 0x46, 0x43, 0x34, 0x36, 0x38 },
    0x0D,
    { 0x3C, 0x46 },
    0x0D,
    { 0x45, 0x38, 0x44, 0x48, 0x3C, 0x45, 0x38, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x97,
    { 0x00, 0x78, 0x80 },
    { 0x47, 0x42 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x8E },
    0x0D,
    { 0x30, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x4C, 0x42, 0x48 },
    0x0D,
    { 0x46, 0x47, 0x34, 0x45, 0x47 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xCB,
    { 0x00, 0x78, 0x80 },
    { 0x4A, 0x3C, 0x47, 0x3B, 0x42, 0x48, 0x47 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x3C, 0x41, 0x3A, 0x8F },
    0x04,
    0x18,
    0x01,
    0x01,
    0x00,
    { 0x00, 0x78, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
