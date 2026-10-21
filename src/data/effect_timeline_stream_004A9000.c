/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9000; /* 0x01 */
    u8 record_base_004A9001; /* 0x00 */
    u8 preamble_opcode_0B_004A9002; /* 0x0B */
    u8 preamble_opcode_0B_payload_004A9003; /* 0x00 */
    u8 preamble_opcode_0C_004A9004; /* 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9005[2]; /* cursor consumes; native does not load */
    u8 preamble_opcode_05_004A9007; /* 0x05 */
    u8 preamble_opcode_05_payload_004A9008; /* 0x00 */
    u8 preamble_opcode_06_004A9009; /* 0x06 */
    u8 preamble_opcode_06_payload_004A900A; /* 0xFF */
    u8 preamble_opcode_07_004A900B; /* 0x07 */
    u8 preamble_opcode_07_payload_004A900C; /* 0xFF */
    u8 preamble_opcode_08_004A900D; /* 0x08 */
    u8 preamble_opcode_08_payload_004A900E; /* 0xFF */
    u8 preamble_opcode_09_004A900F; /* 0x09 */
    u8 preamble_opcode_09_payload_004A9010; /* 0xFF */
    u8 preamble_opcode_01_004A9011; /* 0x01 */
    u8 preamble_be16_byte_0_004A9012; /* 0x00 */
    u8 preamble_be16_byte_1_004A9013; /* 0x80 */
    u8 preamble_native_parameter_0_004A9014; /* 0x01 */
    u8 preamble_native_parameter_1_004A9015; /* 0x44 */
    u8 preamble_native_parameter_2_004A9016; /* 0x80 */
    u8 body_glyph_codes_004A9017_004A901E[8]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A901F; /* 0x0D */
    u8 body_glyph_codes_004A9020_004A9021[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9022; /* 0x0D */
    u8 body_glyph_codes_004A9023_004A9029[7]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A902A; /* 0x0D */
    u8 body_glyph_codes_004A902B_004A902D[3]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A902E; /* 0x04 */
    u8 body_opcode_04_payload_004A902F; /* 0x00 */
    u8 body_opcode_01_004A9030; /* 0x01 */
    u8 body_be16_byte_0_004A9031; /* 0x00 */
    u8 body_be16_byte_1_004A9032; /* 0x70 */
    u8 body_opcode_01_skipped_payload_004A9033[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9036_004A903B[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A903C; /* 0x0D */
    u8 body_glyph_codes_004A903D_004A903E[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A903F; /* 0x0D */
    u8 body_glyph_codes_004A9040_004A9043[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9044; /* 0x0D */
    u8 body_glyph_codes_004A9045_004A9048[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9049; /* 0x0D */
    u8 body_glyph_codes_004A904A_004A904F[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_00_004A9050; /* 0x00 */
} EffectTimelineStream_004A9000;
EffectTimelineStream_004A9000 data_effect_timeline_stream_004A9000 = {
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
    0x80,
    0x01,
    0x44,
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
    { 0x01, 0x44, 0x80 },
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
