typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004CB5B4;
extern void func_0013E0F0(u8 *);
extern void func_0013E570(void);
extern void func_00170E60(s32, s32, s32, s32, void (*)(void), u8 **);

void func_0013E4D0(u8 *p)
{
    u8 *g;
    u8 *obj;
    u8 *tmp[2];

    if (*(s16 *)(p + 0x1C) != 60) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        func_0013E0F0(p);
    }
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 20;
    if (*(s16 *)(p + 0x1E) >= 360)
        *(s16 *)(p + 0x1E) = 0;
    g = D_004CB5B4;
    obj = *(u8 **)(p + 0x84);
    tmp[0] = p;
    tmp[1] = 0;
    func_00170E60(
        *(s32 *)(g + 0x14),
        *(s32 *)(*(u8 **)(g + 0x1C) + 4),
        *(s32 *)(obj + 0x14),
        *(s32 *)(*(s32 *)(obj + 0x1C) + *(s16 *)(p + 0xCC) * 4),
        func_0013E570,
        tmp);
}
