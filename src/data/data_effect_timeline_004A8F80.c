/* Native-read effect fields, bounded by the next callback root. */
typedef unsigned char u8;
typedef struct {
    u8 record_count;
    u8 record_base_byte;
    u8 preamble_3A8F82_opcode_0B;
    u8 preamble_3A8F82_payload_u8;
    u8 preamble_3A8F84_opcode_0C;
} EffectTimelineRun_004A8F80;
EffectTimelineRun_004A8F80 data_effect_timeline_004A8F80 = {
    0x01u, 0x00u, 0x0Bu, 0x00u, 0x0Cu
};
