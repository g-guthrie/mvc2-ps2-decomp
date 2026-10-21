/* One complete count-prefixed native effect-text stream; command/glyph bytes retain parser field roles. */
typedef unsigned char u8;
typedef struct {
    u8 record_count; /* func_004220B0 iterates this many calls to func_00422150; 0x01 */
    u8 record_base; /* the first byte consumed by func_00422150 after record_count; 0x00 */
    u8 preamble_004A8F82_opcode; /* preamble opcode 0x0B; 0x0B */
    u8 preamble_004A8F82_payload_u8; /* one payload byte consumed by preamble opcode 0x0B; 0x00 */
    u8 preamble_004A8F84_opcode; /* preamble opcode 0x0C; 0x0C */
    u8 preamble_004A8F84_opaque_u8_payload[2]; /* two cursor-consumed bytes; native does not load them */
    u8 preamble_004A8F87_opcode; /* preamble opcode 0x05; 0x05 */
    u8 preamble_004A8F87_payload_u8; /* one payload byte consumed by preamble opcode 0x05; 0x00 */
    u8 preamble_004A8F89_opcode; /* preamble opcode 0x06; 0x06 */
    u8 preamble_004A8F89_payload_u8; /* one payload byte consumed by preamble opcode 0x06; 0xFF */
    u8 preamble_004A8F8B_opcode; /* preamble opcode 0x07; 0x07 */
    u8 preamble_004A8F8B_payload_u8; /* one payload byte consumed by preamble opcode 0x07; 0xFF */
    u8 preamble_004A8F8D_opcode; /* preamble opcode 0x08; 0x08 */
    u8 preamble_004A8F8D_payload_u8; /* one payload byte consumed by preamble opcode 0x08; 0xFF */
    u8 preamble_004A8F8F_opcode; /* preamble opcode 0x09; 0x09 */
    u8 preamble_004A8F8F_payload_u8; /* one payload byte consumed by preamble opcode 0x09; 0xFF */
    u8 preamble_004A8F91_opcode; /* preamble opcode 0x01; 0x01 */
    u8 preamble_004A8F91_be16_a_hi; /* first byte of native-read big-endian parameter A; 0x00 */
    u8 preamble_004A8F91_be16_a_lo; /* second byte of native-read big-endian parameter A; 0xA3 */
    u8 preamble_004A8F91_be16_b_hi; /* first byte of native-read big-endian parameter B; 0x01 */
    u8 preamble_004A8F91_be16_b_lo; /* second byte of native-read big-endian parameter B; 0x44 */
    u8 preamble_004A8F91_native_u8; /* fifth preamble byte read by native code; 0x80 */
    u8 body_glyph_codes_004A8F97_004A8F9C[6]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8F9D_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8F9E_004A8F9F[2]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FA0_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FA1_004A8FA6[6]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FA7_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FA8_004A8FAB[4]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FAC_opcode; /* body opcode 0x04; 0x04 */
    u8 body_004A8FAC_advance_u8; /* single byte read and used by native text positioning; 0x00 */
    u8 body_004A8FAE_opcode; /* body opcode 0x01; 0x01 */
    u8 body_004A8FAE_be16_hi; /* first two body payload bytes are read/combined by native code; 0x00 */
    u8 body_004A8FAE_be16_lo; /* second body parameter byte; 0x62 */
    u8 body_004A8FAE_opaque_u8_payload[3]; /* three further bytes consumed by cursor advance without loads */
    u8 body_glyph_codes_004A8FB4_004A8FBC[9]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FBD_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FBE_004A8FCB[14]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FCC_opcode; /* body opcode 0x04; 0x04 */
    u8 body_004A8FCC_advance_u8; /* single byte read and used by native text positioning; 0x00 */
    u8 body_004A8FCE_opcode; /* body opcode 0x01; 0x01 */
    u8 body_004A8FCE_be16_hi; /* first two body payload bytes are read/combined by native code; 0x00 */
    u8 body_004A8FCE_be16_lo; /* second body parameter byte; 0x98 */
    u8 body_004A8FCE_opaque_u8_payload[3]; /* three further bytes consumed by cursor advance without loads */
    u8 body_glyph_codes_004A8FD4_004A8FD8[5]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FD9_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FDA_004A8FDB[2]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FDC_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FDD_004A8FE2[6]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FE3_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FE4_004A8FE7[4]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FE8_opcode; /* body opcode 0x04; 0x04 */
    u8 body_004A8FE8_advance_u8; /* single byte read and used by native text positioning; 0x00 */
    u8 body_004A8FEA_opcode; /* body opcode 0x01; 0x01 */
    u8 body_004A8FEA_be16_hi; /* first two body payload bytes are read/combined by native code; 0x01 */
    u8 body_004A8FEA_be16_lo; /* second body parameter byte; 0x0B */
    u8 body_004A8FEA_opaque_u8_payload[3]; /* three further bytes consumed by cursor advance without loads */
    u8 body_glyph_codes_004A8FF0_004A8FF3[4]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FF4_target_adjust_opcode; /* body target adjustment; consumes no payload bytes; 0x0D */
    u8 body_glyph_codes_004A8FF5_004A8FF6[2]; /* consecutive u8 glyph/native-code values parsed from text body */
    u8 body_004A8FF7_terminator; /* text-mode zero terminator; parser returns; 0x00 */
} EffectTimelineStream_004A8F80;

