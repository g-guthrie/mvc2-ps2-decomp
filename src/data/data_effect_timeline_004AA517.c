/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 preamble_3AA517_opcode_05;
    u8 preamble_3AA517_saved_value;
    u8 preamble_3AA519_opcode_06;
    u8 preamble_3AA519_payload_u8;
    u8 preamble_3AA51B_opcode_07;
    u8 preamble_3AA51B_payload_u8;
    u8 preamble_3AA51D_opcode_08;
    u8 preamble_3AA51D_payload_u8;
    u8 preamble_3AA51F_opcode_09;
    u8 preamble_3AA51F_payload_u8;
    u8 preamble_3AA521_opcode_01;
    u8 preamble_3AA521_be16_a_high;
    u8 preamble_3AA521_be16_a_low;
    u8 preamble_3AA521_be16_b_high;
    u8 preamble_3AA521_be16_b_low;
    u8 preamble_3AA521_native_read_u8;
    u8 body_3AA527_native_opcode_2C;
    u8 body_3AA528_native_opcode_34;
    u8 body_3AA529_native_opcode_49;
    u8 body_3AA52A_native_opcode_38;
    u8 body_3AA52B_target_adjust_opcode_0D;
    u8 body_3AA52C_native_opcode_46;
    u8 body_3AA52D_native_opcode_48;
    u8 body_3AA52E_native_opcode_36;
    u8 body_3AA52F_native_opcode_36;
    u8 body_3AA530_native_opcode_38;
    u8 body_3AA531_native_opcode_46;
    u8 body_3AA532_native_opcode_46;
    u8 body_3AA533_native_opcode_39;
    u8 body_3AA534_native_opcode_48;
    u8 body_3AA535_native_opcode_3F;
    u8 body_3AA536_native_opcode_8E;
    u8 body_3AA537_terminator_opcode;
} EffectTimelineRun_004AA517;
EffectTimelineRun_004AA517 data_effect_timeline_004AA517 = {
    0x05u, 0x18u, 0x06u, 0xFFu, 0x07u, 0xFFu, 0x08u, 0xFFu, 0x09u, 0xFFu, 0x01u, 0x00u, 0xC3u, 0x00u, 0xD0u, 0x80u, 0x2Cu, 0x34u, 0x49u, 0x38u, 0x0Du, 0x46u, 0x48u, 0x36u, 0x36u, 0x38u, 0x46u, 0x46u, 0x39u, 0x48u, 0x3Fu, 0x8Eu, 0x00u
};
