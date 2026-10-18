typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a; s16 b; f32 f; } E15;
extern E15 *D_00445220[];
extern s32 D_00445240[];
extern u32 D_004C2838;
extern s32 func_003DAA40(u8 *);

s32 func_0015CF60(u8 *p)
{
    if (*(s16 *)(p + 0x1C) >= D_00445240[p[0x20]]) return func_003DAA40(p);
    *(s16 *)(p + 0xCC) = D_00445220[p[0x20]][*(s16 *)(p + 0x1C)].a;
    *(u32 *)(p + 0x84) = D_004C2838;
    *(f32 *)(p + 0x7C) = *(f32 *)(p + 0x78) = D_00445220[p[0x20]][*(s16 *)(p + 0x1C)].f;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    (*(s16 *)(p + 0x1C))++;
}
