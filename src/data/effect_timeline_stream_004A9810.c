/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9810; /* native record count 0x01 */
    u8 record_base_004A9811; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9812; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9813; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9814; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9815[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9817; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9818; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9819; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A981A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A981B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A981C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A981D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A981E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A981F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A9820; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A9821; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A9822; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A9823; /* natively read BE16 header A byte 0xA0 */
    u8 preamble_header_B_be16_byte_0_004A9824; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A9825; /* natively read BE16 header B byte 0xB0 */
    u8 preamble_header_u8_004A9826; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A9827_004A9831[11]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9832; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9833_004A9836[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9837; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9838_004A983B[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A983C; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A983D; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A983E; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A983F; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9840; /* natively read BE16 command parameter byte 0x99 */
    u8 body_opcode_01_skipped_operand_004A9841[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9844_004A9849[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A984A; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A984B_004A984E[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A984F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9850_004A9858[9]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9859; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A985A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A985B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A985C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A985D; /* natively read BE16 command parameter byte 0x6D */
    u8 body_opcode_01_skipped_operand_004A985E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9861_004A986E[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A986F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9870_004A9871[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9872; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9873_004A9878[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9879; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A987A; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A987B; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A987C; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A987D; /* natively read BE16 command parameter byte 0xEB */
    u8 body_opcode_01_skipped_operand_004A987E[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9881_004A9884[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9885; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9886_004A988B[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A988C; /* native body control/command opcode 0x00 */
} EffectTimelineStream_004A9810;
EffectTimelineStream_004A9810 data_effect_timeline_stream_004A9810 = {
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
    0xA0,
    0x00,
    0xB0,
    0x80,
    { 0x1A, 0x48, 0x47, 0x42, 0x3F, 0x42, 0x34, 0x37, 0x3C, 0x41, 0x3A },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x39, 0x45, 0x42, 0x40 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x99,
    { 0x00, 0xB0, 0x80 },
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x0D,
    { 0x36, 0x34, 0x45, 0x37 },
    0x0D,
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x6D,
    { 0x00, 0xB0, 0x80 },
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x3C, 0x41 },
    0x0D,
    { 0x26, 0x1E, 0x26, 0x28, 0x2B, 0x32 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xEB,
    { 0x00, 0xB0, 0x80 },
    { 0x1C, 0x1A, 0x2B, 0x1D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47, 0x19, 0x8E },
    0x00,
};
