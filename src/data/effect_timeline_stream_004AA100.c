/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA100; /* native record count 0x01 */
    u8 record_base_004AA101; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA102; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA103; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA104; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA105[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA107; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA108; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA109; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA10A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA10B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA10C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA10D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA10E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA10F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA110; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA111; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA112; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA113; /* native-read BE16 header A 0x80 */
    u8 preamble_header_B_be16_byte_0_004AA114; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA115; /* native-read BE16 header B 0xC8 */
    u8 preamble_header_u8_004AA116; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA117_004AA11E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA11F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA120_004AA121[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA122; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA123_004AA129[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA12A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA12B_004AA12D[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA12E; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA12F; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA130; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA131; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA132; /* native-read BE16 command parameter 0x70 */
    u8 body_opcode_01_skipped_payload_004AA133[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA136_004AA13B[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA13C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA13D_004AA13E[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA13F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA140_004AA143[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA144; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA145_004AA148[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA149; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA14A_004AA14F[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA150; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA100;
EffectTimelineStream_004AA100 data_effect_timeline_stream_004AA100 = {
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
    0x80,
    0x00,
    0xC8,
    0x80,
    { 0x30, 0x1A, 0x2B, 0x27, 0x22, 0x27, 0x20, 0x91 },
    0x0D,
    { 0x27, 0x42 },
    0x0D,
    { 0x98, 0x66, 0x5A, 0x6B, 0x6F, 0x5E, 0x65 },
    0x0D,
    { 0x6F, 0x6C, 0x8E },
    0x04,
    0x00,
    0x01,
    0x00,
    0x70,
    { 0x00, 0xC8, 0x80 },
    { 0x5C, 0x5A, 0x69, 0x5C, 0x68, 0x66 },
    0x0D,
    { 0x52, 0x99 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38 },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x39, 0x42, 0x48, 0x41, 0x37, 0x8E },
    0x00,
};
