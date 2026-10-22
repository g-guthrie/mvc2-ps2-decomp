typedef unsigned int u32;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x; f32 y; u16 a; u16 b; f32 p; f32 q; } D0044E1C0_Rec;
typedef char D0044E1C0_Rec_size_check[(sizeof(D0044E1C0_Rec) == 20) ? 1 : -1];
typedef struct { D0044E1C0_Rec rec[4]; f32 tail_x; f32 tail_y; u32 tail_z; } D0044E1C0_Table;
typedef char D0044E1C0_Table_size_check[(sizeof(D0044E1C0_Table) == 92) ? 1 : -1];
D0044E1C0_Table data_u32_0044E1C0 = {
    {
        { 453.333313f, 175.714279f, 1u, 5u, 1.0f, 0.600000024f },
        { 453.333313f, 175.714279f, 1u, 5u, 1.0f, 0.300000012f },
        { 453.333313f, 175.714279f, 1u, 5u, 4.0999999f, 1.5f },
        { 506.666656f, 175.714279f, 1u, 5u, 4.0999999f, 1.0f },
    },
    506.666656f, 175.714279f, 0u
};
