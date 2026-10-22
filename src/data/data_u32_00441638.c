typedef short s16;
typedef struct { s16 x; s16 y; float a; float b; } data_u32_00441638_entry_t;
typedef struct { float c; float d; s16 e; s16 f; } data_u32_00441638_tail_t;
typedef struct { data_u32_00441638_entry_t entries[5]; data_u32_00441638_tail_t tail; } data_u32_00441638_t;
typedef char data_u32_00441638_t_size_check[(sizeof(data_u32_00441638_t) == 72) ? 1 : -1];

data_u32_00441638_t data_u32_00441638[1] = {
    {
        { { 260, 870, 2.0f, 1.0f }, { 320, 1050, 3.0f, 1.0f }, { 380, 1230, 6.0f, 6.0f }, { -1, -630, 3.0f, 3.0f }, { 0, 0, 0.0f, 0.0f } },
        { 3.0f, 1.0f, 60, 180 },
    },
};
