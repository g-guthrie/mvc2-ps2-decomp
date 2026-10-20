/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA95A_native_opcode_32;
    u8 body_3AA95B_native_opcode_38;
    u8 body_3AA95C_native_opcode_46;
    u8 body_3AA95D_target_adjust_opcode_05;
    u8 body_3AA95E_target_adjust_opcode_05;
    u8 body_3AA95F_native_opcode_27;
    u8 body_3AA960_native_opcode_42;
    u8 body_3AA961_terminator_opcode;
} EffectTimelineRun_004AA95A;
EffectTimelineRun_004AA95A data_effect_timeline_004AA95A = {
    0x32u, 0x38u, 0x46u, 0x05u, 0x05u, 0x27u, 0x42u, 0x00u
};
