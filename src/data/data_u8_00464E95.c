typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* Bytes +5..+0xF of the 0x3C4-byte memory-card icon.sys image D_00464E90 (func_0038B2E0 writes
 * 0x3C4 bytes from it to the card). The image starts with the "PS2D" magic, whose NUL
 * terminator (gPs2DiscTypeName_00464E90) is the low byte of the reserved halfword at +4; this
 * unit holds that halfword's high byte, the title line-break offset halfword at +6 (stored
 * as 0x20 by func_0038CE40/func_0038D010 with sh; retail initial 0x1E), and the two words at
 * +8/+0xC before the background colors at +0x10. */
#pragma pack(1)
typedef struct {
    u8 reserved04Hi;
    u16 titleLineBreak;
    u32 word08;
    u32 word0C;
} IconSysHeaderTail;
#pragma pack()
typedef char IconSysHeaderTail_size_check[(sizeof(IconSysHeaderTail) == 11) ? 1 : -1];
IconSysHeaderTail data_u8_00464E95 = { 0, 0x001E, 0, 0 };
