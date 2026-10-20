/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA094_native_opcode_32;
    u8 body_3AA095_native_opcode_38;
    u8 body_3AA096_native_opcode_46;
    u8 body_3AA097_target_adjust_opcode_05;
    u8 body_3AA098_target_adjust_opcode_05;
    u8 body_3AA099_native_opcode_27;
    u8 body_3AA09A_native_opcode_42;
    u8 body_3AA09B_terminator_opcode;
} EffectTimelineRun_004AA094;
EffectTimelineRun_004AA094 data_effect_timeline_004AA094 = {
    0x32u, 0x38u, 0x46u, 0x05u, 0x05u, 0x27u, 0x42u, 0x00u
};
