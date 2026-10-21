/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA850; /* native record count 0x01 */
    u8 record_base_004AA851; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA852; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA853; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA854; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA855[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA857; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA858; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA859; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA85A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA85B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA85C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA85D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA85E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA85F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA860; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA861; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA862; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA863; /* native-read BE16 header A 0x78 */
    u8 preamble_header_B_be16_byte_0_004AA864; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA865; /* native-read BE16 header B 0xB0 */
    u8 preamble_header_u8_004AA866; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA867_004AA86E[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA86F; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA870_004AA875[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA876; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA877_004AA87A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA87B; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA87C_004AA880[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA881; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA882; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA883; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA884; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA885; /* native-read BE16 command parameter 0x85 */
    u8 body_opcode_01_skipped_payload_004AA886[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA889_004AA88C[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA88D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA88E_004AA89C[15]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA89D; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA850;
EffectTimelineStream_004AA850 data_effect_timeline_stream_004AA850 = {
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
    0x78,
    0x00,
    0xB0,
    0x80,
    { 0x1C, 0x3B, 0x38, 0x36, 0x3E, 0x3C, 0x41, 0x3A },
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
    0x85,
    { 0x00, 0xB0, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94, 0x8E },
    0x00,
};
