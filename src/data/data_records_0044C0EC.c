/* Selectors 2-8 are fixed at callsites to func_001BC660 and func_001BC720; consumers read the 6-byte record fields at offsets 0, 2, 4, and 5. */
typedef struct { signed short field_0; signed short field_2; signed char field_4; unsigned char field_5; } AnimationStateRecord;
AnimationStateRecord data_records_0044C0EC[7] = {
    { 0, 0, 0, 4 },
    { 0, 0, 0, 5 },
    { -99, 93, 0, 6 },
    { 0, 0, 0, 7 },
    { 0, 0, 15, 9 },
    { -36, 88, 7, 1 },
    { 24, 112, 7, 1 }
};
