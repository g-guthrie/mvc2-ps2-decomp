typedef unsigned int u32;
typedef float f32;

/* Selected through D_0043CB10[1] and D_0043CB30[1] by func_001234D0, which indexes
   the 24-byte records with D_004F1F49. Eight u32 header words, then eight records. */
typedef struct {
    u32 word0;
    f32 value0;
    f32 value1;
    u32 word3;
    f32 value2;
    u32 word5;
} Data43C370Entry;

typedef struct {
    u32 header[8];
    Data43C370Entry entries[8];
} Data43C370Table;

typedef char Data43C370Table_size_check[(sizeof(Data43C370Table) == 224) ? 1 : -1];
typedef char Data43C370Entry_size_check[(sizeof(Data43C370Entry) == 24) ? 1 : -1];

Data43C370Table data_u32_0043C370 = {
    { 0x00000007u, 0x00000064u, 0x0000000Fu, 0x0000001Eu, 0x0000000Fu, 0x0000000Cu, 0x0000000Fu, 0x00000012u },
    {
        { 0x00000000u, 1080.0f, 0.1f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 1080.0f, 0.1f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 530.0f, 0.1f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 484.45f, 170.1f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 360.0f, 294.54f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 190.0f, 340.1f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 95.0f, 812.3573f, 0x00000000u, 190.0f, 0x00000000u },
        { 0x00000000u, 95.0f, 812.3573f, 0x00000000u, 190.0f, 0x00000000u },
    },
};
