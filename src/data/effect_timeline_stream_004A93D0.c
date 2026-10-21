/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A93D0; /* native record count 0x01 */
    u8 record_base_004A93D1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A93D2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A93D3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A93D4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A93D5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A93D7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A93D8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A93D9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A93DA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A93DB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A93DC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A93DD; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A93DE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A93DF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A93E0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A93E1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A93E2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A93E3; /* natively read BE16 header A byte 0x92 */
    u8 preamble_header_B_be16_byte_0_004A93E4; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A93E5; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A93E6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A93E7_004A93EE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A93EF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A93F0_004A93F6[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A93F7; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A93F8_004A93F9[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A93FA; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A93FB_004A93FD[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A93FE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A93FF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9400; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9401; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9402; /* natively read BE16 command parameter byte 0x9C */
    u8 body_opcode_01_skipped_operand_004A9403[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9406_004A940B[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A940C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A940D_004A940F[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9410; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9411_004A9416[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9417; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9418_004A941B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A941C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A941D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A941E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A941F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9420; /* natively read BE16 command parameter byte 0x59 */
    u8 body_opcode_01_skipped_operand_004A9421[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9424_004A942C[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A942D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A942E_004A943C[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A943D; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A943E; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A943F; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9440; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9441; /* natively read BE16 command parameter byte 0x4A */
    u8 body_opcode_01_skipped_operand_004A9442[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9445_004A944A[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A944B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A944C_004A944D[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A944E; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A944F_004A9454[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9455; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9456_004A9458[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9459; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A945A_004A945C[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A945D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A945E_004A9465[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9466; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A93D0;
EffectTimelineStream_004A93D0 data_effect_timeline_stream_004A93D0 = {
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
    0x92,
    0x01,
    0x44,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x2C, 0x34, 0x49, 0x3C, 0x41, 0x3A, 0x96 },
    0x0D,
    { 0x1D, 0x42 },
    0x0D,
    { 0x41, 0x42, 0x47 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9C,
    { 0x01, 0x44, 0x80 },
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
    { 0x01, 0x44, 0x80 },
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x95 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x4A,
    { 0x01, 0x44, 0x80 },
    { 0x45, 0x38, 0x46, 0x38, 0x47, 0x95 },
    0x0D,
    { 0x42, 0x45 },
    0x0D,
    { 0x46, 0x4A, 0x3C, 0x47, 0x36, 0x3B },
    0x0D,
    { 0x42, 0x39, 0x39 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
