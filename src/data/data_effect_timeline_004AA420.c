/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA420_native_opcode_46;
    u8 body_3AA421_native_opcode_3F;
    u8 body_3AA422_native_opcode_42;
    u8 body_3AA423_native_opcode_47;
    u8 body_3AA424_target_adjust_opcode_0D;
    u8 body_3AA425_native_opcode_19;
    u8 body_3AA426_native_opcode_8E;
    u8 body_3AA427_terminator_opcode;
} EffectTimelineRun_004AA420;
EffectTimelineRun_004AA420 data_effect_timeline_004AA420 = {
    0x46u, 0x3Fu, 0x42u, 0x47u, 0x0Du, 0x19u, 0x8Eu, 0x00u
};
