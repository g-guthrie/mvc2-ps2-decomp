/* Selectors 16-17 are fixed at callsites to func_001BC660; consumers read the 6-byte record fields at offsets 0, 2, 4, and 5. */
typedef struct { signed short field_0; signed short field_2; signed char field_4; unsigned char field_5; } AnimationStateRecord;
AnimationStateRecord data_records_0044C140[2] = {
    { 0, 0, 0, 43 },
    { 85, 212, 10, 44 }
};
