/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9720; /* native record count 0x01 */
    u8 record_base_004A9721; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9722; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9723; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9724; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9725[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9727; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9728; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9729; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A972A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A972B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A972C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A972D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A972E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A972F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9730; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9731; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9732; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9733; /* natively read BE16 header A byte 0xC3 */
    u8 preamble_header_B_be16_byte_0_004A9734; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9735; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9736; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9737_004A973A[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A973B; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A973C_004A9746[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9747; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9720;
EffectTimelineStream_004A9720 data_effect_timeline_stream_004A9720 = {
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
    0xC3,
    0x01,
    0x44,
    0x80,
    { 0x25, 0x42, 0x34, 0x37 },
    0x0D,
    { 0x46, 0x48, 0x36, 0x36, 0x38, 0x46, 0x46, 0x39, 0x48, 0x3F, 0x8E },
    0x00,
};
