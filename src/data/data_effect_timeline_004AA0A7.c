/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA0A7_opcode_05;
    u8 preamble_3AA0A7_saved_value;
    u8 preamble_3AA0A9_opcode_06;
    u8 preamble_3AA0A9_payload_u8;
    u8 preamble_3AA0AB_opcode_07;
    u8 preamble_3AA0AB_payload_u8;
    u8 preamble_3AA0AD_opcode_08;
    u8 preamble_3AA0AD_payload_u8;
    u8 preamble_3AA0AF_opcode_09;
    u8 preamble_3AA0AF_payload_u8;
    u8 preamble_3AA0B1_opcode_01;
    u8 preamble_3AA0B1_be16_a_high;
    u8 preamble_3AA0B1_be16_a_low;
    u8 preamble_3AA0B1_be16_b_high;
    u8 preamble_3AA0B1_be16_b_low;
    u8 preamble_3AA0B1_native_read_u8;
    u8 body_3AA0B7_native_opcode_30;
    u8 body_3AA0B8_native_opcode_1A;
    u8 body_3AA0B9_native_opcode_2B;
    u8 body_3AA0BA_native_opcode_27;
    u8 body_3AA0BB_native_opcode_22;
    u8 body_3AA0BC_native_opcode_27;
    u8 body_3AA0BD_native_opcode_20;
    u8 body_3AA0BE_native_opcode_91;
    u8 body_3AA0BF_target_adjust_opcode_0D;
    u8 body_3AA0C0_native_opcode_1A;
    u8 body_3AA0C1_native_opcode_48;
    u8 body_3AA0C2_native_opcode_47;
    u8 body_3AA0C3_native_opcode_42;
    u8 body_3AA0C4_native_opcode_46;
    u8 body_3AA0C5_native_opcode_34;
    u8 body_3AA0C6_native_opcode_49;
    u8 body_3AA0C7_native_opcode_38;
    u8 body_3AA0C8_opcode_04;
    u8 body_3AA0C8_opcode_04_payload;
    u8 body_3AA0CA_opcode_01;
    u8 body_3AA0CA_be16_high;
    u8 body_3AA0CA_be16_low;
} EffectTimelineRun_004AA0A7;
EffectTimelineRun_004AA0A7 data_effect_timeline_004AA0A7 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xBBu, 0x00u, 0xB0u, 0x80u, 0x30u, 0x1Au, 0x2Bu, 0x27u, 0x22u, 0x27u, 0x20u, 0x91u, 0x0Du, 0x1Au, 0x48u, 0x47u, 0x42u, 0x46u, 0x34u, 0x49u, 0x38u, 0x04u, 0x00u, 0x01u, 0x00u, 0xC8u
};
