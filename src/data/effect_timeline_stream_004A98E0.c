/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A98E0; /* native record count 0x01 */
    u8 record_base_004A98E1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A98E2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A98E3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A98E4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A98E5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A98E7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A98E8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A98E9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A98EA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A98EB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A98EC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A98ED; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A98EE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A98EF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A98F0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A98F1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A98F2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A98F3; /* natively read BE16 header A byte 0xA3 */
    u8 preamble_header_B_be16_byte_0_004A98F4; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A98F5; /* natively read BE16 header B byte 0x98 */
    u8 preamble_header_u8_004A98F6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A98F7_004A98FE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A98FF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9900_004A990A[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A990B; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A990C; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A990D; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A990E; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A990F; /* natively read BE16 command parameter byte 0x9C */
    u8 body_opcode_01_skipped_operand_004A9910[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9913_004A991B[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A991C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A991D_004A9920[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9921; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9922_004A9925[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9926; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9927_004A9928[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9929; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A992A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A992B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A992C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A992D; /* natively read BE16 command parameter byte 0x7C */
    u8 body_opcode_01_skipped_operand_004A992E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9931_004A9935[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9936; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9937_004A9938[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9939; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A993A_004A993F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9940; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9941_004A9944[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9945; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9946_004A994A[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A994B; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A994C; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A994D; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A994E; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A994F; /* natively read BE16 command parameter byte 0x7A */
    u8 body_opcode_01_skipped_operand_004A9950[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9953_004A9956[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9957; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9958_004A9965[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9966; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9967_004A9968[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9969; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A996A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A996B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A996C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A996D; /* natively read BE16 command parameter byte 0x9F */
    u8 body_opcode_01_skipped_operand_004A996E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9971_004A9976[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9977; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9978_004A997B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A997C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A997D_004A9980[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9981; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9982_004A9983[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9984; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A98E0;
EffectTimelineStream_004A98E0 data_effect_timeline_stream_004A98E0 = {
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
    0x98,
    0x80,
    { 0x1A, 0x48, 0x47, 0x42, 0x3F, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x46, 0x48, 0x36, 0x36, 0x38, 0x46, 0x46, 0x39, 0x48, 0x3F, 0x8E },
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
