typedef unsigned char u8;
/* Routine 00227B90 uses random & 3 here only in state 0 and forwards the selected 0..3 parameter to the animation helper. The next independent base at 004C0088 bounds this four-byte lookup; bytes +4..+7 remain untyped padding. */
u8 data_u8_004C0080[4] = { 0, 1, 2, 3 };
