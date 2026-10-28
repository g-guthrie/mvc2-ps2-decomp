/*
 * Tail of the legal-notice record table that starts at D_004B8C10
 * (func_0016BB50 0x0016BBE8 / func_0016D4B0). Each 0x40-byte record:
 *   +0 lbu x (loop at 0x0016BC20 stops once x >= 100), +1 lbu y,
 *   +2 lhu glyph/style index (sll 4 into D_004B4F40 at 0x0016D4F8),
 *   +4 NUL-terminated text scanned byte-by-byte (0x0016D4E0).
 * The earlier records of the same table (0x004B8C10..0x004B8CCF) are still
 * catalogued as separate units; this unit begins at the record at 0x004B8CD0.
 * The last record (x = 0xFF) is the terminator.
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct LegalNoticeRecord {
    u8 x;
    u8 y;
    u16 style;
    char text[0x3C];
} LegalNoticeRecord;

LegalNoticeRecord gLegalNoticeRecords_004B8CD0[9] = {
    { 0x08, 0x2C, 0x12, "PERMISSION. COPYRIGHT ^Z 2002 MARVEL CHARACTERS," },
    { 0x08, 0x34, 0x12, "INC. ALL RIGHTS RESERVED. www.marvel.com" },
    { 0x08, 0x3C, 0x12, "^ZCAPCOM CO., LTD. 2002," },
    { 0x08, 0x44, 0x12, "^ZCAPCOM U.S.A., INC. 2002 ALL RIGHTS RESERVED." },
    { 0x08, 0x4C, 0x12, "STRIDER: ^ZMOTO KIKAKU. ^ZCAPCOM CO., LTD. 2002," },
    { 0x08, 0x54, 0x12, "^ZCAPCOM U.S.A., INC. 2002 ALL RIGHTS RESERVED." },
    { 0x08, 0x5C, 0x12, "THIS VIDEO GAME HAS BEEN PRODUCED UNDER " },
    { 0x08, 0x64, 0x12, "THE LICENSE FROM MARVEL CHARACTERS, INC." },
    { 0xFF, 0x00, 0x00, "" },
};
