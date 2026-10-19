#pragma padloop on
typedef unsigned char u8;
typedef signed int s32;
typedef signed short s16;

extern void *func_0011D8F8(void *dst, s32 value, s32 size);
extern void func_003F9698(s32 a, s32 b, s16 *c, s16 *d);
extern s32 D_004854C0[];

s32 *func_00404290(void)
{
    s32 i;
    s32 *p;
    s32 *slot;
    p = D_004854C0;
    i = 0;
    if (*p != 0) {
        do {
            i++;
            if (i >= 16)
                break;
            p = (s32 *)((u8 *)p + 60);
        } while (*p != 0);
    }
    if (i == 16)
        return 0;
    slot = (s32 *)((u8 *)D_004854C0 + i * 60);
    func_0011D8F8(slot, 0, 60);
    slot[0] = 1;
    slot[1] = i;
    slot[2] = 0;
    slot[3] = 0;
    func_003F9698(500, 44100, (s16 *)((u8 *)slot + 48), (s16 *)((u8 *)slot + 50));
    func_0011D8F8((u8 *)slot + 40, 0, 8);
    return slot;
}
