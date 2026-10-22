typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x; f32 y; u16 a; u16 b; f32 c; f32 d; } Rec20;
typedef struct { f32 x; f32 y; u16 a; u16 b; } Rec12;
typedef struct {
    Rec20 recs[4];
    Rec12 tail;
} Data0044E15C;
typedef char Data0044E15C_size_check[(sizeof(Data0044E15C) == 92) ? 1 : -1];
Data0044E15C data_u32_0044E15C = {
    { { 586.666626f, 175.714279f, 1, 1, 15.0f, 1.0f }, { 533.333313f, 171.428558f, 1, 1, 15.0f, 1.0f }, { 533.333313f, 171.428558f, 1, 1, 15.0f, 1.0f }, { 533.333313f, 171.428558f, 1, 3, 4.0f, 1.0f } },
    { 600.0f, 171.428558f, 1, 5 }
};
