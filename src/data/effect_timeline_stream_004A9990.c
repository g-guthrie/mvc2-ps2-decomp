/* Complete native count-prefixed effect-text stream, then the zero tail to the next
 * 0xB0-spaced stream: the caller writes a glyph byte at +0xAA, past the terminator. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9990; /* native record count 0x01 */
    u8 record_base_004A9991; /* native record base 0x00 */
    u8 preamble_opcode_0B_004A9992; /* preamble control opcode 0x0B */
    u8 preamble_opcode_0B_operand_004A9993; /* natively read command operand 0x00 */
    u8 preamble_opcode_0C_004A9994; /* preamble control opcode 0x0C */
    u8 preamble_opcode_0C_skipped_operand_004A9995[2]; /* cursor-consumed opaque command operands; no native load */
    u8 preamble_opcode_05_004A9997; /* preamble control opcode 0x05 */
    u8 preamble_opcode_05_operand_004A9998; /* natively read command operand 0x18 */
    u8 preamble_opcode_06_004A9999; /* preamble control opcode 0x06 */
    u8 preamble_opcode_06_operand_004A999A; /* natively read command operand 0xFF */
    u8 preamble_opcode_07_004A999B; /* preamble control opcode 0x07 */
    u8 preamble_opcode_07_operand_004A999C; /* natively read command operand 0xFF */
    u8 preamble_opcode_08_004A999D; /* preamble control opcode 0x08 */
    u8 preamble_opcode_08_operand_004A999E; /* natively read command operand 0xFF */
    u8 preamble_opcode_09_004A999F; /* preamble control opcode 0x09 */
    u8 preamble_opcode_09_operand_004A99A0; /* natively read command operand 0xFF */
    u8 preamble_opcode_01_004A99A1; /* preamble control opcode 0x01 */
    u8 preamble_header_A_be16_byte_0_004A99A2; /* natively read BE16 header A byte 0x00 */
    u8 preamble_header_A_be16_byte_1_004A99A3; /* natively read BE16 header A byte 0x90 */
    u8 preamble_header_B_be16_byte_0_004A99A4; /* natively read BE16 header B byte 0x00 */
    u8 preamble_header_B_be16_byte_1_004A99A5; /* natively read BE16 header B byte 0x98 */
    u8 preamble_header_u8_004A99A6; /* natively read header u8 0x80 */
    u8 body_glyph_native_codes_004A99A7_004A99AC[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99AD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99AE_004A99AF[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99B0; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99B1_004A99B7[7]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99B8; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99B9_004A99BB[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A99BC; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A99BD; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A99BE; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A99BF; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A99C0; /* natively read BE16 command parameter byte 0x70 */
    u8 body_opcode_01_skipped_operand_004A99C1[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A99C4_004A99C9[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99CA; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99CB_004A99CC[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99CD; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99CE_004A99D1[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99D2; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99D3_004A99D6[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99D7; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99D8_004A99DD[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A99DE; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A99DF; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A99E0; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A99E1; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A99E2; /* natively read BE16 command parameter byte 0x88 */
    u8 body_opcode_01_skipped_operand_004A99E3[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A99E6_004A99EA[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99EB; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99EC_004A99EE[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99EF; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99F0_004A99F4[5]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99F5; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99F6_004A99FB[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A99FC; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A99FD_004A99FE[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A99FF; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9A00; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9A01; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9A02; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9A03; /* natively read BE16 command parameter byte 0xB0 */
    u8 body_opcode_01_skipped_operand_004A9A04[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9A07_004A9A0C[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A0D; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A0E_004A9A0E[1]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A0F; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A10_004A9A12[3]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A13; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A14_004A9A17[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A18; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A19_004A9A1A[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_04_004A9A1B; /* native body control/command opcode 0x04 */
    u8 body_opcode_04_operand_004A9A1C; /* natively read command operand 0x00 */
    u8 body_opcode_01_004A9A1D; /* native body control/command opcode 0x01 */
    u8 body_opcode_01_be16_byte_0_004A9A1E; /* natively read BE16 command parameter byte 0x00 */
    u8 body_opcode_01_be16_byte_1_004A9A1F; /* natively read BE16 command parameter byte 0x9F */
    u8 body_opcode_01_skipped_operand_004A9A20[3]; /* cursor-consumed opaque command operands; no native load */
    u8 body_glyph_native_codes_004A9A23_004A9A28[6]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A29; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A2A_004A9A2D[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A2E; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A2F_004A9A32[4]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_0D_004A9A33; /* native body control/command opcode 0x0D */
    u8 body_glyph_native_codes_004A9A34_004A9A35[2]; /* natively read consecutive body glyph/native-code bytes */
    u8 body_opcode_00_004A9A36; /* native body control/command opcode 0x00 */
    u8 tail_004A9A37[9]; /* zero tail to 0x004A9A40; func_00421920 stores a glyph byte at stream +0xAA (0x004A9A3A) */
} EffectTimelineStream_004A9990;
EffectTimelineStream_004A9990 data_effect_timeline_stream_004A9990 = {
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
    0x90,
    0x00,
    0x98,
    0x80,
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 },
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
    { 0x00, 0x98, 0x80 },
    { 0x5C, 0x5A, 0x69, 0x5C, 0x68, 0x66 },
    0x0D,
    { 0x52, 0x99 },
    0x0D,
    { 0x46, 0x34, 0x49, 0x38 },
    0x0D,
    { 0x37, 0x34, 0x47, 0x34 },
    0x0D,
    { 0x39, 0x42, 0x48, 0x41, 0x37, 0x8E },
    0x04,
    0x00,
    0x01,
    0x00,
    0x88,
    { 0x00, 0x98, 0x80 },
    { 0x29, 0x45, 0x38, 0x46, 0x46 },
    0x0D,
    { 0x47, 0x3B, 0x38 },
    0x0D,
    { 0x2C, 0x2D, 0x1A, 0x2B, 0x2D },
    0x0D,
    { 0x35, 0x48, 0x47, 0x47, 0x42, 0x41 },
    0x0D,
    { 0x47, 0x42 },
    0x04,
    0x00,
    0x01,
    0x00,
    0xB0,
    { 0x00, 0x98, 0x80 },
    { 0x36, 0x45, 0x38, 0x34, 0x47, 0x38 },
    0x0D,
    { 0x34 },
    0x0D,
    { 0x41, 0x38, 0x4A },
    0x0D,
    { 0x39, 0x3C, 0x3F, 0x38 },
    0x0D,
    { 0x3C, 0x41 },
    0x04,
    0x00,
    0x01,
    0x00,
    0x9F,
    { 0x00, 0x98, 0x80 },
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 },
    0x0D,
    { 0x5C, 0x5A, 0x6B, 0x5D },
    0x0D,
    { 0x46, 0x3F, 0x42, 0x47 },
    0x0D,
    { 0x19, 0x8E },
    0x00,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
};
