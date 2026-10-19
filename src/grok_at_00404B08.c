typedef unsigned char u8;
typedef signed int s32;

extern void func_00404BD0(u8 *p);
extern s32 func_004003C8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 func_00400BB8(s32 handle, s32 value);
extern void func_00400658(s32 handle, s32 offset);
extern void func_004007A0(s32 handle, s32 mode);
extern void func_004006E8(s32 handle);
extern void func_004052E0(s32 handle, s32 flag);
extern void func_004052C0(s32 handle);

s32 func_00404B08(u8 *p, s32 a, s32 b)
{
    s32 h;
    func_00404BD0(p);
    h = func_004003C8(a, b, 0, 0xFFFFF, *(s32 *)(p + 0x8C));
    *(s32 *)(p + 8) = h;
    if (h == 0)
        return 4;
    func_00400BB8(h, 0x7FFFFFFF);
    func_00400658(*(s32 *)(p + 8), 0);
    func_004007A0(*(s32 *)(p + 8), 3);
    func_004006E8(*(s32 *)(p + 8));
    func_004052E0(*(s32 *)(p + 4), 1);
    func_004052C0(*(s32 *)(p + 4));
    p[1] = 1;
    return 1;
}
