typedef unsigned char u8;
typedef unsigned short u16;
/* Header of record 0 of the alternate legal-notice table D_004B8C10 (same 0x40-byte record
 * layout as D_004B8950; func_0016D4B0 reads +0/+1 with lbu and +2 with lhu). Its text
 * starts at gLegalNoticeSegment10_004B8C14. */
typedef struct {
    u8 x;
    u8 y;
    u16 attr;
} LegalNoticeLineHeader;
typedef char LegalNoticeLineHeader_size_check[(sizeof(LegalNoticeLineHeader) == 4) ? 1 : -1];
LegalNoticeLineHeader data_raw_004B8C10 = { 0x08, 0x14, 0x0012 };
