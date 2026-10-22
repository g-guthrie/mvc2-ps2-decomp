typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; u32 id; u32 pad[3]; } D00443644_Rec;
typedef char D00443644_Rec_size_check[(sizeof(D00443644_Rec) == 28) ? 1 : -1];
typedef struct { u32 head[4]; D00443644_Rec rec[2]; } D00443644_Table;
typedef char D00443644_Table_size_check[(sizeof(D00443644_Table) == 72) ? 1 : -1];
D00443644_Table data_u32_00443644 = {
    { 0x01000080u, 0x00000000u, 0x00000000u, 0x00000000u },
    {
        { 0.879999995f, 0.270000011f, 0.899999976f, 81u, { 0u, 0u, 0u } },
        { 0.790000021f, 0.180000007f, 0.810000002f, 82u, { 0u, 0u, 0u } },
    }
};
