typedef signed short s16;
typedef signed int s32;

extern s32 D_004C2B70;
extern s32 D_004C2B74;
extern s16 D_00633720[];
extern void func_0041CEE0(s32 *x, s32 *y, s32 deltaX,
                          s32 deltaY, s32 wrapY, s32 wrapX);

s32 func_0041D020(s32 unused0, s32 unused1, s32 delta)
{
    s16 *value;

    func_0041CEE0(&D_004C2B70, &D_004C2B74, delta, 0, 0, delta);
    value = (s16 *)((unsigned char *)D_00633720
                  + (D_004C2B70 << 4)
                  + (D_004C2B74 << 1));
    return *value;
}
