typedef unsigned int u32;
typedef short s16;
typedef float f32;

/* Seven-word setup record passed to func_00141C90 (count 8 at the call site). Words 1-2 and
 * 4-5 are f32 values, words 3 and 6 hold two signed halfwords each. */
typedef struct {
    u32 word_00;
    f32 f_04;
    f32 f_08;
    s16 h_0C;
    s16 h_0E;
    f32 f_10;
    f32 f_14;
    s16 h_18;
    s16 h_1A;
} data_u32_00441700_t;
typedef char data_u32_00441700_size_check[(sizeof(data_u32_00441700_t) == 28) ? 1 : -1];

data_u32_00441700_t data_u32_00441700[1] = {
    { 0x00000000u, 3.0f, 3.0f, 30, 90, 2.0f, 2.0f, 60, 180 },
};
