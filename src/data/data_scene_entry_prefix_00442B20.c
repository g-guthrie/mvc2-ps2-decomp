typedef unsigned short u16;
#pragma pack(1)
typedef struct { float x, y, z; u16 actor_field_CC; } SceneEntryPrefix;
#pragma pack()
typedef char SceneEntryPrefix_size_must_be_14[(sizeof(SceneEntryPrefix) == 14) ? 1 : -1];
const SceneEntryPrefix data_scene_entry_prefix_00442B20 = { 0.0f, 0.0f, 0.019999999552965164f, 0x008Cu };
