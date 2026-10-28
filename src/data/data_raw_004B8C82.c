typedef unsigned char u8;
typedef unsigned short u16;
/* In the alternate legal-notice table D_004B8C10 (0x40-byte records: u8 x, u8 y, u16 attr,
 * char text[0x3C]; read by func_0016D4B0): the zero tail of record 1's text field after
 * gLegalNoticeSegment11_004B8C54, then the header of record 2, whose text is
 * gLegalNoticeSegment12_004B8C94. */
typedef struct {
    u8 x;
    u8 y;
    u16 attr;
} LegalNoticeLineHeader;
typedef char LegalNoticeLineHeader_size_check[(sizeof(LegalNoticeLineHeader) == 4) ? 1 : -1];
typedef struct {
    char textTail[14];
    LegalNoticeLineHeader next;
} LegalNoticeLineJoin14;
typedef char LegalNoticeLineJoin14_size_check[(sizeof(LegalNoticeLineJoin14) == 18) ? 1 : -1];
LegalNoticeLineJoin14 data_raw_004B8C82 = { "", { 0x08, 0x24, 0x0012 } };
