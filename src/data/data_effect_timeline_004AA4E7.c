/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA4E7_opcode_05;
    u8 preamble_3AA4E7_saved_value;
    u8 preamble_3AA4E9_opcode_06;
    u8 preamble_3AA4E9_payload_u8;
    u8 preamble_3AA4EB_opcode_07;
    u8 preamble_3AA4EB_payload_u8;
    u8 preamble_3AA4ED_opcode_08;
    u8 preamble_3AA4ED_payload_u8;
    u8 preamble_3AA4EF_opcode_09;
    u8 preamble_3AA4EF_payload_u8;
    u8 preamble_3AA4F1_opcode_01;
    u8 preamble_3AA4F1_be16_a_high;
    u8 preamble_3AA4F1_be16_a_low;
    u8 preamble_3AA4F1_be16_b_high;
    u8 preamble_3AA4F1_be16_b_low;
    u8 preamble_3AA4F1_native_read_u8;
    u8 body_3AA4F7_native_opcode_1E;
    u8 body_3AA4F8_native_opcode_2B;
    u8 body_3AA4F9_native_opcode_2B;
    u8 body_3AA4FA_native_opcode_28;
    u8 body_3AA4FB_native_opcode_2B;
    u8 body_3AA4FC_native_opcode_91;
    u8 body_3AA4FD_target_adjust_opcode_0D;
    u8 body_3AA4FE_native_opcode_1F;
    u8 body_3AA4FF_native_opcode_42;
    u8 body_3AA500_native_opcode_45;
    u8 body_3AA501_native_opcode_40;
    u8 body_3AA502_native_opcode_34;
    u8 body_3AA503_native_opcode_47;
    u8 body_3AA504_target_adjust_opcode_0D;
    u8 body_3AA505_native_opcode_39;
    u8 body_3AA506_native_opcode_34;
    u8 body_3AA507_native_opcode_3C;
    u8 body_3AA508_native_opcode_3F;
    u8 body_3AA509_native_opcode_38;
    u8 body_3AA50A_native_opcode_37;
    u8 body_3AA50B_native_opcode_8E;
    u8 body_3AA50C_terminator_opcode;
} EffectTimelineRun_004AA4E7;
EffectTimelineRun_004AA4E7 data_effect_timeline_004AA4E7 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0x9Eu, 0x00u, 0xD0u, 0x80u, 0x1Eu, 0x2Bu, 0x2Bu, 0x28u, 0x2Bu, 0x91u, 0x0Du, 0x1Fu, 0x42u, 0x45u, 0x40u, 0x34u, 0x47u, 0x0Du, 0x39u, 0x34u, 0x3Cu, 0x3Fu, 0x38u, 0x37u, 0x8Eu, 0x00u
};
