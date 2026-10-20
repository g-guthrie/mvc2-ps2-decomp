/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA3A4_native_opcode_32;
    u8 body_3AA3A5_native_opcode_38;
    u8 body_3AA3A6_native_opcode_46;
    u8 body_3AA3A7_target_adjust_opcode_05;
    u8 body_3AA3A8_target_adjust_opcode_05;
    u8 body_3AA3A9_native_opcode_27;
    u8 body_3AA3AA_native_opcode_42;
    u8 body_3AA3AB_terminator_opcode;
} EffectTimelineRun_004AA3A4;
EffectTimelineRun_004AA3A4 data_effect_timeline_004AA3A4 = {
    0x32u, 0x38u, 0x46u, 0x05u, 0x05u, 0x27u, 0x42u, 0x00u
};
