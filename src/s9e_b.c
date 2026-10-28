typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
extern u16 D_0043CC30[];
extern u16 D_0043CC40[];
extern u16 D_004F4480[];
extern u16 D_004CA020[][8];
extern u16 D_004F7FC0[][8];
extern s16 D_004F25A0[];
extern s16 D_004F25A2[];
extern s16 D_004F25A4[];
extern s16 D_004F25A6[];
void func_001288A0(s32 i)
{
    s32 j;
    s32 o;
    u16 r;
    u16 *q;
    s32 k;
    u16 b;
    b = D_004F4480[i * 10];
    k = i << 4;
    r = 0;
    for (j = 0; j < 8; j++) D_004CA020[i][j] = b & D_0043CC30[j];
    q = (u16 *)((u8 *)D_004F7FC0 + k) + 0x10;
    for (j = 0; j < 8; j++) {
        if (D_004CA020[i][j] != 0) r |= D_0043CC40[q[j]];
    }
    o = i * 0x5B8;
    *(u16 *)((u8 *)D_004F25A2 + o) = *(u16 *)((u8 *)D_004F25A0 + o);
    *(s16 *)((u8 *)D_004F25A0 + o) = (s16)r | (b & 0xBC02);
    *(s16 *)((u8 *)D_004F25A4 + o) = ~*(s16 *)((u8 *)D_004F25A2 + o) & *(s16 *)((u8 *)D_004F25A0 + o);
    *(s16 *)((u8 *)D_004F25A6 + o) = *(s16 *)((u8 *)D_004F25A2 + o) & ~*(s16 *)((u8 *)D_004F25A0 + o);
}
