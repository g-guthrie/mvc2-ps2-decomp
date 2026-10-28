typedef unsigned char u8;
typedef unsigned short u16;
/* In the alternate legal-notice table D_004B8C10 (0x40-byte records: u8 x, u8 y, u16 attr,
 * char text[0x3C]; read by func_0016D4B0): the zero tail of record 0's text field after
 * gLegalNoticeSegment10_004B8C14, then the header of record 1, whose text is
 * gLegalNoticeSegment11_004B8C54. */
typedef struct {
    u8 x;
    u8 y;
    u16 attr;
} LegalNoticeLineHeader;
typedef char LegalNoticeLineHeader_size_check[(sizeof(LegalNoticeLineHeader) == 4) ? 1 : -1];
typedef struct {
    char textTail[18];
    LegalNoticeLineHeader next;
} LegalNoticeLineJoin18;
typedef char LegalNoticeLineJoin18_size_check[(sizeof(LegalNoticeLineJoin18) == 22) ? 1 : -1];
LegalNoticeLineJoin18 data_raw_004B8C3E = { "", { 0x08, 0x1C, 0x0012 } };
