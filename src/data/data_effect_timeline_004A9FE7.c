/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3A9FE7_opcode_05;
    u8 preamble_3A9FE7_saved_value;
    u8 preamble_3A9FE9_opcode_06;
    u8 preamble_3A9FE9_payload_u8;
    u8 preamble_3A9FEB_opcode_07;
    u8 preamble_3A9FEB_payload_u8;
    u8 preamble_3A9FED_opcode_08;
    u8 preamble_3A9FED_payload_u8;
    u8 preamble_3A9FEF_opcode_09;
    u8 preamble_3A9FEF_payload_u8;
    u8 preamble_3A9FF1_opcode_01;
    u8 preamble_3A9FF1_be16_a_high;
    u8 preamble_3A9FF1_be16_a_low;
    u8 preamble_3A9FF1_be16_b_high;
    u8 preamble_3A9FF1_be16_b_low;
    u8 preamble_3A9FF1_native_read_u8;
    u8 body_3A9FF7_native_opcode_1A;
    u8 body_3A9FF8_native_opcode_48;
    u8 body_3A9FF9_native_opcode_47;
    u8 body_3A9FFA_native_opcode_42;
    u8 body_3A9FFB_native_opcode_3F;
    u8 body_3A9FFC_native_opcode_42;
    u8 body_3A9FFD_native_opcode_34;
    u8 body_3A9FFE_native_opcode_37;
    u8 body_3A9FFF_target_adjust_opcode_0D;
    u8 body_3AA000_native_opcode_46;
    u8 body_3AA001_native_opcode_48;
    u8 body_3AA002_native_opcode_36;
    u8 body_3AA003_native_opcode_36;
    u8 body_3AA004_native_opcode_38;
    u8 body_3AA005_native_opcode_46;
    u8 body_3AA006_native_opcode_46;
    u8 body_3AA007_native_opcode_39;
    u8 body_3AA008_native_opcode_48;
    u8 body_3AA009_native_opcode_3F;
    u8 body_3AA00A_native_opcode_8E;
    u8 body_3AA00B_terminator_opcode;
} EffectTimelineRun_004A9FE7;
EffectTimelineRun_004A9FE7 data_effect_timeline_004A9FE7 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xA3u, 0xFCu, 0xDBu, 0x80u, 0x1Au, 0x48u, 0x47u, 0x42u, 0x3Fu, 0x42u, 0x34u, 0x37u, 0x0Du, 0x46u, 0x48u, 0x36u, 0x36u, 0x38u, 0x46u, 0x46u, 0x39u, 0x48u, 0x3Fu, 0x8Eu, 0x00u
};
