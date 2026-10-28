typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Stream of 8-byte records, selected through the D_0043E860 pointer table and func_00134710 (D_0043E410).
 * The parser stops on the first record whose field_0 is -1. */
ByteFloatRecord data_rec_0043E410[16] = {
    { 2, 0, 3, 0, 1.0f },
    { 2, 1, 0, 0, 3.5f },
    { 2, 2, 0, 0, 3.5f },
    { 2, 3, 0, 0, 3.5f },
    { 2, 4, 0, 0, 3.5f },
    { 2, 5, 0, 0, 3.5f },
    { 2, 6, 0, 0, 3.5f },
    { 2, 7, 0, 0, 3.5f },
    { 2, -1, 0, 0, 3.5f },
    { 2, -1, 0, 0, 3.5f },
    { 2, -1, 0, 0, 3.5f },
    { 3, -1, 4, 36, 3.5f },
    { 3, -1, 0, 37, 2.25f },
    { 3, -1, 0, 38, 2.25f },
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
    { 0, 0, 0, 0, 0.0f }, /* alignment pad to next stream */
};
