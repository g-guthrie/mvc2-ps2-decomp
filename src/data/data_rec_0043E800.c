typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E800[4] = {
    { 1, -1, 0, 34, 1.5f },
    { 1, -1, 0, 14, 2.93f },
    { 1, -1, 0, 28, 2.96f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
