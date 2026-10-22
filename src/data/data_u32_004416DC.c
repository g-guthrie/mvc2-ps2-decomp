typedef unsigned short u16;
typedef short s16;
typedef struct {
    u16 a0;
    u16 a1;
    float f2;
    float f3;
    u16 b0;
    u16 b1;
    float f4;
    float f5;
    s16 c0;
    s16 c1;
} data_u32_004416DC_rec;
typedef char data_u32_004416DC_size_check[(sizeof(data_u32_004416DC_rec) == 28) ? 1 : -1];
data_u32_004416DC_rec data_u32_004416DC = {
    0x003C, 0x005A, 3.0f, 3.0f, 0x0078, 0x00B4, 2.0f, 2.0f, -3, 810 };

