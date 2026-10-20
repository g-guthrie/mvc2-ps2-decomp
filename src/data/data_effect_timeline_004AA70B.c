/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA70B_native_opcode_34;
    u8 body_3AA70C_native_opcode_47;
    u8 body_3AA70D_target_adjust_opcode_0D;
    u8 body_3AA70E_native_opcode_3F;
    u8 body_3AA70F_native_opcode_38;
    u8 body_3AA710_native_opcode_34;
    u8 body_3AA711_native_opcode_46;
    u8 body_3AA712_native_opcode_47;
    u8 body_3AA713_target_adjust_opcode_0D;
    u8 body_3AA714_native_opcode_11;
    u8 body_3AA715_native_opcode_11;
    u8 body_3AA716_native_opcode_19;
    u8 body_3AA717_native_opcode_24;
    u8 body_3AA718_native_opcode_1B;
    u8 body_3AA719_target_adjust_opcode_0D;
    u8 body_3AA71A_native_opcode_42;
    u8 body_3AA71B_native_opcode_39;
    u8 body_3AA71C_target_adjust_opcode_0D;
    u8 body_3AA71D_native_opcode_39;
    u8 body_3AA71E_native_opcode_45;
    u8 body_3AA71F_native_opcode_38;
    u8 body_3AA720_native_opcode_38;
    u8 body_3AA721_opcode_04;
    u8 body_3AA721_opcode_04_payload;
    u8 body_3AA723_opcode_01;
    u8 body_3AA723_be16_high;
    u8 body_3AA723_be16_low;
} EffectTimelineRun_004AA70B;
EffectTimelineRun_004AA70B data_effect_timeline_004AA70B = {
    0x34u, 0x47u, 0x0Du, 0x3Fu, 0x38u, 0x34u, 0x46u, 0x47u, 0x0Du, 0x11u, 0x11u, 0x19u, 0x24u, 0x1Bu, 0x0Du, 0x42u, 0x39u, 0x0Du, 0x39u, 0x45u, 0x38u, 0x38u, 0x04u, 0x00u, 0x01u, 0x00u, 0x7Fu
};
