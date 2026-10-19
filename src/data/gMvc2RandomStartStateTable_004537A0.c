/* Routine 002590A0 indexes this sibling random-state map with (random & 0xF) * 2. Its 16 two-byte records match the E2 layout and contents at 004577A0; the next native base at 004537C0 bounds the span. */
typedef unsigned char u8;
typedef struct { u8 a; u8 b; } E2;

E2 gMvc2RandomStartStateTable_004537A0[16] = {
    { 5, 0 },
    { 5, 0 },
    { 5, 0 },
    { 6, 0 },
    { 6, 0 },
    { 7, 0 },
    { 7, 0 },
    { 7, 0 },
    { 8, 0 },
    { 8, 0 },
    { 8, 0 },
    { 8, 0 },
    { 9, 0 },
    { 10, 0 },
    { 10, 0 },
    { 10, 0 },
};
