/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9060; /* 0x01 */
    u8 record_base_004A9061; /* 0x00 */
    u8 preamble_opcode_0B_004A9062; /* 0x0B */
    u8 preamble_opcode_0B_payload_004A9063; /* 0x00 */
    u8 preamble_opcode_0C_004A9064; /* 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9065[2]; /* cursor consumes; native does not load */
    u8 preamble_opcode_05_004A9067; /* 0x05 */
    u8 preamble_opcode_05_payload_004A9068; /* 0x00 */
    u8 preamble_opcode_06_004A9069; /* 0x06 */
    u8 preamble_opcode_06_payload_004A906A; /* 0xFF */
    u8 preamble_opcode_07_004A906B; /* 0x07 */
    u8 preamble_opcode_07_payload_004A906C; /* 0xFF */
    u8 preamble_opcode_08_004A906D; /* 0x08 */
    u8 preamble_opcode_08_payload_004A906E; /* 0xFF */
    u8 preamble_opcode_09_004A906F; /* 0x09 */
    u8 preamble_opcode_09_payload_004A9070; /* 0xFF */
    u8 preamble_opcode_01_004A9071; /* 0x01 */
    u8 preamble_be16_byte_0_004A9072; /* 0x00 */
    u8 preamble_be16_byte_1_004A9073; /* 0x77 */
    u8 preamble_native_parameter_0_004A9074; /* 0x01 */
    u8 preamble_native_parameter_1_004A9075; /* 0x36 */
    u8 preamble_native_parameter_2_004A9076; /* 0x80 */
    u8 body_glyph_codes_004A9077_004A907C[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A907D; /* 0x0D */
    u8 body_glyph_codes_004A907E_004A9089[12]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A908A; /* 0x0D */
    u8 body_glyph_codes_004A908B_004A9090[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A9091; /* 0x04 */
    u8 body_opcode_04_payload_004A9092; /* 0x00 */
    u8 body_opcode_01_004A9093; /* 0x01 */
    u8 body_be16_byte_0_004A9094; /* 0x00 */
    u8 body_be16_byte_1_004A9095; /* 0x7B */
    u8 body_opcode_01_skipped_payload_004A9096[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9099_004A909E[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A909F; /* 0x0D */
    u8 body_glyph_codes_004A90A0_004A90A0[1]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90A1; /* 0x0D */
    u8 body_glyph_codes_004A90A2_004A90A7[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90A8; /* 0x0D */
    u8 body_glyph_codes_004A90A9_004A90AC[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90AD; /* 0x0D */
    u8 body_glyph_codes_004A90AE_004A90B2[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A90B3; /* 0x04 */
    u8 body_opcode_04_payload_004A90B4; /* 0x00 */
    u8 body_opcode_01_004A90B5; /* 0x01 */
    u8 body_be16_byte_0_004A90B6; /* 0x00 */
    u8 body_be16_byte_1_004A90B7; /* 0x6A */
    u8 body_opcode_01_skipped_payload_004A90B8[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A90BB_004A90BE[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90BF; /* 0x0D */
    u8 body_glyph_codes_004A90C0_004A90CD[14]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90CE; /* 0x0D */
    u8 body_glyph_codes_004A90CF_004A90D2[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A90D3; /* 0x04 */
    u8 body_opcode_04_payload_004A90D4; /* 0x00 */
    u8 body_opcode_01_004A90D5; /* 0x01 */
    u8 body_be16_byte_0_004A90D6; /* 0x00 */
    u8 body_be16_byte_1_004A90D7; /* 0xA8 */
    u8 body_opcode_01_skipped_payload_004A90D8[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A90DB_004A90DC[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90DD; /* 0x0D */
    u8 body_glyph_codes_004A90DE_004A90E2[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90E3; /* 0x0D */
    u8 body_glyph_codes_004A90E4_004A90E7[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90E8; /* 0x0D */
    u8 body_glyph_codes_004A90E9_004A90EA[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90EB; /* 0x0D */
    u8 body_glyph_codes_004A90EC_004A90EF[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A90F0; /* 0x04 */
    u8 body_opcode_04_payload_004A90F1; /* 0x00 */
    u8 body_opcode_01_004A90F2; /* 0x01 */
    u8 body_be16_byte_0_004A90F3; /* 0x00 */
    u8 body_be16_byte_1_004A90F4; /* 0x7F */
    u8 body_opcode_01_skipped_payload_004A90F5[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A90F8_004A90FC[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A90FD; /* 0x0D */
    u8 body_glyph_codes_004A90FE_004A90FF[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9100; /* 0x0D */
    u8 body_glyph_codes_004A9101_004A9108[8]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9109; /* 0x0D */
    u8 body_glyph_codes_004A910A_004A910B[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A910C; /* 0x0D */
    u8 body_glyph_codes_004A910D_004A9111[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_00_004A9112; /* 0x00 */
} EffectTimelineStream_004A9060;
EffectTimelineStream_004A9060 data_effect_timeline_stream_004A9060 = {
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
    0x77,
    0x01,
    0x36,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
    0x0D,
    { 0x22, 0x41, 0x46, 0x48, 0x39, 0x39, 0x3C, 0x36, 0x3C, 0x38, 0x41, 0x47 },
    0x0D,
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7B,
    { 0x01, 0x36, 0x80 },
    { 0x46, 0x43, 0x34, 0x36, 0x38, 0x8E },
    0x0D,
    { 0x1A },
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
    0x6A,
    { 0x01, 0x36, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA8,
    { 0x01, 0x36, 0x80 },
    { 0x34, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x15, 0x17, 0x24, 0x1B },
    0x0D,
    { 0x42, 0x39 },
    0x0D,
    { 0x39, 0x45, 0x38, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7F,
    { 0x01, 0x36, 0x80 },
    { 0x46, 0x43, 0x34, 0x36, 0x38 },
    0x0D,
    { 0x3C, 0x46 },
    0x0D,
    { 0x45, 0x38, 0x44, 0x48, 0x3C, 0x45, 0x38, 0x37 },
    0x0D,
    { 0x47, 0x42 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38, 0x8E },
    0x00,
};
