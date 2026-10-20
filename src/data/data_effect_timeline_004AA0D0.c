/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA0D0_native_opcode_39;
    u8 body_3AA0D1_native_opcode_48;
    u8 body_3AA0D2_native_opcode_41;
    u8 body_3AA0D3_native_opcode_36;
    u8 body_3AA0D4_native_opcode_47;
    u8 body_3AA0D5_native_opcode_3C;
    u8 body_3AA0D6_native_opcode_42;
    u8 body_3AA0D7_native_opcode_41;
    u8 body_3AA0D8_target_adjust_opcode_0D;
    u8 body_3AA0D9_native_opcode_4A;
    u8 body_3AA0DA_native_opcode_3C;
    u8 body_3AA0DB_native_opcode_3F;
    u8 body_3AA0DC_native_opcode_3F;
    u8 body_3AA0DD_target_adjust_opcode_0D;
    u8 body_3AA0DE_native_opcode_35;
    u8 body_3AA0DF_native_opcode_38;
    u8 body_3AA0E0_opcode_04;
    u8 body_3AA0E0_opcode_04_payload;
    u8 body_3AA0E2_opcode_01;
    u8 body_3AA0E2_be16_high;
    u8 body_3AA0E2_be16_low;
} EffectTimelineRun_004AA0D0;
EffectTimelineRun_004AA0D0 data_effect_timeline_004AA0D0 = {
    0x39u, 0x48u, 0x41u, 0x36u, 0x47u, 0x3Cu, 0x42u, 0x41u, 0x0Du, 0x4Au, 0x3Cu, 0x3Fu, 0x3Fu, 0x0Du, 0x35u, 0x38u, 0x04u, 0x00u, 0x01u, 0x00u, 0xEBu
};
