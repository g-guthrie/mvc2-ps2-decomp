/* Complete native count-prefixed effect-text stream; inter-root gap excluded. */
typedef unsigned char u8;
typedef struct {
    u8 record_count_004A9120; /* 0x01 */
    u8 record_base_004A9121; /* 0x00 */
    u8 preamble_opcode_0B_004A9122; /* 0x0B */
    u8 preamble_opcode_0B_payload_004A9123; /* 0x00 */
    u8 preamble_opcode_0C_004A9124; /* 0x0C */
    u8 preamble_opcode_0C_skipped_payload_004A9125[2]; /* cursor consumes; native does not load */
    u8 preamble_opcode_05_004A9127; /* 0x05 */
    u8 preamble_opcode_05_payload_004A9128; /* 0x00 */
    u8 preamble_opcode_06_004A9129; /* 0x06 */
    u8 preamble_opcode_06_payload_004A912A; /* 0xFF */
    u8 preamble_opcode_07_004A912B; /* 0x07 */
    u8 preamble_opcode_07_payload_004A912C; /* 0xFF */
    u8 preamble_opcode_08_004A912D; /* 0x08 */
    u8 preamble_opcode_08_payload_004A912E; /* 0xFF */
    u8 preamble_opcode_09_004A912F; /* 0x09 */
    u8 preamble_opcode_09_payload_004A9130; /* 0xFF */
    u8 preamble_opcode_01_004A9131; /* 0x01 */
    u8 preamble_be16_byte_0_004A9132; /* 0x00 */
    u8 preamble_be16_byte_1_004A9133; /* 0x77 */
    u8 preamble_native_parameter_0_004A9134; /* 0x01 */
    u8 preamble_native_parameter_1_004A9135; /* 0x44 */
    u8 preamble_native_parameter_2_004A9136; /* 0x80 */
    u8 body_glyph_codes_004A9137_004A913C[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A913D; /* 0x0D */
    u8 body_glyph_codes_004A913E_004A9149[12]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A914A; /* 0x0D */
    u8 body_glyph_codes_004A914B_004A9150[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A9151; /* 0x04 */
    u8 body_opcode_04_payload_004A9152; /* 0x00 */
    u8 body_opcode_01_004A9153; /* 0x01 */
    u8 body_be16_byte_0_004A9154; /* 0x00 */
    u8 body_be16_byte_1_004A9155; /* 0x7B */
    u8 body_opcode_01_skipped_payload_004A9156[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A9159_004A915E[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A915F; /* 0x0D */
    u8 body_glyph_codes_004A9160_004A9160[1]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9161; /* 0x0D */
    u8 body_glyph_codes_004A9162_004A9167[6]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A9168; /* 0x0D */
    u8 body_glyph_codes_004A9169_004A916C[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A916D; /* 0x0D */
    u8 body_glyph_codes_004A916E_004A9172[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A9173; /* 0x04 */
    u8 body_opcode_04_payload_004A9174; /* 0x00 */
    u8 body_opcode_01_004A9175; /* 0x01 */
    u8 body_be16_byte_0_004A9176; /* 0x00 */
    u8 body_be16_byte_1_004A9177; /* 0x6A */
    u8 body_opcode_01_skipped_payload_004A9178[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A917B_004A917E[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A917F; /* 0x0D */
    u8 body_glyph_codes_004A9180_004A918D[14]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A918E; /* 0x0D */
    u8 body_glyph_codes_004A918F_004A9192[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A9193; /* 0x04 */
    u8 body_opcode_04_payload_004A9194; /* 0x00 */
    u8 body_opcode_01_004A9195; /* 0x01 */
    u8 body_be16_byte_0_004A9196; /* 0x00 */
    u8 body_be16_byte_1_004A9197; /* 0xA0 */
    u8 body_opcode_01_skipped_payload_004A9198[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A919B_004A919C[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A919D; /* 0x0D */
    u8 body_glyph_codes_004A919E_004A91A2[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91A3; /* 0x0D */
    u8 body_glyph_codes_004A91A4_004A91A8[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91A9; /* 0x0D */
    u8 body_glyph_codes_004A91AA_004A91AB[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91AC; /* 0x0D */
    u8 body_glyph_codes_004A91AD_004A91B0[4]; /* consecutive native-read glyph codes */
    u8 body_opcode_04_004A91B1; /* 0x04 */
    u8 body_opcode_04_payload_004A91B2; /* 0x00 */
    u8 body_opcode_01_004A91B3; /* 0x01 */
    u8 body_be16_byte_0_004A91B4; /* 0x00 */
    u8 body_be16_byte_1_004A91B5; /* 0x7F */
    u8 body_opcode_01_skipped_payload_004A91B6[3]; /* cursor consumes; native does not load */
    u8 body_glyph_codes_004A91B9_004A91BD[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91BE; /* 0x0D */
    u8 body_glyph_codes_004A91BF_004A91C0[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91C1; /* 0x0D */
    u8 body_glyph_codes_004A91C2_004A91C9[8]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91CA; /* 0x0D */
    u8 body_glyph_codes_004A91CB_004A91CC[2]; /* consecutive native-read glyph codes */
    u8 body_opcode_0D_004A91CD; /* 0x0D */
    u8 body_glyph_codes_004A91CE_004A91D2[5]; /* consecutive native-read glyph codes */
    u8 body_opcode_00_004A91D3; /* 0x00 */
} EffectTimelineStream_004A9120;
EffectTimelineStream_004A9120 data_effect_timeline_stream_004A9120 = {
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
    0x44,
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
    { 0x01, 0x44, 0x80 },
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
    { 0x01, 0x44, 0x80 },
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
    { 0x01, 0x44, 0x80 },
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
    { 0x01, 0x44, 0x80 },
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
