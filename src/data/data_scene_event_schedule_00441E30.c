#define offsetof(type, member) ((unsigned int)&(((type *)0)->member))
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;
typedef struct {
    s16 frame;
    u8 action_code;
    u8 category_code;
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    const void *resource;
    u8 pool_index;
    u8 object_field_24;
} SceneEventScheduleRecord;
typedef char check_record_size[(sizeof(SceneEventScheduleRecord) == 0x1C) ? 1 : -1];
typedef char check_pool_offset[(offsetof(SceneEventScheduleRecord, pool_index) == 0x18) ? 1 : -1];
typedef char check_object24_offset[(offsetof(SceneEventScheduleRecord, object_field_24) == 0x19) ? 1 : -1];
extern u8 data_raw_00441CD4[];
extern u32 data_u32_0044138C[];
extern u32 data_u32_004414B0[];
extern u32 data_u32_00441544[];
extern u32 data_u32_00441638[];
extern u32 data_u32_00441724[];
extern u32 data_u32_004418D8[];
extern u32 data_u32_00441920[];
extern u32 data_u32_00441970[];
extern u32 data_u32_004419C0[];
extern u32 data_u32_00441A10[];
extern u32 data_u32_00441AF8[];
extern u32 data_u32_00441B28[];
extern u32 data_u32_00441C48[];
SceneEventScheduleRecord data_scene_event_schedule_00441E30[63] = {
    { 0, 0x2E, 0x01, 0.0f, 0.0f, 0.0f, -10.0f, (data_raw_00441CD4 + 0xFC), 0x01, 0x00 },
    { 0, 0x30, 0x01, 0.0f, 0.0f, 0.0f, -10.0f, (data_raw_00441CD4 + 0x12C), 0x02, 0x00 },
    { 110, 0x00, 0x00, 1.0f, 0.0f, 0.0f, -15.1000004f, 0, 0x00, 0x09 },
    { 110, 0x01, 0x01, 1.0f, 0.0f, 0.0f, -4.0f, ((const u8 *)data_u32_0044138C + 0x4), 0x01, 0x09 },
    { 110, 0x03, 0x00, 1.0f, 0.0f, 0.0f, -15.0f, 0, 0x02, 0x09 },
    { 110, 0x04, 0x02, 1.0f, 0.0f, 0.0f, -15.0f, ((const u8 *)data_u32_0044138C + 0x84), 0x03, 0x00 },
    { 110, 0x05, 0x02, 1.0f, 0.0f, 0.0f, -15.0f, ((const u8 *)data_u32_0044138C + 0x94), 0x04, 0x00 },
    { 110, 0x06, 0x06, 1.0f, 0.0f, 0.0f, -15.0200005f, ((const u8 *)data_u32_0044138C + 0xA4), 0x05, 0x04 },
    { 110, 0x07, 0x06, 1.0f, 0.0f, 0.0f, -15.04f, ((const u8 *)data_u32_004414B0 + 0x40), 0x06, 0x03 },
    { 110, 0x08, 0x06, 1.0f, 0.0f, 0.0f, -15.0299997f, ((const u8 *)data_u32_00441544 + 0x5C), 0x07, 0x02 },
    { 110, 0x09, 0x06, 1.0f, 0.0f, 0.0f, -15.0500002f, ((const u8 *)data_u32_00441638 + 0x38), 0x08, 0x01 },
    { 318, 0x0A, 0x02, 0.0f, 0.0f, 0.0f, -14.8000002f, ((const u8 *)data_u32_00441724 + 0x4C), 0x09, 0x05 },
    { 338, 0x0B, 0x02, 0.0f, 0.0f, 0.0f, -14.8000002f, ((const u8 *)data_u32_00441724 + 0x4C), 0x0A, 0x06 },
    { 358, 0x0C, 0x02, 0.0f, 0.0f, 0.0f, -14.8000002f, ((const u8 *)data_u32_00441724 + 0x4C), 0x0B, 0x07 },
    { 398, 0x0D, 0x02, 0.0f, 0.0f, 0.0f, -14.8000002f, ((const u8 *)data_u32_00441724 + 0x5C), 0x0C, 0x08 },
    { 453, 0x0E, 0x03, 1.0f, 7.0f, 0.5f, -14.0f, ((const u8 *)data_u32_00441724 + 0x6C), 0x09, 0x09 },
    { 453, 0x10, 0x03, 1.0f, 10.0f, -0.5f, -14.0f, ((const u8 *)data_u32_00441724 + 0xAC), 0x0A, 0x0A },
    { 483, 0x21, 0x01, 1.0f, 13.0f, 0.0f, -14.8000002f, ((const u8 *)data_u32_00441724 + 0xEC), 0x0B, 0x00 },
    { 503, 0x1F, 0x01, 0.0f, 9.0f, -2.0f, -12.0f, ((const u8 *)data_u32_00441724 + 0x13C), 0x09, 0x00 },
    { 513, 0x23, 0x05, 1.0f, 25.0f, -3.0f, -12.0f, ((const u8 *)data_u32_00441724 + 0x16C), 0x0A, 0x0A },
    { 563, 0x32, 0x00, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0x23, 0x09 },
    { 563, 0x34, 0x00, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0x24, 0x0A },
    { 852, 0x12, 0x05, 1.0f, 13.0f, 4.5f, -14.0f, ((const u8 *)data_u32_004418D8 + 0x18), 0x09, 0x05 },
    { 860, 0x2B, 0x00, 1.10000002f, 7.5f, 3.0f, -13.9899998f, 0, 0x1F, 0x0A },
    { 867, 0x13, 0x05, 1.0f, 13.0f, 1.5f, -14.0f, ((const u8 *)data_u32_00441920 + 0x20), 0x0A, 0x05 },
    { 867, 0x1D, 0x04, 1.0f, 4.75f, 3.0f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x48), 0x14, 0x0A },
    { 875, 0x2B, 0x00, 1.10000002f, 7.5f, 1.0f, -13.9899998f, 0, 0x20, 0x0A },
    { 882, 0x14, 0x05, 1.0f, 13.0f, -1.5f, -14.0f, ((const u8 *)data_u32_00441970 + 0x20), 0x0B, 0x05 },
    { 882, 0x1D, 0x04, 1.0f, 4.75f, 1.0f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x18), 0x15, 0x0A },
    { 890, 0x2B, 0x00, 1.10000002f, 7.5f, -1.0f, -13.9899998f, 0, 0x21, 0x0A },
    { 897, 0x15, 0x05, 1.0f, 13.0f, -4.5f, -14.0f, ((const u8 *)data_u32_004419C0 + 0x20), 0x0C, 0x05 },
    { 897, 0x1D, 0x04, 1.0f, 4.75f, -1.0f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x18), 0x16, 0x0A },
    { 905, 0x2B, 0x00, 1.10000002f, 7.5f, -3.0f, -13.9899998f, 0, 0x22, 0x0A },
    { 912, 0x1D, 0x04, 1.0f, 4.75f, -3.0f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x48), 0x17, 0x0A },
    { 938, 0x2F, 0x05, 1.0f, 1.0f, 1.0f, 1.0f, (data_raw_00441CD4 + 0x9C), 0x11, 0x0A },
    { 970, 0x22, 0x01, 1.0f, 9.47999954f, 0.0f, -10.0f, ((const u8 *)data_u32_00441A10 + 0x20), 0x0D, 0x00 },
    { 980, 0x20, 0x01, 0.0f, 0.0f, -2.0f, -6.0f, ((const u8 *)data_u32_00441A10 + 0x60), 0x0E, 0x00 },
    { 1000, 0x25, 0x05, 1.0f, -35.7999992f, -3.5f, -13.0f, ((const u8 *)data_u32_00441A10 + 0xA0), 0x0F, 0x0A },
    { 1327, 0x16, 0x04, 1.0f, 4.5f, -4.80000019f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x0D, 0x09 },
    { 1342, 0x17, 0x04, 1.0f, -6.0f, -5.5f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x0E, 0x09 },
    { 1342, 0x18, 0x04, 1.0f, 6.0f, -6.5f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x0F, 0x09 },
    { 1343, 0x2B, 0x00, 1.10000002f, 4.5f, -4.80000019f, -13.9899998f, 0, 0x1F, 0x0A },
    { 1357, 0x19, 0x04, 1.0f, -7.0f, -2.5f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x10, 0x09 },
    { 1357, 0x1A, 0x04, 1.0f, 6.0f, -8.0f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x11, 0x09 },
    { 1358, 0x2B, 0x00, 1.10000002f, -6.0f, -5.5f, -13.9899998f, 0, 0x20, 0x0A },
    { 1358, 0x2B, 0x00, 1.10000002f, 6.0f, -6.5f, -13.9899998f, 0, 0x22, 0x0A },
    { 1372, 0x1B, 0x04, 1.0f, -8.0f, 0.5f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x12, 0x09 },
    { 1372, 0x1C, 0x04, 1.0f, 6.0f, -9.5f, -14.0f, ((const u8 *)data_u32_00441AF8 + 0x18), 0x13, 0x09 },
    { 1373, 0x2B, 0x00, 1.10000002f, -7.0f, -2.5f, -13.9899998f, 0, 0x22, 0x0A },
    { 1373, 0x2B, 0x00, 1.10000002f, 6.0f, -8.0f, -13.9899998f, 0, 0x21, 0x0A },
    { 1377, 0x1D, 0x04, 1.0f, -5.25f, 0.5f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x48), 0x18, 0x0A },
    { 1377, 0x1E, 0x04, 1.0f, 3.52999997f, -9.5f, -13.9300003f, ((const u8 *)data_u32_00441B28 + 0xA8), 0x19, 0x0A },
    { 1388, 0x2B, 0x00, 1.10000002f, -8.0f, 0.5f, -13.9899998f, 0, 0x20, 0x0A },
    { 1388, 0x2B, 0x00, 1.10000002f, 6.0f, -9.5f, -13.9899998f, 0, 0x22, 0x0A },
    { 1392, 0x1D, 0x04, 1.0f, -3.25f, -5.5f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x78), 0x1A, 0x0A },
    { 1392, 0x1E, 0x04, 1.0f, 3.52999997f, -8.0f, -13.9200001f, ((const u8 *)data_u32_00441B28 + 0xA8), 0x1B, 0x0A },
    { 1392, 0x1E, 0x04, 1.0f, 2.45000005f, -9.57999992f, -13.9200001f, ((const u8 *)data_u32_00441B28 + 0x108), 0x1C, 0x0A },
    { 1407, 0x1D, 0x04, 1.0f, -4.25f, -2.5f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x18), 0x1D, 0x0A },
    { 1407, 0x1E, 0x04, 1.0f, 3.52999997f, -6.5f, -13.9099998f, ((const u8 *)data_u32_00441B28 + 0xD8), 0x1E, 0x0A },
    { 1417, 0x1D, 0x04, 1.0f, 1.75f, -4.80000019f, -13.9499998f, ((const u8 *)data_u32_00441B28 + 0x18), 0x1F, 0x0A },
    { 1547, 0x28, 0x05, 0.0f, 0.0f, 0.0f, -13.0f, (data_raw_00441CD4 + 0xC), 0x20, 0x0D },
    { 1547, 0x27, 0x07, 0.0f, 0.0f, 0.0f, -13.0f, ((const u8 *)data_u32_00441C48 + 0x18), 0x21, 0x0C },
    { 1627, 0x2D, 0x00, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0x22, 0x00 },
};
