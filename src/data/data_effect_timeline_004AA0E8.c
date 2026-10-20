/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA0E8_native_opcode_47;
    u8 body_3AA0E9_native_opcode_48;
    u8 body_3AA0EA_native_opcode_45;
    u8 body_3AA0EB_native_opcode_41;
    u8 body_3AA0EC_native_opcode_38;
    u8 body_3AA0ED_native_opcode_37;
    u8 body_3AA0EE_target_adjust_opcode_0D;
    u8 body_3AA0EF_native_opcode_42;
    u8 body_3AA0F0_native_opcode_39;
    u8 body_3AA0F1_native_opcode_39;
    u8 body_3AA0F2_native_opcode_8E;
    u8 body_3AA0F3_terminator_opcode;
} EffectTimelineRun_004AA0E8;
EffectTimelineRun_004AA0E8 data_effect_timeline_004AA0E8 = {
    0x47u, 0x48u, 0x45u, 0x41u, 0x38u, 0x37u, 0x0Du, 0x42u, 0x39u, 0x39u, 0x8Eu, 0x00u
};
