typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table.
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E5A0[6] = {
    { 1, -1, 0, 16, 1.5f },
    { 1, -1, 0, 27, 3.55f },
    { 1, -1, 0, 14, 3.12f },
    { 1, -1, 0, 10, 3.08f },
    { 1, -1, 0, 29, 2.86f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
