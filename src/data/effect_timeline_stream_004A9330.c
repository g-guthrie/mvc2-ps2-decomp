/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9330; /* native record count 0x01 */
    u8 record_base_004A9331; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9332; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9333; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9334; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9335[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9337; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9338; /* natively read command operand 0x00 */
    u8 preamble_opcode_06_004A9339; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A933A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A933B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A933C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A933D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A933E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A933F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9340; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9341; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9342; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9343; /* natively read BE16 header A byte 0x9E */
    u8 preamble_header_B_be16_byte_0_004A9344; /* natively read BE16 header B byte 0x01 */
    u8 preamble_header_B_be16_byte_1_004A9345; /* natively read BE16 header B byte 0x44 */
    u8 preamble_header_u8_004A9346; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9347_004A934C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A934D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A934E_004A9353[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9354; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9355_004A935B[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A935C; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9330;
EffectTimelineStream_004A9330 data_effect_timeline_stream_004A9330 = {
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
    0x9E,
    0x01,
    0x44,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x1F, 0x42, 0x45, 0x40, 0x34, 0x47 },
    0x0D,
    { 0x39, 0x34, 0x3C, 0x3F, 0x38, 0x37, 0x8E },
    0x00,
};
