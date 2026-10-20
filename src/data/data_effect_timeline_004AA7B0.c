/* Native-read effect fields at 0x004AA7B0, bounded by the next callback root. */
typedef unsigned char u8;
typedef struct {
    u8 record_count;
    u8 record_base_byte;
    u8 preamble_3AA7B2_opcode_0B;
    u8 preamble_3AA7B2_payload_u8;
    u8 preamble_3AA7B4_opcode_0C;
} EffectTimelineRun_004AA7B0;
EffectTimelineRun_004AA7B0 data_effect_timeline_004AA7B0 = {
    0x01u, 0x00u, 0x0Bu, 0x00u, 0x0Cu
};