EffectTimelineStream_004A8F80 data_effect_timeline_stream_004A8F80 = {
    0x01, /* record_count */
    0x00, /* record_base */
    0x0B, /* preamble_004A8F82_opcode */
    0x00, /* preamble_004A8F82_payload_u8 */
    0x0C, /* preamble_004A8F84_opcode */
    { 0x00, 0x00 }, /* preamble_004A8F84_opaque_u8_payload */
    0x05, /* preamble_004A8F87_opcode */
    0x00, /* preamble_004A8F87_payload_u8 */
    0x06, /* preamble_004A8F89_opcode */
    0xFF, /* preamble_004A8F89_payload_u8 */
    0x07, /* preamble_004A8F8B_opcode */
    0xFF, /* preamble_004A8F8B_payload_u8 */
    0x08, /* preamble_004A8F8D_opcode */
    0xFF, /* preamble_004A8F8D_payload_u8 */
    0x09, /* preamble_004A8F8F_opcode */
    0xFF, /* preamble_004A8F8F_payload_u8 */
    0x01, /* preamble_004A8F91_opcode */
    0x00, /* preamble_004A8F91_be16_a_hi */
    0xA3, /* preamble_004A8F91_be16_a_lo */
    0x01, /* preamble_004A8F91_be16_b_hi */
    0x44, /* preamble_004A8F91_be16_b_lo */
    0x80, /* preamble_004A8F91_native_u8 */
    { 0x1E, 0x2B, 0x2B, 0x28, 0x2B, 0x91 }, /* body_glyph_codes_004A8F97_004A8F9C */
    0x0D, /* body_004A8F9D_target_adjust_opcode */
    { 0x27, 0x42 }, /* body_glyph_codes_004A8F9E_004A8F9F */
    0x0D, /* body_004A8FA0_target_adjust_opcode */
    { 0x40, 0x38, 0x40, 0x42, 0x45, 0x4C }, /* body_glyph_codes_004A8FA1_004A8FA6 */
    0x0D, /* body_004A8FA7_target_adjust_opcode */
    { 0x36, 0x34, 0x45, 0x37 }, /* body_glyph_codes_004A8FA8_004A8FAB */
    0x04, /* body_004A8FAC_opcode */
    0x00, /* body_004A8FAC_advance_u8 */
    0x01, /* body_004A8FAE_opcode */
    0x00, /* body_004A8FAE_be16_hi */
    0x62, /* body_004A8FAE_be16_lo */
    { 0x01, 0x44, 0x80 }, /* body_004A8FAE_opaque_u8_payload */
    { 0x93, 0x18, 0x26, 0x1B, 0x94, 0x93, 0x39, 0x42, 0x45 }, /* body_glyph_codes_004A8FB4_004A8FBC */
    0x0D, /* body_004A8FBD_target_adjust_opcode */
    { 0x69, 0x7F, 0x74, 0x8C, 0x6C, 0x87, 0x74, 0x87, 0x7C, 0x82, 0x81, 0x9A, 0x52, 0x94 }, /* body_glyph_codes_004A8FBE_004A8FCB */
    0x04, /* body_004A8FCC_opcode */
    0x00, /* body_004A8FCC_advance_u8 */
    0x01, /* body_004A8FCE_opcode */
    0x00, /* body_004A8FCE_be16_hi */
    0x98, /* body_004A8FCE_be16_lo */
    { 0x01, 0x44, 0x80 }, /* body_004A8FCE_opaque_u8_payload */
    { 0x39, 0x42, 0x48, 0x41, 0x37 }, /* body_glyph_codes_004A8FD4_004A8FD8 */
    0x0D, /* body_004A8FD9_target_adjust_opcode */
    { 0x3C, 0x41 }, /* body_glyph_codes_004A8FDA_004A8FDB */
    0x0D, /* body_004A8FDC_target_adjust_opcode */
    { 0x66, 0x5E, 0x66, 0x68, 0x6B, 0x72 }, /* body_glyph_codes_004A8FDD_004A8FE2 */
    0x0D, /* body_004A8FE3_target_adjust_opcode */
    { 0x5C, 0x5A, 0x6B, 0x5D }, /* body_glyph_codes_004A8FE4_004A8FE7 */
    0x04, /* body_004A8FE8_opcode */
    0x00, /* body_004A8FE8_advance_u8 */
    0x01, /* body_004A8FEA_opcode */
    0x01, /* body_004A8FEA_be16_hi */
    0x0B, /* body_004A8FEA_be16_lo */
    { 0x01, 0x44, 0x80 }, /* body_004A8FEA_opaque_u8_payload */
    { 0x46, 0x3F, 0x42, 0x47 }, /* body_glyph_codes_004A8FF0_004A8FF3 */
    0x0D, /* body_004A8FF4_target_adjust_opcode */
    { 0x19, 0x8E }, /* body_glyph_codes_004A8FF5_004A8FF6 */
    0x00, /* body_004A8FF7_terminator */
};
