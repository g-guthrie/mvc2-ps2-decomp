typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E6C0[10] = {
    { 1, -1, 0, 22, 2.0f },
    { 1, -1, 0, 10, 3.8f },
    { 1, -1, 0, 27, 3.45f },
    { 1, -1, 0, 31, 3.4f },
    { 1, -1, 0, 14, 3.31f },
    { 1, -1, 0, 21, 3.24f },
    { 1, -1, 0, 24, 2.72f },
    { 1, -1, 0, 30, 3.62f },
    { 1, -1, 0, 28, 3.69f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
