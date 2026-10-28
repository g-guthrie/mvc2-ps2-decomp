typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E770[10] = {
    { 3, -1, 0, 10, 1.5f },
    { 3, -1, 0, 18, 2.42f },
    { 3, -1, 0, 27, 2.56f },
    { 3, -1, 0, 12, 7.27f },
    { 3, -1, 0, 24, 3.54f },
    { 3, -1, 0, 22, 4.0f },
    { 3, -1, 0, 11, 4.07f },
    { 3, -1, 0, 24, 3.41f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
    { 0, 0, 0, 0, 0.0f }, /* alignment pad to next stream */
};
