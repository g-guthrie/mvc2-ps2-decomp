/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA2F7_native_opcode_4C;
    u8 body_3AA2F8_native_opcode_42;
    u8 body_3AA2F9_native_opcode_48;
    u8 body_3AA2FA_target_adjust_opcode_0D;
    u8 body_3AA2FB_native_opcode_46;
    u8 body_3AA2FC_native_opcode_47;
    u8 body_3AA2FD_native_opcode_34;
    u8 body_3AA2FE_native_opcode_45;
    u8 body_3AA2FF_native_opcode_47;
    u8 body_3AA300_target_adjust_opcode_0D;
    u8 body_3AA301_native_opcode_47;
    u8 body_3AA302_native_opcode_3B;
    u8 body_3AA303_native_opcode_38;
    u8 body_3AA304_target_adjust_opcode_0D;
    u8 body_3AA305_native_opcode_3A;
    u8 body_3AA306_native_opcode_34;
    u8 body_3AA307_native_opcode_40;
    u8 body_3AA308_native_opcode_38;
    u8 body_3AA309_native_opcode_8F;
    u8 body_3AA30A_opcode_04;
    u8 body_3AA30A_opcode_04_payload;
    u8 body_3AA30C_opcode_01;
    u8 body_3AA30C_be16_high;
    u8 body_3AA30C_be16_low;
} EffectTimelineRun_004AA2F7;
EffectTimelineRun_004AA2F7 data_effect_timeline_004AA2F7 = {
    0x4Cu, 0x42u, 0x48u, 0x0Du, 0x46u, 0x47u, 0x34u, 0x45u, 0x47u, 0x0Du, 0x47u, 0x3Bu, 0x38u, 0x0Du, 0x3Au, 0x34u, 0x40u, 0x38u, 0x8Fu, 0x04u, 0x18u, 0x01u, 0x01u, 0x00u
};
