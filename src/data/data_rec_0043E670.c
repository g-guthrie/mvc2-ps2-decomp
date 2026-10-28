typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E670[10] = {
    { 1, -1, 0, 15, 1.0f },
    { 1, -1, 0, 10, 2.76f },
    { 1, -1, 0, 23, 3.34f },
    { 1, -1, 0, 29, 3.52f },
    { 1, -1, 0, 10, 2.94f },
    { 1, -1, 0, 28, 3.4f },
    { 1, -1, 0, 29, 3.32f },
    { 1, -1, 0, 18, 2.67f },
    { 1, -1, 0, 12, 2.73f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
