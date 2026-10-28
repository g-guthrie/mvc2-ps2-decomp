typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E820[8] = {
    { 1, -1, 0, 22, 2.0f },
    { 1, -1, 0, 24, 3.92f },
    { 1, -1, 0, 23, 3.51f },
    { 1, -1, 0, 28, 3.56f },
    { 1, -1, 0, 29, 3.39f },
    { 1, -1, 0, 14, 3.13f },
    { 1, -1, 0, 27, 3.02f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
