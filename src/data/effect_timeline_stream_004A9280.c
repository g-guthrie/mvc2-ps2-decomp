/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9280; /* native record count 0x01 */
    u8 record_base_004A9281; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9282; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9283; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9284; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9285[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9287; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9288; /* natively read command operand 0x00 */
    u8 preamble_opcode_06_004A9289; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A928A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A928B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A928C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A928D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A928E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A928F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9290; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9291; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9292; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9293; /* natively read BE16 header A byte 0x8E */
    u8 preamble_header_B_be16_byte_0_004A9294; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9295; /* natively read BE16 header B byte 0x34 */
    u8 preamble_header_u8_004A9296; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9297_004A929E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A929F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92A0_004A92AA[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92AB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92AC_004A92AD[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A92AE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A92AF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A92B0; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A92B1; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A92B2; /* natively read BE16 command parameter byte 0x80 */
    u8 body_opcode_01_skipped_operand_004A92B3[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A92B6_004A92B8[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92B9; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92BA_004A92BF[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92C0; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92C1_004A92C3[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92C4; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92C5_004A92CA[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92CB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92CC_004A92CF[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A92D0; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A92D1; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A92D2; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A92D3; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A92D4; /* natively read BE16 command parameter byte 0x59 */
    u8 body_opcode_01_skipped_operand_004A92D5[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A92D8_004A92E0[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92E1; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A92E2_004A92F0[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A92F1; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A92F2; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A92F3; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A92F4; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A92F5; /* natively read BE16 command parameter byte 0x8F */
    u8 body_opcode_01_skipped_operand_004A92F6[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A92F9_004A92FE[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A92FF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9300_004A9301[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9302; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9303_004A9308[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9309; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A930A_004A930C[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A930D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A930E_004A9310[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9311; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9312; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9313; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9314; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9315; /* natively read BE16 command parameter byte 0xFF */
    u8 body_opcode_01_skipped_operand_004A9316[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9319_004A9320[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9321; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9280;
EffectTimelineStream_004A9280 data_effect_timeline_stream_004A9280 = {
    0x01,
    0x00,
    0x0B,
    0x00,
    0x0C,
    { 0x00, 0x00 },
    0x05,
    0x00,
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
    0x01,
    0x34,
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
    { 0x01, 0x34, 0x80 },
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
    { 0x01, 0x34, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x95 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x8F,
    { 0x01, 0x34, 0x80 },
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
    { 0x01, 0x34, 0x80 },
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
