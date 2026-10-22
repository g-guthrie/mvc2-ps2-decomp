typedef float f32;
typedef struct { f32 v[4]; char title[48]; } TitleRecord;
typedef char TitleRecord_size_check[(sizeof(TitleRecord) == 64) ? 1 : -1];
/* title is Shift-JIS text "MARVEL VS. CAPCOM2" (full-width), zero padded. */
TitleRecord data_u32_00464F40 = { { 0.300000012f, 0.300000012f, 0.300000012f, 1.0f }, "\x82\x6c\x82\x60\x82\x71\x82\x75\x82\x64\x82\x6b\x81\x40\x82\x75\x82\x72\x81\x44\x82\x62\x82\x60\x82\x6f\x82\x62\x82\x6e\x82\x6c\x82\x51" };
