/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA082_native_opcode_39;
    u8 body_3AA083_native_opcode_42;
    u8 body_3AA084_native_opcode_45;
    u8 body_3AA085_native_opcode_40;
    u8 body_3AA086_native_opcode_34;
    u8 body_3AA087_native_opcode_47;
    u8 body_3AA088_target_adjust_opcode_0D;
    u8 body_3AA089_native_opcode_3C;
    u8 body_3AA08A_native_opcode_47;
    u8 body_3AA08B_native_opcode_8F;
    u8 body_3AA08C_opcode_04;
    u8 body_3AA08C_opcode_04_payload;
    u8 body_3AA08E_opcode_01;
    u8 body_3AA08E_be16_high;
    u8 body_3AA08E_be16_low;
} EffectTimelineRun_004AA082;
EffectTimelineRun_004AA082 data_effect_timeline_004AA082 = {
    0x39u, 0x42u, 0x45u, 0x40u, 0x34u, 0x47u, 0x0Du, 0x3Cu, 0x47u, 0x8Fu, 0x04u, 0x18u, 0x01u, 0x01u, 0x00u
};
