typedef signed char s8;
typedef float f32;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; f32 field_4; } ByteFloatRecord;
/* Entry 3 of jtbl_0043E860 (word at 0x0043E86C): an empty 8-byte record stream holding only
 * the terminator record (the parser stops on field_0 == -1), like data_rec_0043E570's tail. */
ByteFloatRecord data_rec_004BF358[1] = {
    { -1, -1, 0, 0, 0.0f }, /* stream terminator */
};
