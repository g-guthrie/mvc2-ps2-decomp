/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA787_opcode_05;
    u8 preamble_3AA787_saved_value;
    u8 preamble_3AA789_opcode_06;
    u8 preamble_3AA789_payload_u8;
    u8 preamble_3AA78B_opcode_07;
    u8 preamble_3AA78B_payload_u8;
    u8 preamble_3AA78D_opcode_08;
    u8 preamble_3AA78D_payload_u8;
    u8 preamble_3AA78F_opcode_09;
    u8 preamble_3AA78F_payload_u8;
    u8 preamble_3AA791_opcode_01;
    u8 preamble_3AA791_be16_a_high;
    u8 preamble_3AA791_be16_a_low;
    u8 preamble_3AA791_be16_b_high;
    u8 preamble_3AA791_be16_b_low;
    u8 preamble_3AA791_native_read_u8;
    u8 body_3AA797_native_opcode_2D;
    u8 body_3AA798_native_opcode_3B;
    u8 body_3AA799_native_opcode_3C;
    u8 body_3AA79A_native_opcode_46;
    u8 body_3AA79B_target_adjust_opcode_0D;
    u8 body_3AA79C_native_opcode_26;
    u8 body_3AA79D_native_opcode_38;
    u8 body_3AA79E_native_opcode_46;
    u8 body_3AA79F_native_opcode_46;
    u8 body_3AA7A0_native_opcode_34;
    u8 body_3AA7A1_native_opcode_3A;
    u8 body_3AA7A2_native_opcode_38;
    u8 body_3AA7A3_target_adjust_opcode_0D;
    u8 body_3AA7A4_native_opcode_41;
    u8 body_3AA7A5_native_opcode_42;
    u8 body_3AA7A6_native_opcode_47;
    u8 body_3AA7A7_target_adjust_opcode_0D;
    u8 body_3AA7A8_native_opcode_1E;
    u8 body_3AA7A9_native_opcode_4B;
    u8 body_3AA7AA_native_opcode_3C;
    u8 body_3AA7AB_native_opcode_46;
    u8 body_3AA7AC_native_opcode_47;
    u8 body_3AA7AD_native_opcode_8E;
    u8 body_3AA7AE_terminator_opcode;
} EffectTimelineRun_004AA787;
EffectTimelineRun_004AA787 data_effect_timeline_004AA787 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0x93u, 0x01u, 0x44u, 0x80u, 0x2Du, 0x3Bu, 0x3Cu, 0x46u, 0x0Du, 0x26u, 0x38u, 0x46u, 0x46u, 0x34u, 0x3Au, 0x38u, 0x0Du, 0x41u, 0x42u, 0x47u, 0x0Du, 0x1Eu, 0x4Bu, 0x3Cu, 0x46u, 0x47u, 0x8Eu, 0x00u
};
