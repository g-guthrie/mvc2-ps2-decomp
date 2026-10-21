/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9750; /* native record count 0x01 */
    u8 record_base_004A9751; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9752; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9753; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9754; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9755[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9757; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9758; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9759; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A975A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A975B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A975C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A975D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A975E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A975F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9760; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9761; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9762; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9763; /* natively read BE16 header A byte 0x7B */
    u8 preamble_header_B_be16_byte_0_004A9764; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9765; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9766; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9767_004A976A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A976B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A976C_004A9776[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9777; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9778_004A977B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A977C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A977D_004A9780[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9781; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9782; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9783; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9784; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9785; /* natively read BE16 command parameter byte 0x98 */
    u8 body_opcode_01_skipped_operand_004A9786[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9789_004A978A[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A978B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A978C_004A9790[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9791; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9792_004A9793[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9794; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9795_004A979A[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A979B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A979C_004A979F[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A97A0; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A97A1; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A97A2; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A97A3; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A97A4; /* natively read BE16 command parameter byte 0x5E */
    u8 body_opcode_01_skipped_operand_004A97A5[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A97A8_004A97B0[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97B1; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A97B2_004A97BF[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97C0; /* native body control/command opcode 0x0D */
    u8 body_opcode_04_004A97C1; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A97C2; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A97C3; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A97C4; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A97C5; /* natively read BE16 command parameter byte 0x8F */
    u8 body_opcode_01_skipped_operand_004A97C6[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A97C9_004A97CA[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97CB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A97CC_004A97D1[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97D2; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A97D3_004A97D6[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A97D7; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A97D8_004A97DD[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A97DE; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9750;
EffectTimelineStream_004A9750 data_effect_timeline_stream_004A9750 = {
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
    0x7B,
    0x01,
    0x44,
    0x80,
    { 0x25, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x46, 0x48, 0x36, 0x36, 0x38, 0x46, 0x46, 0x39, 0x48, 0x3F, 0x8E },
    0x0D,
    { 0x1D, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x4A, 0x3C, 0x3F, 0x3F },
    0x04,
    0x00,
    0x01,
    0x00,
    0x98,
    { 0x01, 0x44, 0x80 },
    { 0x35, 0x38 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x5E,
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    0x04,
    0x00,
    0x01,
    0x00,
    0x8F,
    { 0x01, 0x44, 0x80 },
    { 0x3C, 0x41 },
    0x0D,
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 },
    0x0D,
    { 0x5C, 0x5A, 0x6B, 0x5D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47, 0x10, 0x8E },
    0x00,
};
