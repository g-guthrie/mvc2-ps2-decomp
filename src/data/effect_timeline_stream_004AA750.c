/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA750; /* native record count 0x01 */
    u8 record_base_004AA751; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA752; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA753; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA754; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA755[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA757; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA758; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA759; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA75A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA75B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA75C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA75D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA75E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA75F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA760; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA761; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA762; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA763; /* native-read BE16 header A 0xAE */
    u8 preamble_header_B_be16_byte_0_004AA764; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA765; /* native-read BE16 header B 0xD0 */
    u8 preamble_header_u8_004AA766; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA767_004AA76C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA76D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA76E_004AA771[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA772; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA773_004AA779[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA77A; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA750;
EffectTimelineStream_004AA750 data_effect_timeline_stream_004AA750 = {
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
    0xAE,
    0x00,
    0xD0,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x25, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x8E },
    0x00,
};
