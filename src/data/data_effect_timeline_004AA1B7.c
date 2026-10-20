/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA1B7_native_opcode_26;
    u8 body_3AA1B8_native_opcode_1E;
    u8 body_3AA1B9_native_opcode_26;
    u8 body_3AA1BA_native_opcode_28;
    u8 body_3AA1BB_native_opcode_2B;
    u8 body_3AA1BC_native_opcode_32;
    u8 body_3AA1BD_target_adjust_opcode_0D;
    u8 body_3AA1BE_native_opcode_1C;
    u8 body_3AA1BF_native_opcode_1A;
    u8 body_3AA1C0_native_opcode_2B;
    u8 body_3AA1C1_native_opcode_1D;
    u8 body_3AA1C2_target_adjust_opcode_0D;
    u8 body_3AA1C3_native_opcode_46;
    u8 body_3AA1C4_native_opcode_3F;
    u8 body_3AA1C5_native_opcode_42;
    u8 body_3AA1C6_native_opcode_47;
    u8 body_3AA1C7_target_adjust_opcode_0D;
    u8 body_3AA1C8_native_opcode_19;
    u8 body_3AA1C9_native_opcode_8E;
    u8 body_3AA1CA_target_adjust_opcode_0D;
    u8 body_3AA1CB_native_opcode_1A;
    u8 body_3AA1CC_native_opcode_47;
    u8 body_3AA1CD_opcode_04;
    u8 body_3AA1CD_opcode_04_payload;
    u8 body_3AA1CF_opcode_01;
    u8 body_3AA1CF_be16_high;
    u8 body_3AA1CF_be16_low;
} EffectTimelineRun_004AA1B7;
EffectTimelineRun_004AA1B7 data_effect_timeline_004AA1B7 = {
    0x26u, 0x1Eu, 0x26u, 0x28u, 0x2Bu, 0x32u, 0x0Du, 0x1Cu, 0x1Au, 0x2Bu, 0x1Du, 0x0Du, 0x46u, 0x3Fu, 0x42u, 0x47u, 0x0Du, 0x19u, 0x8Eu, 0x0Du, 0x1Au, 0x47u, 0x04u, 0x00u, 0x01u, 0x00u, 0x90u
};
