/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA64B_native_opcode_34;
    u8 body_3AA64C_native_opcode_47;
    u8 body_3AA64D_target_adjust_opcode_0D;
    u8 body_3AA64E_native_opcode_3F;
    u8 body_3AA64F_native_opcode_38;
    u8 body_3AA650_native_opcode_34;
    u8 body_3AA651_native_opcode_46;
    u8 body_3AA652_native_opcode_47;
    u8 body_3AA653_target_adjust_opcode_0D;
    u8 body_3AA654_native_opcode_15;
    u8 body_3AA655_native_opcode_17;
    u8 body_3AA656_native_opcode_24;
    u8 body_3AA657_native_opcode_1B;
    u8 body_3AA658_target_adjust_opcode_0D;
    u8 body_3AA659_native_opcode_42;
    u8 body_3AA65A_native_opcode_39;
    u8 body_3AA65B_target_adjust_opcode_0D;
    u8 body_3AA65C_native_opcode_39;
    u8 body_3AA65D_native_opcode_45;
    u8 body_3AA65E_native_opcode_38;
    u8 body_3AA65F_native_opcode_38;
    u8 body_3AA660_opcode_04;
    u8 body_3AA660_opcode_04_payload;
    u8 body_3AA662_opcode_01;
    u8 body_3AA662_be16_high;
    u8 body_3AA662_be16_low;
} EffectTimelineRun_004AA64B;
EffectTimelineRun_004AA64B data_effect_timeline_004AA64B = {
    0x34u, 0x47u, 0x0Du, 0x3Fu, 0x38u, 0x34u, 0x46u, 0x47u, 0x0Du, 0x15u, 0x17u, 0x24u, 0x1Bu, 0x0Du, 0x42u, 0x39u, 0x0Du, 0x39u, 0x45u, 0x38u, 0x38u, 0x04u, 0x00u, 0x01u, 0x00u, 0x7Fu
};
