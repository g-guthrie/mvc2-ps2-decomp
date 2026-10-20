/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA8D8_native_opcode_42;
    u8 body_3AA8D9_native_opcode_41;
    u8 body_3AA8DA_target_adjust_opcode_0D;
    u8 body_3AA8DB_native_opcode_40;
    u8 body_3AA8DC_native_opcode_38;
    u8 body_3AA8DD_native_opcode_40;
    u8 body_3AA8DE_native_opcode_42;
    u8 body_3AA8DF_native_opcode_45;
    u8 body_3AA8E0_native_opcode_4C;
    u8 body_3AA8E1_target_adjust_opcode_0D;
    u8 body_3AA8E2_native_opcode_36;
    u8 body_3AA8E3_native_opcode_34;
    u8 body_3AA8E4_native_opcode_45;
    u8 body_3AA8E5_native_opcode_37;
    u8 body_3AA8E6_target_adjust_opcode_0D;
    u8 body_3AA8E7_native_opcode_93;
    u8 body_3AA8E8_native_opcode_29;
    u8 body_3AA8E9_native_opcode_2C;
    u8 body_3AA8EA_native_opcode_12;
    u8 body_3AA8EB_native_opcode_94;
    u8 body_3AA8EC_native_opcode_8E;
    u8 body_3AA8ED_opcode_04;
    u8 body_3AA8ED_opcode_04_payload;
    u8 body_3AA8EF_opcode_01;
    u8 body_3AA8EF_be16_high;
    u8 body_3AA8EF_be16_low;
} EffectTimelineRun_004AA8D8;
EffectTimelineRun_004AA8D8 data_effect_timeline_004AA8D8 = {
    0x42u, 0x41u, 0x0Du, 0x40u, 0x38u, 0x40u, 0x42u, 0x45u, 0x4Cu, 0x0Du, 0x36u, 0x34u, 0x45u, 0x37u, 0x0Du, 0x93u, 0x29u, 0x2Cu, 0x12u, 0x94u, 0x8Eu, 0x04u, 0x00u, 0x01u, 0x00u, 0x7Cu
};
