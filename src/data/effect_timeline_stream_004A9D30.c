/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9D30; /* native record count 0x01 */
    u8 record_base_004A9D31; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9D32; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9D33; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9D34; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9D35[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9D37; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9D38; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9D39; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A9D3A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A9D3B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A9D3C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A9D3D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A9D3E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A9D3F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9D40; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9D41; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9D42; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9D43; /* natively read BE16 header A byte 0xA3 */
    u8 preamble_header_B_be16_byte_0_004A9D44; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9D45; /* natively read BE16 header B byte 0x78 */
    u8 preamble_header_u8_004A9D46; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9D47_004A9D4C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D4D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D4E_004A9D4F[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D50; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D51_004A9D56[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D57; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D58_004A9D5B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9D5C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9D5D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9D5E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9D5F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9D60; /* natively read BE16 command parameter byte 0x7B */
    u8 body_opcode_01_skipped_operand_004A9D61[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9D64_004A9D68[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D69; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D6A_004A9D6F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D70; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D71_004A9D71[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D72; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D73_004A9D78[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D79; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D7A_004A9D7D[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9D7E; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9D7F; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9D80; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9D81; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9D82; /* natively read BE16 command parameter byte 0x84 */
    u8 body_opcode_01_skipped_operand_004A9D83[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9D86_004A9D8A[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D8B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D8C_004A9D8F[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D90; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D91_004A9D92[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D93; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D94_004A9D98[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9D99; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9D9A_004A9D9E[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9D9F; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9DA0; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9DA1; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9DA2; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9DA3; /* natively read BE16 command parameter byte 0x88 */
    u8 body_opcode_01_skipped_operand_004A9DA4[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9DA7_004A9DA8[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DA9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DAA_004A9DAD[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DAE; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DAF_004A9DB3[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DB4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DB5_004A9DB6[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DB7; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DB8_004A9DBF[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9DC0; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9DC1; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9DC2; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9DC3; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9DC4; /* natively read BE16 command parameter byte 0x97 */
    u8 body_opcode_01_skipped_operand_004A9DC5[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9DC8_004A9DC9[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DCA; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DCB_004A9DCF[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DD0; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DD1_004A9DD4[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DD5; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DD6_004A9DD8[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DD9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DDA_004A9DDE[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9DDF; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9DE0; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9DE1; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9DE2; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9DE3; /* natively read BE16 command parameter byte 0xCB */
    u8 body_opcode_01_skipped_operand_004A9DE4[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9DE7_004A9DED[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9DEE; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9DEF_004A9DF5[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9DF6; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9DF7; /* natively read command operand 0x18 */
    u8 body_opcode_01_004A9DF8; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9DF9; /* natively read BE16 command parameter byte 0x01 */
    u8 body_opcode_01_be16_byte_1_004A9DFA; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_skipped_operand_004A9DFB[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9DFE_004A9E00[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004A9E01; /* native body control/command opcode 0x05 */
    u8 body_opcode_05_004A9E02; /* native body control/command opcode 0x05 */
    u8 body_glyph_native_codes_004A9E03_004A9E04[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9E05; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9D30;
EffectTimelineStream_004A9D30 data_effect_timeline_stream_004A9D30 = {
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
    0x84,
    { 0x00, 0x78, 0x80 },
    { 0x93, 0x29, 0x2C, 0x12, 0x94 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B },
    0x0D,
    { 0x34, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x11, 0x11, 0x19, 0x24, 0x1B },
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
