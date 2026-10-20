/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA392_native_opcode_39;
    u8 body_3AA393_native_opcode_42;
    u8 body_3AA394_native_opcode_45;
    u8 body_3AA395_native_opcode_40;
    u8 body_3AA396_native_opcode_34;
    u8 body_3AA397_native_opcode_47;
    u8 body_3AA398_target_adjust_opcode_0D;
    u8 body_3AA399_native_opcode_3C;
    u8 body_3AA39A_native_opcode_47;
    u8 body_3AA39B_native_opcode_8F;
    u8 body_3AA39C_opcode_04;
    u8 body_3AA39C_opcode_04_payload;
    u8 body_3AA39E_opcode_01;
    u8 body_3AA39E_be16_high;
    u8 body_3AA39E_be16_low;
} EffectTimelineRun_004AA392;
EffectTimelineRun_004AA392 data_effect_timeline_004AA392 = {
    0x39u, 0x42u, 0x45u, 0x40u, 0x34u, 0x47u, 0x0Du, 0x3Cu, 0x47u, 0x8Fu, 0x04u, 0x18u, 0x01u, 0x01u, 0x00u
};
