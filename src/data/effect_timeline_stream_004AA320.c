/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA320; /* native record count 0x01 */
    u8 record_base_004AA321; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA322; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA323; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA324; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA325[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA327; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA328; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA329; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA32A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA32B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA32C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA32D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA32E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA32F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA330; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA331; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA332; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA333; /* native-read BE16 header A 0x87 */
    u8 preamble_header_B_be16_byte_0_004AA334; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA335; /* native-read BE16 header B 0x98 */
    u8 preamble_header_u8_004AA336; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA337_004AA33C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA33D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA33E_004AA343[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA344; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA345_004AA348[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA349; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA34A_004AA34E[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA34F; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA350; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA351; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA352; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA353; /* native-read BE16 command parameter 0x7A */
    u8 body_opcode_01_skipped_payload_004AA354[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA357_004AA35A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA35B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA35C_004AA369[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA36A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA36B_004AA36C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA36D; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA36E; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA36F; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA370; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA371; /* native-read BE16 command parameter 0x9F */
    u8 body_opcode_01_skipped_payload_004AA372[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA375_004AA380[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA381; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA382_004AA385[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA386; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA387_004AA389[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA38A; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA38B; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA38C; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA38D; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA38E; /* native-read BE16 command parameter 0xF3 */
    u8 body_opcode_01_skipped_payload_004AA38F[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA392_004AA397[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA398; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA399_004AA39B[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA39C; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA39D; /* native-read command operand 0x18 */
    u8 body_opcode_01_004AA39E; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA39F; /* native-read BE16 command parameter 0x01 */
    u8 body_opcode_01_be16_byte_1_004AA3A0; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_skipped_payload_004AA3A1[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA3A4_004AA3A6[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_05_004AA3A7; /* native body command opcode 0x05 */
    u8 body_opcode_05_004AA3A8; /* native body command opcode 0x05 */
    u8 body_glyph_native_codes_004AA3A9_004AA3AA[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA3AB; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA320;
EffectTimelineStream_004AA320 data_effect_timeline_stream_004AA320 = {
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
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x26, 0x38, 0x40, 0x42, 0x45, 0x4C },
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
    { 0x3C, 0x46 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x98, 0x80 },
    { 0x48, 0x41, 0x39, 0x42, 0x45, 0x40, 0x34, 0x47, 0x47, 0x38, 0x37, 0x8E },
    0x0D,
    { 0x30, 0x3C, 0x3F, 0x3F },
    0x0D,
    { 0x4C, 0x42, 0x48 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xF3,
    { 0x00, 0x98, 0x80 },
    { 0x39, 0x42, 0x45, 0x40, 0x34, 0x47 },
    0x0D,
    { 0x3C, 0x47, 0x8F },
    0x04,
    0x18,
    0x01,
    0x01,
    0x00,
    { 0x00, 0x98, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x05,
    0x05,
    { 0x27, 0x42 },
    0x00,
};
