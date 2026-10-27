typedef struct SA37_J0 SA37_J0;
typedef struct SA37_R SA37_R;
/* Select collision flags for this actor interaction variant. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

s32 func_00167700(u8 *p, u8 *q)
{
    extern s32 func_0016B250();
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(SA37_J0 *, SA37_R *, s32);
    u16 v;
    if (func_0016B250(p, 2) == 0) return 0;
    if (func_0016B360(p, q) == 0) return 0;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 0);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    v = (*(s32 *)(p + 0x4C8) != 0) ? 0x20 : 0x40;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    v |= ((*(s16 *)(p + 0x4C8) << 8) & 0x3C00);
    if ((v & 0xC00) != 0) v = v ^ (p[0x1E6] * 3 << 10);
    *(u16 *)(p + 0x4F0) = v;
    return 0;
}
