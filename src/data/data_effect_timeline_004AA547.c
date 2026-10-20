/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA547_opcode_05;
    u8 preamble_3AA547_saved_value;
    u8 preamble_3AA549_opcode_06;
    u8 preamble_3AA549_payload_u8;
    u8 preamble_3AA54B_opcode_07;
    u8 preamble_3AA54B_payload_u8;
    u8 preamble_3AA54D_opcode_08;
    u8 preamble_3AA54D_payload_u8;
    u8 preamble_3AA54F_opcode_09;
    u8 preamble_3AA54F_payload_u8;
    u8 preamble_3AA551_opcode_01;
    u8 preamble_3AA551_be16_a_high;
    u8 preamble_3AA551_be16_a_low;
    u8 preamble_3AA551_be16_b_high;
    u8 preamble_3AA551_be16_b_low;
    u8 preamble_3AA551_native_read_u8;
    u8 body_3AA557_native_opcode_1E;
    u8 body_3AA558_native_opcode_2B;
    u8 body_3AA559_native_opcode_2B;
    u8 body_3AA55A_native_opcode_28;
    u8 body_3AA55B_native_opcode_2B;
    u8 body_3AA55C_native_opcode_91;
    u8 body_3AA55D_target_adjust_opcode_0D;
    u8 body_3AA55E_native_opcode_2C;
    u8 body_3AA55F_native_opcode_34;
    u8 body_3AA560_native_opcode_49;
    u8 body_3AA561_native_opcode_38;
    u8 body_3AA562_target_adjust_opcode_0D;
    u8 body_3AA563_native_opcode_39;
    u8 body_3AA564_native_opcode_34;
    u8 body_3AA565_native_opcode_3C;
    u8 body_3AA566_native_opcode_3F;
    u8 body_3AA567_native_opcode_38;
    u8 body_3AA568_native_opcode_37;
    u8 body_3AA569_native_opcode_8E;
    u8 body_3AA56A_terminator_opcode;
} EffectTimelineRun_004AA547;
EffectTimelineRun_004AA547 data_effect_timeline_004AA547 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xAEu, 0x00u, 0xD0u, 0x80u, 0x1Eu, 0x2Bu, 0x2Bu, 0x28u, 0x2Bu, 0x91u, 0x0Du, 0x2Cu, 0x34u, 0x49u, 0x38u, 0x0Du, 0x39u, 0x34u, 0x3Cu, 0x3Fu, 0x38u, 0x37u, 0x8Eu, 0x00u
};
