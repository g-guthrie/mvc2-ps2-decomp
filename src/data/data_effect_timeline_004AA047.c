/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA047_native_opcode_93;
    u8 body_3AA048_native_opcode_39;
    u8 body_3AA049_native_opcode_42;
    u8 body_3AA04A_native_opcode_45;
    u8 body_3AA04B_target_adjust_opcode_0D;
    u8 body_3AA04C_native_opcode_69;
    u8 body_3AA04D_native_opcode_7F;
    u8 body_3AA04E_native_opcode_74;
    u8 body_3AA04F_native_opcode_8C;
    u8 body_3AA050_native_opcode_6C;
    u8 body_3AA051_native_opcode_87;
    u8 body_3AA052_native_opcode_74;
    u8 body_3AA053_native_opcode_87;
    u8 body_3AA054_native_opcode_7C;
    u8 body_3AA055_native_opcode_82;
    u8 body_3AA056_native_opcode_81;
    u8 body_3AA057_native_opcode_9A;
    u8 body_3AA058_native_opcode_52;
    u8 body_3AA059_native_opcode_94;
    u8 body_3AA05A_target_adjust_opcode_0D;
    u8 body_3AA05B_native_opcode_3C;
    u8 body_3AA05C_native_opcode_46;
    u8 body_3AA05D_opcode_04;
    u8 body_3AA05D_opcode_04_payload;
    u8 body_3AA05F_opcode_01;
    u8 body_3AA05F_be16_high;
    u8 body_3AA05F_be16_low;
} EffectTimelineRun_004AA047;
EffectTimelineRun_004AA047 data_effect_timeline_004AA047 = {
    0x93u, 0x39u, 0x42u, 0x45u, 0x0Du, 0x69u, 0x7Fu, 0x74u, 0x8Cu, 0x6Cu, 0x87u, 0x74u, 0x87u, 0x7Cu, 0x82u, 0x81u, 0x9Au, 0x52u, 0x94u, 0x0Du, 0x3Cu, 0x46u, 0x04u, 0x00u, 0x01u, 0x00u, 0x9Fu
};
