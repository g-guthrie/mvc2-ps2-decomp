typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00174170(void);
extern void func_00169C90(u8 *);

void func_00169F40(u8 *p)
{
    u8 *s2 = p;
    u8 *tbl;
    u8 *s0;
    u8 *row;
    u8 *s1;
    u8 *s3;
    s32 r;
    u8 v1;

    tbl = *(u8 **)(*(u8 **)(s2 + 0x4CC) + 0x184);
    s0 = *(u8 **)(s2 + 0x1A4);
    tbl += s2[0x4B4] * 28;
    row = s0 + tbl[0x19] * 12;
    s1 = *(s32 *)(row + 8) + s0;
    s3 = *(s32 *)(row + 4) + s0;
    r = func_00174170() & 0x1F;
    v1 = *(u8 *)(s3 + r);
    *(s32 *)(s2 + 0x484) = (s32)(*(s32 *)(s1 + v1 * 4) + s0);
    *(s16 *)(s2 + 0x488) = 0;
    s2[0x48A] = v1;
    s2[0x48B] = 0;
    func_00169C90(s2);
}
