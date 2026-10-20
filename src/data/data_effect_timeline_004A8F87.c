/* Native-read effect fields, bounded by the next callback root. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3A8F87_opcode_05;
    u8 preamble_3A8F87_saved_value;
    u8 preamble_3A8F89_opcode_06;
    u8 preamble_3A8F89_payload_u8;
    u8 preamble_3A8F8B_opcode_07;
    u8 preamble_3A8F8B_payload_u8;
    u8 preamble_3A8F8D_opcode_08;
    u8 preamble_3A8F8D_payload_u8;
    u8 preamble_3A8F8F_opcode_09;
    u8 preamble_3A8F8F_payload_u8;
    u8 preamble_3A8F91_opcode_01;
    u8 preamble_3A8F91_be16_a_high;
    u8 preamble_3A8F91_be16_a_low;
    u8 preamble_3A8F91_be16_b_high;
    u8 preamble_3A8F91_be16_b_low;
    u8 preamble_3A8F91_native_read_u8;
    u8 body_3A8F97_native_opcode_1E;
    u8 body_3A8F98_native_opcode_2B;
    u8 body_3A8F99_native_opcode_2B;
    u8 body_3A8F9A_native_opcode_28;
    u8 body_3A8F9B_native_opcode_2B;
    u8 body_3A8F9C_native_opcode_91;
    u8 body_3A8F9D_target_adjust_opcode_0D;
    u8 body_3A8F9E_native_opcode_27;
    u8 body_3A8F9F_native_opcode_42;
    u8 body_3A8FA0_target_adjust_opcode_0D;
    u8 body_3A8FA1_native_opcode_40;
    u8 body_3A8FA2_native_opcode_38;
    u8 body_3A8FA3_native_opcode_40;
    u8 body_3A8FA4_native_opcode_42;
    u8 body_3A8FA5_native_opcode_45;
    u8 body_3A8FA6_native_opcode_4C;
    u8 body_3A8FA7_target_adjust_opcode_0D;
    u8 body_3A8FA8_native_opcode_36;
    u8 body_3A8FA9_native_opcode_34;
    u8 body_3A8FAA_native_opcode_45;
    u8 body_3A8FAB_native_opcode_37;
    u8 body_3A8FAC_opcode_04;
    u8 body_3A8FAC_opcode_04_payload;
    u8 body_3A8FAE_opcode_01;
    u8 body_3A8FAE_be16_high;
    u8 body_3A8FAE_be16_low;
} EffectTimelineRun_004A8F87;
EffectTimelineRun_004A8F87 data_effect_timeline_004A8F87 = {
    0x05u, 0x00u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xA3u, 0x01u, 0x44u, 0x80u, 0x1Eu, 0x2Bu, 0x2Bu, 0x28u, 0x2Bu, 0x91u, 0x0Du, 0x27u, 0x42u, 0x0Du, 0x40u, 0x38u, 0x40u, 0x42u, 0x45u, 0x4Cu, 0x0Du, 0x36u, 0x34u, 0x45u, 0x37u, 0x04u, 0x00u, 0x01u, 0x00u, 0x62u
};
