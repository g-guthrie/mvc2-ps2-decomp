typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E490[12] = {
    { 3, -1, 0, 15, 1.0f },
    { 3, -1, 0, 18, 2.42f },
    { 3, -1, 0, 27, 2.73f },
    { 3, -1, 0, 28, 3.43f },
    { 3, -1, 0, 29, 3.3f },
    { 3, -1, 0, 10, 5.78f },
    { 3, -1, 0, 29, 3.06f },
    { 3, -1, 0, 29, 3.46f },
    { 3, -1, 0, 10, 3.04f },
    { 3, -1, 0, 12, 3.35f },
    { 3, -1, 0, 20, 3.7f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
