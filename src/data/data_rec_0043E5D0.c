typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E5D0[10] = {
    { 1, -1, 0, 31, 1.5f },
    { 1, -1, 0, 14, 3.0f },
    { 1, -1, 0, 27, 3.03f },
    { 1, -1, 0, 34, 3.17f },
    { 1, -1, 0, 16, 5.76f },
    { 1, -1, 0, 24, 3.44f },
    { 1, -1, 0, 24, 3.5f },
    { 1, -1, 0, 13, 3.5f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
    { 0, 0, 0, 0, 0.0f }, /* alignment pad to next stream */
};
