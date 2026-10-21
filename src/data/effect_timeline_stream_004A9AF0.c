/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9AF0; /* native record count 0x01 */
    u8 record_base_004A9AF1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9AF2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9AF3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9AF4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9AF5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9AF7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9AF8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9AF9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9AFA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9AFB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9AFC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9AFD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9AFE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9AFF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9B00; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9B01; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9B02; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9B03; /* natively read BE16 header A byte 0x8F */
    u8 preamble_header_B_be16_byte_0_004A9B04; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9B05; /* natively read BE16 header B byte 0x98 */
    u8 preamble_header_u8_004A9B06; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9B07_004A9B07[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B08; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B09_004A9B0C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B0D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B0E_004A9B10[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B11; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B12_004A9B15[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B16; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B17_004A9B1E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9B1F; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9B20; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9B21; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9B22; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9B23; /* natively read BE16 command parameter byte 0x9C */
    u8 body_opcode_01_skipped_operand_004A9B24[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9B27_004A9B2F[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B30; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B31_004A9B34[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B35; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B36_004A9B39[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B3A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B3B_004A9B3C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9B3D; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9B3E; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9B3F; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9B40; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9B41; /* natively read BE16 command parameter byte 0x7C */
    u8 body_opcode_01_skipped_operand_004A9B42[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9B45_004A9B49[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B4A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B4B_004A9B4C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B4D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B4E_004A9B53[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B54; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B55_004A9B58[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B59; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B5A_004A9B5E[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9B5F; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9B60; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9B61; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9B62; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9B63; /* natively read BE16 command parameter byte 0x7A */
    u8 body_opcode_01_skipped_operand_004A9B64[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9B67_004A9B6A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B6B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B6C_004A9B79[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B7A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B7B_004A9B7C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9B7D; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9B7E; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9B7F; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9B80; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9B81; /* natively read BE16 command parameter byte 0x9F */
    u8 body_opcode_01_skipped_operand_004A9B82[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9B85_004A9B8A[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B8B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B8C_004A9B8F[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B90; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B91_004A9B94[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9B95; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9B96_004A9B97[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9B98; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9AF0;
EffectTimelineStream_004A9AF0 data_effect_timeline_stream_004A9AF0 = {
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
    0x8F,
    0x00,
    0x98,
    0x80,
    { 0x1A },
    0x0D,
    { 0x39, 0x3C, 0x3F, 0x38 },
    0x0D,
    { 0x3B, 0x34, 0x46 },
    0x0D,
    { 0x35, 0x38, 0x38, 0x41 },
    0x0D,
    { 0x36, 0x45, 0x38, 0x34, 0x47, 0x38, 0x37, 0x8E },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9C,
    { 0x00, 0x98, 0x80 },
    { 0x1A, 0x48, 0x47, 0x42, 0x46, 0x34, 0x49, 0x38, 0x37 },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x4A, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x35, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7C,
    { 0x00, 0x98, 0x80 },
    { 0x46, 0x34, 0x49, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
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
    0x7A,
    { 0x00, 0x98, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x3C, 0x41 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x98, 0x80 },
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 },
    0x0D,
    { 0x5C, 0x5A, 0x6B, 0x5D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47 },
    0x0D,
    { 0x19, 0x8E },
    0x00,
};
