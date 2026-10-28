typedef float f32;

/* Twelve selector rows of three float3 keys each. func_00140020 (0x00140020)
 * builds the base pointer from %hi/%lo(D_00440AD0) at 0x001400B0-B8 and
 * indexes it by selector * 36 (0x001400A0-A8, 0x001400C0), loading three f32
 * components at +0/+4/+8 (lwc1 0x001400D8-E0). func_00140110 (0x00140110)
 * reaches the same table at 0x0014014C/0x0014015C with index (key + 3 * row) *
 * 12, reading key and key + 1 of the row as float3 (lwc1 +0/+4/+8). No
 * code reads this span by any other address. */
typedef struct {
    f32 x, y, z;
} Data00440AD0Key;
typedef struct {
    Data00440AD0Key key[3];
} Data00440AD0Row;
typedef char data_rec_00440AD0_size_check[(sizeof(Data00440AD0Row) == 36) ? 1 : -1];

Data00440AD0Row data_rec_00440AD0[12] = {
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
    { { { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 10.0f }, { 1.0f, 1.0f, 1.0f } } },
};
