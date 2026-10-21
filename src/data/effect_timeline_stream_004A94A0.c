/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A94A0; /* native record count 0x01 */
    u8 record_base_004A94A1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A94A2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A94A3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A94A4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A94A5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A94A7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A94A8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A94A9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A94AA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A94AB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A94AC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A94AD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A94AE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A94AF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A94B0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A94B1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A94B2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A94B3; /* natively read BE16 header A byte 0x77 */
    u8 preamble_header_B_be16_byte_0_004A94B4; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A94B5; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A94B6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A94B7_004A94BA[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94BB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94BC_004A94C6[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94C7; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94C8_004A94D0[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A94D1; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A94D2; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A94D3; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A94D4; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A94D5; /* natively read BE16 command parameter byte 0xA8 */
    u8 body_opcode_01_skipped_operand_004A94D6[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A94D9_004A94DC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94DD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94DE_004A94E1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94E2; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94E3_004A94E4[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94E5; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94E6_004A94EA[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94EB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94EC_004A94ED[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A94EE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A94EF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A94F0; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A94F1; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A94F2; /* natively read BE16 command parameter byte 0xA8 */
    u8 body_opcode_01_skipped_operand_004A94F3[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A94F6_004A94FB[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A94FC; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A94FD_004A9500[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9501; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9502_004A9506[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9507; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9508_004A9509[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A950A; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A950B; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A950C; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A950D; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A950E; /* natively read BE16 command parameter byte 0xA3 */
    u8 body_opcode_01_skipped_operand_004A950F[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9512_004A9517[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9518; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9519_004A951C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A951D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A951E_004A9523[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9524; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A94A0;
EffectTimelineStream_004A94A0 data_effect_timeline_stream_004A94A0 = {
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
    0x01,
    0x44,
    0x80,
    { 0x2C, 0x34, 0x49, 0x38 },
    0x0D,
    { 0x46, 0x48, 0x36, 0x36, 0x38, 0x46, 0x46, 0x39, 0x48, 0x3F, 0x8E },
    0x0D,
    { 0x1A, 0x48, 0x47, 0x42, 0x46, 0x34, 0x49, 0x38, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA8,
    { 0x01, 0x44, 0x80 },
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x4A, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x35, 0x38 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA8,
    { 0x01, 0x44, 0x80 },
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
    0xA3,
    { 0x01, 0x44, 0x80 },
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 },
    0x0D,
    { 0x5C, 0x5A, 0x6B, 0x5D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47, 0x19, 0x8E },
    0x00,
};
