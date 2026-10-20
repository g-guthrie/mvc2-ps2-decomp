/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA757_opcode_05;
    u8 preamble_3AA757_saved_value;
    u8 preamble_3AA759_opcode_06;
    u8 preamble_3AA759_payload_u8;
    u8 preamble_3AA75B_opcode_07;
    u8 preamble_3AA75B_payload_u8;
    u8 preamble_3AA75D_opcode_08;
    u8 preamble_3AA75D_payload_u8;
    u8 preamble_3AA75F_opcode_09;
    u8 preamble_3AA75F_payload_u8;
    u8 preamble_3AA761_opcode_01;
    u8 preamble_3AA761_be16_a_high;
    u8 preamble_3AA761_be16_a_low;
    u8 preamble_3AA761_be16_b_high;
    u8 preamble_3AA761_be16_b_low;
    u8 preamble_3AA761_native_read_u8;
    u8 body_3AA767_native_opcode_1E;
    u8 body_3AA768_native_opcode_2B;
    u8 body_3AA769_native_opcode_2B;
    u8 body_3AA76A_native_opcode_28;
    u8 body_3AA76B_native_opcode_2B;
    u8 body_3AA76C_native_opcode_91;
    u8 body_3AA76D_target_adjust_opcode_0D;
    u8 body_3AA76E_native_opcode_25;
    u8 body_3AA76F_native_opcode_42;
    u8 body_3AA770_native_opcode_34;
    u8 body_3AA771_native_opcode_37;
    u8 body_3AA772_target_adjust_opcode_0D;
    u8 body_3AA773_native_opcode_39;
    u8 body_3AA774_native_opcode_34;
    u8 body_3AA775_native_opcode_3C;
    u8 body_3AA776_native_opcode_3F;
    u8 body_3AA777_native_opcode_38;
    u8 body_3AA778_native_opcode_37;
    u8 body_3AA779_native_opcode_8E;
    u8 body_3AA77A_terminator_opcode;
} EffectTimelineRun_004AA757;
EffectTimelineRun_004AA757 data_effect_timeline_004AA757 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xAEu, 0x00u, 0xD0u, 0x80u, 0x1Eu, 0x2Bu, 0x2Bu, 0x28u, 0x2Bu, 0x91u, 0x0Du, 0x25u, 0x42u, 0x34u, 0x37u, 0x0Du, 0x39u, 0x34u, 0x3Cu, 0x3Fu, 0x38u, 0x37u, 0x8Eu, 0x00u
};
