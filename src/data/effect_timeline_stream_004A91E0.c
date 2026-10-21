/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A91E0; /* 0x01 */
    u8 record_base_004A91E1; /* 0x00 */
    u8 preamble_opcode_0B_004A91E2; /* 0x0B */
    u8 preamble_opcode_0B_payload_004A91E3; /* 0x00 */
    u8 preamble_opcode_0C_004A91E4; /* 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A91E5[2]; /* cursor consumes; native does not load */
    u8 preamble_opcode_05_004A91E7; /* 0x05 */
    u8 preamble_opcode_05_payload_004A91E8; /* 0x00 */
    u8 preamble_opcode_06_004A91E9; /* 0x06 */
    u8 preamble_opcode_06_payload_004A91EA; /* 0xFF */
    u8 preamble_opcode_07_004A91EB; /* 0x07 */
    u8 preamble_opcode_07_payload_004A91EC; /* 0xFF */
    u8 preamble_opcode_08_004A91ED; /* 0x08 */
    u8 preamble_opcode_08_payload_004A91EE; /* 0xFF */
    u8 preamble_opcode_09_004A91EF; /* 0x09 */
    u8 preamble_opcode_09_payload_004A91F0; /* 0xFF */
    u8 preamble_opcode_01_004A91F1; /* 0x01 */
    u8 preamble_be16_byte_0_004A91F2; /* 0x00 */
    u8 preamble_be16_byte_1_004A91F3; /* 0x87 */
    u8 preamble_native_parameter_0_004A91F4; /* 0x01 */
    u8 preamble_native_parameter_1_004A91F5; /* 0x36 */
    u8 preamble_native_parameter_2_004A91F6; /* 0x80 */
    u8 body_glyph_codes_004A91F7_004A91FC[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91FD; /* 0x0D */
    u8 body_glyph_codes_004A91FE_004A9203[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9204; /* 0x0D */
    u8 body_glyph_codes_004A9205_004A9208[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9209; /* 0x0D */
    u8 body_glyph_codes_004A920A_004A920E[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A920F; /* 0x04 */
    u8 body_opcode_04_payload_004A9210; /* 0x00 */
    u8 body_opcode_01_004A9211; /* 0x01 */
    u8 body_be16_byte_0_004A9212; /* 0x00 */
    u8 body_be16_byte_1_004A9213; /* 0x7A */
    u8 body_opcode_01_skipped_payload_004A9214[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9217_004A921A[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A921B; /* 0x0D */
    u8 body_glyph_codes_004A921C_004A9229[14]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A922A; /* 0x0D */
    u8 body_glyph_codes_004A922B_004A922C[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A922D; /* 0x04 */
    u8 body_opcode_04_payload_004A922E; /* 0x00 */
    u8 body_opcode_01_004A922F; /* 0x01 */
    u8 body_be16_byte_0_004A9230; /* 0x00 */
    u8 body_be16_byte_1_004A9231; /* 0x9F */
    u8 body_opcode_01_skipped_payload_004A9232[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9235_004A9240[12]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9241; /* 0x0D */
    u8 body_glyph_codes_004A9242_004A9245[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9246; /* 0x0D */
    u8 body_glyph_codes_004A9247_004A9249[3]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A924A; /* 0x04 */
    u8 body_opcode_04_payload_004A924B; /* 0x00 */
    u8 body_opcode_01_004A924C; /* 0x01 */
    u8 body_be16_byte_0_004A924D; /* 0x00 */
    u8 body_be16_byte_1_004A924E; /* 0xF3 */
    u8 body_opcode_01_skipped_payload_004A924F[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9252_004A9257[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9258; /* 0x0D */
    u8 body_glyph_codes_004A9259_004A925B[3]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A925C; /* 0x04 */
    u8 body_opcode_04_payload_004A925D; /* 0x00 */
    u8 body_opcode_01_004A925E; /* 0x01 */
    u8 body_be16_byte_0_004A925F; /* 0x01 */
    u8 body_be16_byte_1_004A9260; /* 0x00 */
    u8 body_opcode_01_skipped_payload_004A9261[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9264_004A9266[3]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9267; /* 0x0D */
    u8 body_opcode_0D_004A9268; /* 0x0D */
    u8 body_opcode_0D_004A9269; /* 0x0D */
    u8 body_opcode_0D_004A926A; /* 0x0D */
    u8 body_opcode_0D_004A926B; /* 0x0D */
    u8 body_opcode_0D_004A926C; /* 0x0D */
    u8 body_glyph_codes_004A926D_004A926E[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_00_004A926F; /* 0x00 */
} EffectTimelineStream_004A91E0;
EffectTimelineStream_004A91E0 data_effect_timeline_stream_004A91E0 = {
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
    0x87,
    0x01,
    0x36,
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
    { 0x01, 0x36, 0x80 },
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
    { 0x01, 0x36, 0x80 },
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
    { 0x01, 0x36, 0x80 },
    { 0x39, 0x42, 0x45, 0x40, 0x34, 0x47 },
    0x0D,
    { 0x3C, 0x47, 0x8F },
    0x04,
    0x00,
    0x01,
    0x01,
    0x00,
    { 0x01, 0x36, 0x80 },
    { 0x32, 0x38, 0x46 },
    0x0D,
    0x0D,
    0x0D,
    0x0D,
    0x0D,
    0x0D,
    { 0x27, 0x42 },
    0x00,
};
