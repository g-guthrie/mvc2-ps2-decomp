/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA3B7_opcode_05;
    u8 preamble_3AA3B7_saved_value;
    u8 preamble_3AA3B9_opcode_06;
    u8 preamble_3AA3B9_payload_u8;
    u8 preamble_3AA3BB_opcode_07;
    u8 preamble_3AA3BB_payload_u8;
    u8 preamble_3AA3BD_opcode_08;
    u8 preamble_3AA3BD_payload_u8;
    u8 preamble_3AA3BF_opcode_09;
    u8 preamble_3AA3BF_payload_u8;
    u8 preamble_3AA3C1_opcode_01;
    u8 preamble_3AA3C1_be16_a_high;
    u8 preamble_3AA3C1_be16_a_low;
    u8 preamble_3AA3C1_be16_b_high;
    u8 preamble_3AA3C1_be16_b_low;
    u8 preamble_3AA3C1_native_read_u8;
    u8 body_3AA3C7_native_opcode_1E;
    u8 body_3AA3C8_native_opcode_2B;
    u8 body_3AA3C9_native_opcode_2B;
    u8 body_3AA3CA_native_opcode_28;
    u8 body_3AA3CB_native_opcode_2B;
    u8 body_3AA3CC_native_opcode_91;
    u8 body_3AA3CD_target_adjust_opcode_0D;
    u8 body_3AA3CE_native_opcode_27;
    u8 body_3AA3CF_native_opcode_42;
    u8 body_3AA3D0_target_adjust_opcode_0D;
    u8 body_3AA3D1_native_opcode_40;
    u8 body_3AA3D2_native_opcode_38;
    u8 body_3AA3D3_native_opcode_40;
    u8 body_3AA3D4_native_opcode_42;
    u8 body_3AA3D5_native_opcode_45;
    u8 body_3AA3D6_native_opcode_4C;
    u8 body_3AA3D7_target_adjust_opcode_0D;
    u8 body_3AA3D8_native_opcode_36;
    u8 body_3AA3D9_native_opcode_34;
    u8 body_3AA3DA_native_opcode_45;
    u8 body_3AA3DB_native_opcode_37;
    u8 body_3AA3DC_opcode_04;
    u8 body_3AA3DC_opcode_04_payload;
    u8 body_3AA3DE_opcode_01;
    u8 body_3AA3DE_be16_high;
    u8 body_3AA3DE_be16_low;
} EffectTimelineRun_004AA3B7;
EffectTimelineRun_004AA3B7 data_effect_timeline_004AA3B7 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xA3u, 0x00u, 0xA8u, 0x80u, 0x1Eu, 0x2Bu, 0x2Bu, 0x28u, 0x2Bu, 0x91u, 0x0Du, 0x27u, 0x42u, 0x0Du, 0x40u, 0x38u, 0x40u, 0x42u, 0x45u, 0x4Cu, 0x0Du, 0x36u, 0x34u, 0x45u, 0x37u, 0x04u, 0x00u, 0x01u, 0x00u, 0x62u
};
