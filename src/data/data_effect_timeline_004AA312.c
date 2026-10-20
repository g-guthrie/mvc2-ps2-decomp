/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA312_native_opcode_32;
    u8 body_3AA313_native_opcode_38;
    u8 body_3AA314_native_opcode_46;
    u8 body_3AA315_target_adjust_opcode_05;
    u8 body_3AA316_target_adjust_opcode_05;
    u8 body_3AA317_native_opcode_27;
    u8 body_3AA318_native_opcode_42;
    u8 body_3AA319_terminator_opcode;
} EffectTimelineRun_004AA312;
EffectTimelineRun_004AA312 data_effect_timeline_004AA312 = {
    0x32u, 0x38u, 0x46u, 0x05u, 0x05u, 0x27u, 0x42u, 0x00u
};
