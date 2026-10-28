typedef unsigned char u8;
typedef unsigned short u16;
/* Legal-notice lines drawn by func_0016BBD4..0x0016BC28 (also 0x003D1978): the loop passes
 * each 0x40-byte record to func_0016D4B0 while byte 0 is below 0x64. func_0016D4B0 reads
 * bytes +0/+1 (lbu) and the halfword at +2 (lhu) and draws the NUL-terminated text at +4.
 * Record 10 (0xFF) terminates the list. D_004B8C10 is the alternate table chosen when
 * D_004C2840->b29 == 1. */
typedef struct {
    u8 x;
    u8 y;
    u16 attr;
    char text[0x3C];
} Mvc2LegalNoticeLine;
typedef char Mvc2LegalNoticeLine_size_check[(sizeof(Mvc2LegalNoticeLine) == 0x40) ? 1 : -1];
Mvc2LegalNoticeLine D_004B8950[11] = {
    { 0x08, 0x14, 0x0012, "MARVEL AND ALL RELATED CHARACTERS AND THE" },
    { 0x08, 0x1C, 0x0012, "DISTINCTIVE LIKENESSES THEREOF ARE TRADEMARKS" },
    { 0x08, 0x24, 0x0012, "OF MARVEL CHARACTERS, INC., AND ARE USED WITH" },
    { 0x08, 0x2C, 0x0012, "PERMISSION. COPYRIGHT ^Z 2002 MARVEL CHARACTERS," },
    { 0x08, 0x34, 0x0012, "INC. ALL RIGHTS RESERVED. www.marvel.com" },
    { 0x08, 0x3C, 0x0012, "^ZCAPCOM CO., LTD. 2002 ALLRIGHTS RESERVED." },
    { 0x08, 0x44, 0x0012, "STRIDER: ^ZMOTO KIKAKU. ^ZCAPCOM CO., LTD. 2002" },
    { 0x08, 0x4C, 0x0012, "ALL RIGHTS RESERVED." },
    { 0x08, 0x54, 0x0012, "THIS VIDEO GAME HAS BEEN PRODUCED UNDER " },
    { 0x08, 0x5C, 0x0012, "THE LICENSE FROM MARVEL CHARACTERS, INC." },
    { 0xFF, 0x00, 0x0000, "" },
};
