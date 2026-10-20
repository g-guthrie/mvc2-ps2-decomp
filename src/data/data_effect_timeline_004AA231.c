/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA231_native_opcode_32;
    u8 body_3AA232_native_opcode_38;
    u8 body_3AA233_native_opcode_46;
    u8 body_3AA234_target_adjust_opcode_05;
    u8 body_3AA235_target_adjust_opcode_05;
    u8 body_3AA236_native_opcode_27;
    u8 body_3AA237_native_opcode_42;
    u8 body_3AA238_terminator_opcode;
} EffectTimelineRun_004AA231;
EffectTimelineRun_004AA231 data_effect_timeline_004AA231 = {
    0x32u, 0x38u, 0x46u, 0x05u, 0x05u, 0x27u, 0x42u, 0x00u
};
