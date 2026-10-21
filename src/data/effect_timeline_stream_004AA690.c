/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004AA690; /* native record count 0x01 */
    u8 record_base_004AA691; /* native record base 0x00 */
    u8 preamble_opcode_0B_004AA692; /* native preamble opcode 0x0B */
    u8 preamble_opcode_0B_operand_004AA693; /* native-read preamble operand 0x00 */
    u8 preamble_opcode_0C_004AA694; /* native preamble opcode 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004AA695[2]; /* cursor-consumed command operands; no native loads */
    u8 preamble_opcode_05_004AA697; /* native preamble opcode 0x05 */
    u8 preamble_opcode_05_operand_004AA698; /* native-read preamble operand 0x18 */
    u8 preamble_opcode_06_004AA699; /* native preamble opcode 0x06 */
    u8 preamble_opcode_06_operand_004AA69A; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_07_004AA69B; /* native preamble opcode 0x07 */
    u8 preamble_opcode_07_operand_004AA69C; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_08_004AA69D; /* native preamble opcode 0x08 */
    u8 preamble_opcode_08_operand_004AA69E; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_09_004AA69F; /* native preamble opcode 0x09 */
    u8 preamble_opcode_09_operand_004AA6A0; /* native-read preamble operand 0xFF */
    u8 preamble_opcode_01_004AA6A1; /* native preamble opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004AA6A2; /* native-read BE16 header A 0x00 */
    u8 preamble_header_A_be16_byte_1_004AA6A3; /* native-read BE16 header A 0x77 */
    u8 preamble_header_B_be16_byte_0_004AA6A4; /* native-read BE16 header B 0x00 */
    u8 preamble_header_B_be16_byte_1_004AA6A5; /* native-read BE16 header B 0xA0 */
    u8 preamble_header_u8_004AA6A6; /* native-read header u8 0x80 */
    u8 body_glyph_native_codes_004AA6A7_004AA6AC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6AD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6AE_004AA6B9[12]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6BA; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6BB_004AA6C0[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA6C1; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA6C2; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA6C3; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA6C4; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA6C5; /* native-read BE16 command parameter 0x7B */
    u8 body_opcode_01_skipped_payload_004AA6C6[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA6C9_004AA6CE[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6CF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6D0_004AA6D0[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6D1; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6D2_004AA6D7[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6D8; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6D9_004AA6DC[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6DD; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6DE_004AA6E2[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA6E3; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA6E4; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA6E5; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA6E6; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA6E7; /* native-read BE16 command parameter 0x6A */
    u8 body_opcode_01_skipped_payload_004AA6E8[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA6EB_004AA6EE[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6EF; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6F0_004AA6FD[14]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA6FE; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA6FF_004AA702[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA703; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA704; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA705; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA706; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA707; /* native-read BE16 command parameter 0xA0 */
    u8 body_opcode_01_skipped_payload_004AA708[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA70B_004AA70C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA70D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA70E_004AA712[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA713; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA714_004AA718[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA719; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA71A_004AA71B[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA71C; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA71D_004AA720[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004AA721; /* native body command opcode 0x04 */
    u8 body_opcode_04_operand_004AA722; /* native-read command operand 0x00 */
    u8 body_opcode_01_004AA723; /* native body command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004AA724; /* native-read BE16 command parameter 0x00 */
    u8 body_opcode_01_be16_byte_1_004AA725; /* native-read BE16 command parameter 0x7F */
    u8 body_opcode_01_skipped_payload_004AA726[3]; /* cursor-consumed command operands; no native loads */
    u8 body_glyph_native_codes_004AA729_004AA72D[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA72E; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA72F_004AA730[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA731; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA732_004AA739[8]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA73A; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA73B_004AA73C[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004AA73D; /* native body command opcode 0x0D */
    u8 body_glyph_native_codes_004AA73E_004AA742[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004AA743; /* native body command opcode 0x00 */
} EffectTimelineStream_004AA690;
EffectTimelineStream_004AA690 data_effect_timeline_stream_004AA690 = {
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
    0x77,
    0x00,
    0xA0,
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
    { 0x00, 0xA0, 0x80 },
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
    { 0x00, 0xA0, 0x80 },
    { 0x93, 0x39, 0x42, 0x45 },
    0x0D,
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 },
    0x0D,
    { 0x4A, 0x3C, 0x47, 0x3B },
    0x04,
    0x00,
    0x01,
    0x00,
    0xA0,
    { 0x00, 0xA0, 0x80 },
    { 0x34, 0x47 },
    0x0D,
    { 0x3F, 0x38, 0x34, 0x46, 0x47 },
    0x0D,
    { 0x11, 0x11, 0x19, 0x24, 0x1B },
    0x0D,
    { 0x42, 0x39 },
    0x0D,
    { 0x39, 0x45, 0x38, 0x38 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x7F,
    { 0x00, 0xA0, 0x80 },
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
