typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
struct RuntimeVector3 { f32 x, y, z; };

extern s32 func_00416AE0(s32);
extern void func_00417A50(f32, f32, f32);
extern void func_00417170(const struct RuntimeVector3 *);
extern void func_004172E0(u32);
extern void func_00417270(u32);
extern void func_00417200(const struct RuntimeVector3 *);
extern f32 func_001519E0(u8 *);
extern void func_00417FC0(f32);
extern void *func_00416D40(f32 *);
extern void func_003DDAD0(u32 *, f32, f32, f32);
extern void func_003DDDC0(f32 *, f32, f32, f32);
extern void func_003DD260(f32 *);
extern void func_003DF850(s32, u32);
extern void func_001538B0(u8 *, u8 *, f32 *);
extern s32 func_00416CC0(s32);

void func_001431A0(u8 *p)
{
    u8 *res;
    f32 t[16];
    f32 m[16];
    f32 base[16];
    u32 flags;

    if (*(s8 *)(p + 0x13C) == 0)
        return;
    func_00416AE0(0);
    func_00417A50(*(f32 *)(p + 0x78), *(f32 *)(p + 0x7C), *(f32 *)(p + 0x80));
    func_00417170((const struct RuntimeVector3 *)(p + 0x50));
    func_004172E0(*(u32 *)(p + 0x44));
    func_00417270(*(u32 *)(p + 0x48));
    func_00417200((const struct RuntimeVector3 *)(p + 0x34));
    func_00417FC0(func_001519E0(p + 0x50));
    res = *(u8 **)(p + 0x84);
    func_00416D40(base);
    t[0] = base[0]; t[1] = base[1]; t[2] = base[2]; t[3] = base[3];
    t[4] = base[4]; t[5] = base[5]; t[6] = base[6]; t[7] = base[7];
    t[8] = base[8]; t[9] = base[9]; t[10] = base[10]; t[11] = base[11];
    t[12] = base[12]; t[13] = base[13]; t[14] = base[14]; t[15] = base[15];
    flags = *(u32 *)(p + 0xD0);
    if (flags & 0x20000) {
        func_003DDAD0((u32 *)m, *(f32 *)(p + 0xE0), *(f32 *)(p + 0xE4), 0.0f);
        func_003DDDC0(m, 0.0f, 0.0f, 0.0f);
    } else {
        func_003DD260(m);
    }
    func_003DF850(0x1A, (u32)m);
    flags = *(u32 *)(p + 0xD0);
    if (flags & 0x200000)
        func_003DF850(0x6C, 7);
    func_001538B0(p, ((u8 **)(*(u8 **)(res + 0x1C)))[*(s16 *)(p + 0xCC)], t);
    flags = *(u32 *)(p + 0xD0);
    if (flags & 0x200000)
        func_003DF850(0x6C, 1);
    func_00416CC0(1);
}
