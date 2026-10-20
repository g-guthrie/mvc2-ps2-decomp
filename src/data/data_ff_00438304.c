typedef unsigned int u32;

/* Each sentinel word is accessed directly: word0 at 0x00107A7C/0x00107AD0, word1 at 0x0010759C, and word2 at 0x00108380. The following data unit at 0x00438310 is separately loaded at 0x00107E10/0x00107E20, bounding this object to three words. */
typedef struct { u32 word_0; u32 word_4; u32 word_8; } U32FieldTriplet;
U32FieldTriplet data_ff_00438304 = { 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu };
