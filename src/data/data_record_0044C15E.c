/* Selector 21 is fixed at a callsite to func_001BC660; consumers read the 6-byte record fields at offsets 0, 2, 4, and 5. */
typedef struct { signed short field_0; signed short field_2; signed char field_4; unsigned char field_5; } AnimationStateRecord;
AnimationStateRecord data_record_0044C15E[1] = {
    { 0, 0, 0, 48 }
};
