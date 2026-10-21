/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9530; /* native record count 0x01 */
    u8 record_base_004A9531; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9532; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9533; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9534; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9535[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9537; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9538; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9539; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A953A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A953B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A953C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A953D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A953E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A953F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9540; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9541; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9542; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9543; /* natively read BE16 header A byte 0x93 */
    u8 preamble_header_B_be16_byte_0_004A9544; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9545; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9546; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9547_004A954E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A954F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9550_004A9550[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9551; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9552_004A9555[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9556; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9557_004A955D[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A955E; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A955F; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9560; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9561; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9562; /* natively read BE16 command parameter byte 0x7B */
    u8 body_opcode_01_skipped_operand_004A9563[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9566_004A956C[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A956D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A956E_004A9571[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9572; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9573_004A9575[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9576; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9577_004A957F[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9580; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9581; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9582; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9583; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9584; /* natively read BE16 command parameter byte 0xB7 */
    u8 body_opcode_01_skipped_operand_004A9585[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9588_004A958A[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A958B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A958C_004A9593[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9594; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9595_004A9599[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A959A; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A959B; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A959C; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A959D; /* natively read BE16 command parameter byte 0x01 */
    u8 body_opcode_01_be16_byte_1_004A959E; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_skipped_operand_004A959F[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A95A2_004A95A4[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004A95A5; /* native body control/command opcode 0x05 */
    u8 body_opcode_05_004A95A6; /* native body control/command opcode 0x05 */
    u8 body_glyph_native_codes_004A95A7_004A95A8[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A95A9; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9530;
EffectTimelineStream_004A9530 data_effect_timeline_stream_004A9530 = {
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
    0x93,
    0x01,
    0x44,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x1A },
    0x0D,
    { 0x39, 0x3C, 0x3F, 0x38 },
    0x0D,
    { 0x34, 0x3F, 0x45, 0x38, 0x34, 0x37, 0x4C },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7B,
    { 0x01, 0x44, 0x80 },
    { 0x38, 0x4B, 0x3C, 0x46, 0x47, 0x46, 0x8E },
    0x0D,
    { 0x30, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x4C, 0x42, 0x48 },
    0x0D,
    { 0x42, 0x49, 0x38, 0x45, 0x4A, 0x45, 0x3C, 0x47, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xB7,
    { 0x01, 0x44, 0x80 },
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x43, 0x45, 0x38, 0x49, 0x3C, 0x42, 0x48, 0x46 },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34, 0x8F },
    0x04,
    0x00,
    0x01,
    0x01,
    0x00,
    { 0x01, 0x44, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
