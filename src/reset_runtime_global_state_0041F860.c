typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;

struct RuntimeResetState
{
    s32 slotE8;
    s32 slotEC;
    s32 counterF0;
    s32 counterF4;
    u8 padding10[6];
    u16 field16;
    u8 padding18[6];
    u16 field1E;
};

extern struct RuntimeResetState D_006336E8;
extern s32 D_004D1788[];
extern s32 D_004C2B78;
extern s32 D_004C2B7C;
extern u8 D_004C2B80;
extern s32 D_004C2B84;
extern void func_0038CFB0(s32 mode);

void func_0041F860(s32 use_default)
{
    D_006336E8.counterF0 = 0;
    D_006336E8.counterF4 = 0;
    D_004C2B7C = -1;
    D_004C2B78 = -1;
    D_006336E8.slotE8 = -1;
    D_006336E8.slotEC = -1;
    D_004D1788[0] = 0;
    D_006336E8.field16 = 0xFFFF;
    D_006336E8.field1E = 0xFFFF;

    if (use_default == 0)
    {
        func_0038CFB0(0);
        D_004C2B84 = 58;
        D_004C2B80 = 1;
    }
    else
    {
        func_0038CFB0(1);
        D_004C2B84 = 119;
        D_004C2B80 = 4;
    }
}
