/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 record_count;
    u8 record_base_byte;
    u8 preamble_3AA852_opcode_0B;
    u8 preamble_3AA852_payload_u8;
    u8 preamble_3AA854_opcode_0C;
} EffectTimelineRun_004AA850;
EffectTimelineRun_004AA850 data_effect_timeline_004AA850 = {
    0x01u, 0x00u, 0x0Bu, 0x00u, 0x0Cu
};
