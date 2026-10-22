typedef unsigned char u8;
typedef float f32;
typedef struct {
    f32 w;
    f32 h;
    f32 scale;
    u8 color[4];
} Tab00477288Rec;
typedef char Tab00477288Rec_size_check[(sizeof(Tab00477288Rec) == 16) ? 1 : -1];
typedef struct {
    f32 scale;
    u8 color[4];
    Tab00477288Rec records[16];
} Tab00477288;
typedef char Tab00477288_size_check[(sizeof(Tab00477288) == 264) ? 1 : -1];
Tab00477288 data_u8_00477288 = {
    0.97f,
    { 0xFFu, 0xB4u, 0x00u, 0xFFu },
    {
    { 3.2e+02f, 2.4e+02f, 0.96f, { 0x15u, 0xFFu, 0x00u, 0xFFu } },
    { 3.2e+02f, 2.4e+02f, 0.96f, { 0x15u, 0xFFu, 0x00u, 0xFFu } },
    { 3.2e+02f, 2.4e+02f, 0.96f, { 0x15u, 0xFFu, 0x00u, 0xFFu } },
    { 3.2e+02f, 2.4e+02f, 0.96f, { 0x15u, 0xFFu, 0x00u, 0xFFu } },
    { 0.0f, 0.0f, 0.8f, { 0xFFu, 0x00u, 0x00u, 0x80u } },
    { 6.4e+02f, 0.0f, 0.8f, { 0xFFu, 0x00u, 0x00u, 0x80u } },
    { 0.0f, 32.0f, 0.8f, { 0xFFu, 0x00u, 0x00u, 0x80u } },
    { 6.4e+02f, 32.0f, 0.8f, { 0xFFu, 0x00u, 0x00u, 0x80u } },
    { 0.0f, 0.0f, 0.8f, { 0x00u, 0x80u, 0x00u, 0x80u } },
    { 6.4e+02f, 0.0f, 0.8f, { 0x00u, 0x80u, 0x00u, 0x80u } },
    { 0.0f, 32.0f, 0.8f, { 0x00u, 0x80u, 0x00u, 0x80u } },
    { 6.4e+02f, 32.0f, 0.8f, { 0x00u, 0x80u, 0x00u, 0x80u } },
    { 4.3e+02f, 0.0f, 0.8f, { 0x00u, 0x00u, 0x00u, 0x80u } },
    { 6.4e+02f, 0.0f, 0.8f, { 0x00u, 0x00u, 0x00u, 0x80u } },
    { 4.3e+02f, 32.0f, 0.8f, { 0x00u, 0x00u, 0x00u, 0x80u } },
    { 6.4e+02f, 32.0f, 0.8f, { 0x00u, 0x00u, 0x00u, 0x80u } }
    }
};
