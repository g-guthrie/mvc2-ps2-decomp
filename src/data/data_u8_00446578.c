typedef unsigned int u32;
typedef float f32;
typedef struct { f32 f0; u32 w1; f32 f2; f32 f3; } Rec16;
typedef struct { f32 f0; u32 w1; } Rec8;
typedef struct {
    Rec16 recs[4];
    Rec8 tail;
} Data00446578;
typedef char Data00446578_size_check[(sizeof(Data00446578) == 72) ? 1 : -1];
Data00446578 data_u8_00446578 = {
    { { 0.99000001f, 0xFFFFFFFFu, 112.0f, 64.0f }, { 0.980000019f, 0xFF0000EEu, 528.0f, 64.0f }, { 0.980000019f, 0xFF0000EEu, 112.0f, 416.0f }, { 0.980000019f, 0xFF00B4FFu, 528.0f, 416.0f } },
    { 0.980000019f, 0xFF00B4FFu }
};
