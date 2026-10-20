/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3A9FC5_native_opcode_3C;
    u8 body_3A9FC6_native_opcode_46;
    u8 body_3A9FC7_target_adjust_opcode_0D;
    u8 body_3A9FC8_native_opcode_48;
    u8 body_3A9FC9_native_opcode_41;
    u8 body_3A9FCA_native_opcode_39;
    u8 body_3A9FCB_native_opcode_42;
    u8 body_3A9FCC_native_opcode_45;
    u8 body_3A9FCD_native_opcode_40;
    u8 body_3A9FCE_native_opcode_34;
    u8 body_3A9FCF_native_opcode_47;
    u8 body_3A9FD0_native_opcode_47;
    u8 body_3A9FD1_native_opcode_38;
    u8 body_3A9FD2_native_opcode_37;
    u8 body_3A9FD3_native_opcode_8E;
    u8 body_3A9FD4_terminator_opcode;
} EffectTimelineRun_004A9FC5;
EffectTimelineRun_004A9FC5 data_effect_timeline_004A9FC5 = {
    0x3Cu, 0x46u, 0x0Du, 0x48u, 0x41u, 0x39u, 0x42u, 0x45u, 0x40u, 0x34u, 0x47u, 0x47u, 0x38u, 0x37u, 0x8Eu, 0x00u
};
