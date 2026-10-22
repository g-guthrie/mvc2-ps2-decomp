typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    u32 w6;
    u32 w7;
    u32 w8;
    u32 w9;
    u32 w10;
    u32 w11;
} Data4C1920Table;

typedef char Data4C1920Table_size_check[(sizeof(Data4C1920Table) == 48) ? 1 : -1];

Data4C1920Table data_u32_004C1920 = {
    -33.0f, -98.0f, -9.0f, -5.25f, 1.8f, 1.05f,
    0x0000B556u, 0u, 0x0000D778u, 0x0000D778u, 0x0000199Au, 0x0000199Au,
};
