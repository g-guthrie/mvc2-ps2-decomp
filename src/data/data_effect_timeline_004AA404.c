/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 body_3AA404_native_opcode_39;
    u8 body_3AA405_native_opcode_42;
    u8 body_3AA406_native_opcode_48;
    u8 body_3AA407_native_opcode_41;
    u8 body_3AA408_native_opcode_37;
    u8 body_3AA409_target_adjust_opcode_0D;
    u8 body_3AA40A_native_opcode_3C;
    u8 body_3AA40B_native_opcode_41;
    u8 body_3AA40C_target_adjust_opcode_0D;
    u8 body_3AA40D_native_opcode_66;
    u8 body_3AA40E_native_opcode_5E;
    u8 body_3AA40F_native_opcode_66;
    u8 body_3AA410_native_opcode_68;
    u8 body_3AA411_native_opcode_6B;
    u8 body_3AA412_native_opcode_72;
    u8 body_3AA413_target_adjust_opcode_0D;
    u8 body_3AA414_native_opcode_5C;
    u8 body_3AA415_native_opcode_5A;
    u8 body_3AA416_native_opcode_6B;
    u8 body_3AA417_native_opcode_5D;
    u8 body_3AA418_opcode_04;
    u8 body_3AA418_opcode_04_payload;
    u8 body_3AA41A_opcode_01;
    u8 body_3AA41A_be16_high;
    u8 body_3AA41A_be16_low;
} EffectTimelineRun_004AA404;
EffectTimelineRun_004AA404 data_effect_timeline_004AA404 = {
    0x39u, 0x42u, 0x48u, 0x41u, 0x37u, 0x0Du, 0x3Cu, 0x41u, 0x0Du, 0x66u, 0x5Eu, 0x66u, 0x68u, 0x6Bu, 0x72u, 0x0Du, 0x5Cu, 0x5Au, 0x6Bu, 0x5Du, 0x04u, 0x00u, 0x01u, 0x01u, 0x0Bu
};
