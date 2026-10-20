typedef unsigned int u32;

/* Three directly accessed 32-bit fields: word0 is stored at 0x00107710 and loaded at 0x00108B30/0x00108B5C; word1 is read at 0x00107B30; word2 is read at 0x001076E8 and written at 0x00107DA0. The next unit at 0x00438304 is independently read at 0x00107A7C. */
typedef struct { u32 word_0; u32 word_4; u32 word_8; } U32FieldTriplet;
U32FieldTriplet data_u32_004382F8 = { 0x00000000u, 0x00000000u, 0x00000000u };
