typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s16 *D_0045F048[];
extern s32 D_0045F058[];
extern u8 *D_004C283C;
extern void func_003DAA40(u8 *);

void func_0033D5F0(u8 *p)
{
    *(s32 *)(p + 0x74) = 0x3f000000;
    *(s16 *)(p + 0xcc) = D_0045F048[p[0x20]][*(s16 *)(p + 0x1c)];
    *(u8 **)(p + 0x84) = D_004C283C;
    *(s16 *)(p + 0x1c) = (s16)(*(s16 *)(p + 0x1c) + 1);
    if ((s16)(*(s16 *)(p + 0x1c)) >= D_0045F058[p[0x20]])
        func_003DAA40(p);
}
