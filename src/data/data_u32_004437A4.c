typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; u32 id; u32 pad[3]; } D004437A4_Rec;
typedef char D004437A4_Rec_size_check[(sizeof(D004437A4_Rec) == 28) ? 1 : -1];
typedef struct { u32 head[4]; D004437A4_Rec rec[2]; } D004437A4_Table;
typedef char D004437A4_Table_size_check[(sizeof(D004437A4_Table) == 72) ? 1 : -1];
D004437A4_Table data_u32_004437A4 = {
    { 0x01000004u, 0x00000000u, 0x00000000u, 0x00000000u },
    {
        { 1.0f, 0.200000003f, 0.200000003f, 2u, { 0u, 0u, 0u } },
        { 1.0f, 0.200000003f, 0.200000003f, 6u, { 0u, 0u, 0u } },
    }
};
