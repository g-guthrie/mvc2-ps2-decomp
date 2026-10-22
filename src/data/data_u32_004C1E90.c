typedef short s16;
typedef struct Pt16 { s16 x; s16 y; } Pt16;
extern unsigned int data_u32_00472A9C[];
/* Two pointers into data_u32_00472A9C, then four 16-bit pairs. */
typedef struct Rec24P { const void *a; const void *b; Pt16 pts[4]; } Rec24P;
Rec24P data_u32_004C1E90 = {
    (const void *)&data_u32_00472A9C[5],
    (const void *)&data_u32_00472A9C[13],
    { { 2, 4 }, { 0, 0 }, { 16384, -5 }, { 16384, -7 } },
};
