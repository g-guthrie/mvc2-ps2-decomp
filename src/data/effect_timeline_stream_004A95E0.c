/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A95E0; /* native record count 0x01 */
    u8 record_base_004A95E1; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A95E2; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A95E3; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A95E4; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A95E5[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A95E7; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A95E8; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A95E9; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A95EA; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A95EB; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A95EC; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A95ED; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A95EE; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A95EF; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A95F0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A95F1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A95F2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A95F3; /* natively read BE16 header A byte 0x87 */
    u8 preamble_header_B_be16_byte_0_004A95F4; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A95F5; /* natively read BE16 header B byte 0x98 */
    u8 preamble_header_u8_004A95F6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A95F7_004A95FE[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A95FF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9600_004A9609[10]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A960A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A960B_004A960E[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A960F; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9610; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9611; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9612; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9613; /* natively read BE16 command parameter byte 0x94 */
    u8 body_opcode_01_skipped_operand_004A9614[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9617_004A9618[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9619; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A961A_004A961F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9620; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9621_004A9624[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9625; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9626_004A962A[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A962B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A962C_004A962D[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A962E; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A962F; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9630; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9631; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9632; /* natively read BE16 command parameter byte 0x9F */
    u8 body_opcode_01_skipped_operand_004A9633[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9636_004A963B[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A963C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A963D_004A9640[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9641; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9642_004A9645[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9646; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9647_004A9648[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9649; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A964A_004A964B[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A964C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A964D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A964E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A964F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9650; /* natively read BE16 command parameter byte 0x80 */
    u8 body_opcode_01_skipped_operand_004A9651[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9654_004A9656[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9657; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9658_004A965D[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A965E; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A965F_004A9661[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9662; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9663_004A9668[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9669; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A966A_004A966D[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A966E; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A966F; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9670; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9671; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9672; /* natively read BE16 command parameter byte 0x8E */
    u8 body_opcode_01_skipped_operand_004A9673[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9676_004A967B[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A967C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A967D_004A9682[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9683; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9684_004A9685[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9686; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9687_004A968C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A968D; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A968E; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A968F; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9690; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9691; /* natively read BE16 command parameter byte 0xC7 */
    u8 body_opcode_01_skipped_operand_004A9692[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9695_004A9697[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9698; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9699_004A969B[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A969C; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A969D_004A96A4[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A96A5; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A95E0;
EffectTimelineStream_004A95E0 data_effect_timeline_stream_004A95E0 = {
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
    0x87,
    0x00,
    0x98,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1A, 0x48, 0x47, 0x42, 0x46, 0x34, 0x49, 0x3C, 0x41, 0x3A },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x94,
    { 0x00, 0x98, 0x80 },
    { 0x47, 0x42 },
    0x0D,
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
    0x9F,
    { 0x00, 0x98, 0x80 },
    { 0x26, 0x1E, 0x26, 0x28, 0x2B, 0x32 },
    0x0D,
    { 0x1C, 0x1A, 0x2B, 0x1D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47 },
    0x0D,
    { 0x19, 0x96 },
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
    0x8E,
    { 0x00, 0x98, 0x80 },
    { 0x93, 0x29, 0x2C, 0x12, 0x94, 0x95 },
    0x0D,
    { 0x45, 0x38, 0x46, 0x38, 0x47, 0x95 },
    0x0D,
    { 0x42, 0x45 },
    0x0D,
    { 0x46, 0x4A, 0x3C, 0x47, 0x36, 0x3B },
    0x04,
    0x00,
    0x01,
    0x00,
    0xC7,
    { 0x00, 0x98, 0x80 },
    { 0x42, 0x39, 0x39 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x36, 0x42, 0x41, 0x46, 0x42, 0x3F, 0x38, 0x8E },
    0x00,
};
