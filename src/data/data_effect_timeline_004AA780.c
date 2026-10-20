/* Native-read effect fields; variable records retain BE bytes and opaque skips. */
typedef unsigned char u8;
typedef struct {
    u8 record_count;
    u8 record_base_byte;
    u8 preamble_3AA782_opcode_0B;
    u8 preamble_3AA782_payload_u8;
    u8 preamble_3AA784_opcode_0C;
} EffectTimelineRun_004AA780;
EffectTimelineRun_004AA780 data_effect_timeline_004AA780 = {
    0x01u, 0x00u, 0x0Bu, 0x00u, 0x0Cu
};
