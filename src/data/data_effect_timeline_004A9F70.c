/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 record_count;
    u8 record_base_byte;
    u8 preamble_3A9F72_opcode_0B;
    u8 preamble_3A9F72_payload_u8;
    u8 preamble_3A9F74_opcode_0C;
} EffectTimelineRun_004A9F70;
EffectTimelineRun_004A9F70 data_effect_timeline_004A9F70 = {
    0x01u, 0x00u, 0x0Bu, 0x00u, 0x0Cu
};
