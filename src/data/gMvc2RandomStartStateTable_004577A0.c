/* Lookup at 00290940 indexes with random & 0xF; field a is the selected initial state. Field b is part of the observed E2 layout and remains zero. The next native base at 004577C0 bounds the table. */
typedef unsigned char u8;
typedef struct { u8 a; u8 b; } E2;

E2 gMvc2RandomStartStateTable_004577A0[16] = {
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
