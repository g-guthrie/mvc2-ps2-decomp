typedef signed char s8;
typedef struct { s8 field_0; s8 field_1; s8 field_2; s8 field_3; float field_4; } ByteFloatRecord;
/* Parser reads signed bytes at offsets 0-3, a float at 4, then advances 8 bytes. */
ByteFloatRecord data_records_0043E3D0[7] = {
    { 2, 0, 1, 0, 2.5F },
    { 2, 1, 0, 0, 3.5F },
    { 2, 2, 0, 0, 3.5F },
    { 4, -1, 2, 17, 2.80999994F },
    { 4, -1, 0, 18, 2.68000007F },
    { 4, -1, 0, 29, 2.38000011F },
    { -1, -1, 0, 0, 0.0F },
};
