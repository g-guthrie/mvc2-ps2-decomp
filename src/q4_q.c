typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0017AF30(u8 *p)
{
    extern void func_00185490(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00184E70(u8 *);
    extern void func_00184CA0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001821D0(u8 *);
    extern void func_001820A0(u8 *);
    extern s32 func_00185A90(u8 *);
    extern void func_001822B0(u8 *);
    extern void func_00182300(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001865B0(u8 *);
    u32 *b;
    u32 *a;
    func_00185490(p);
    if (func_00184720(p) != 0) return;
    a = (u32 *)(p + 0x428);
    b = (u32 *)(p + 0x42C);
    if (((*(u32 *)(p + 0x428) & 0x184010A0) | (*(u32 *)(p + 0x42C) & 0x02000801)) != 0) {
        if (func_00184E70(p) != 0) return;
    }
    if (((*a & 0xA8400960) | (*b & 0x10)) != 0) func_00184CA0(p);
    if (p[1] == 0x2A) (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
    func_00175700(p);
    func_001821D0(p);
    func_001820A0(p);
    if (func_00185A90(p) != 0) return;
    func_001822B0(p);
    func_00182300(p);
    if (func_001864A0(p) != 0) func_001865B0(p);
}
