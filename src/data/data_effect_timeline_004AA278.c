/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA278_native_opcode_42;
    u8 body_3AA279_native_opcode_41;
    u8 body_3AA27A_target_adjust_opcode_0D;
    u8 body_3AA27B_native_opcode_40;
    u8 body_3AA27C_native_opcode_38;
    u8 body_3AA27D_native_opcode_40;
    u8 body_3AA27E_native_opcode_42;
    u8 body_3AA27F_native_opcode_45;
    u8 body_3AA280_native_opcode_4C;
    u8 body_3AA281_target_adjust_opcode_0D;
    u8 body_3AA282_native_opcode_36;
    u8 body_3AA283_native_opcode_34;
    u8 body_3AA284_native_opcode_45;
    u8 body_3AA285_native_opcode_37;
    u8 body_3AA286_target_adjust_opcode_0D;
    u8 body_3AA287_native_opcode_93;
    u8 body_3AA288_native_opcode_29;
    u8 body_3AA289_native_opcode_2C;
    u8 body_3AA28A_native_opcode_12;
    u8 body_3AA28B_native_opcode_94;
    u8 body_3AA28C_target_adjust_opcode_0D;
    u8 body_3AA28D_native_opcode_3C;
    u8 body_3AA28E_native_opcode_41;
    u8 body_3AA28F_opcode_04;
    u8 body_3AA28F_opcode_04_payload;
    u8 body_3AA291_opcode_01;
    u8 body_3AA291_be16_high;
    u8 body_3AA291_be16_low;
} EffectTimelineRun_004AA278;
EffectTimelineRun_004AA278 data_effect_timeline_004AA278 = {
    0x42u, 0x41u, 0x0Du, 0x40u, 0x38u, 0x40u, 0x42u, 0x45u, 0x4Cu, 0x0Du, 0x36u, 0x34u, 0x45u, 0x37u, 0x0Du, 0x93u, 0x29u, 0x2Cu, 0x12u, 0x94u, 0x0Du, 0x3Cu, 0x41u, 0x04u, 0x00u, 0x01u, 0x00u, 0x9Fu
};
