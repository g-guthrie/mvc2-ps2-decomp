typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* Two adjacent records; field meanings are not yet known from the readers. */
typedef struct {
    f32 f0;
    f32 f1;
    u32 w2;
    u32 w3;
    f32 f4;
    f32 f5;
    u32 w6;
    u32 w7;
} Data4BF400RecordA;

typedef struct {
    f32 f0;
    f32 f1;
    u32 w2;
    s32 s3;
    u32 w4;
    f32 f5;
} Data4BF400RecordB;

typedef struct {
    Data4BF400RecordA a;
    Data4BF400RecordB b;
} Data4BF400Table;

typedef char Data4BF400Table_size_check[(sizeof(Data4BF400Table) == 56) ? 1 : -1];

Data4BF400Table data_u32_004BF400 = {
    { 5.94f, -7.42f, 12u, 6u, 3.0f, 4.5f, 0u, 0u },
    { 3.33f, 0.02f, 0u, -1, 0u, 5.0f },
};
