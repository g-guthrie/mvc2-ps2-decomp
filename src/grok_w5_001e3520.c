typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004F20B0[];

void func_001E3520(u8 *p, s32 animation)
{
    extern void func_001741D0(const f32 *, f32 *);
    extern s32 func_00118FA8(f32);
    extern void func_001E3D20(s32, s32, s32, s32);
    f32 t[2];
    s32 mode;
    u8 frame;
    s32 i;
    s32 offset;
    u8 *e;
    func_001741D0((f32 *)(p + 0x34), t);
    mode = func_00118FA8(t[0] / 40.0f);
    if (mode <= -1) mode = 0;
    if (mode >= 16) mode = 15;
    if (((s8 *)D_004C2840)[0x45] != 0) {
        u8 *map = *(u8 **)(u32)0x0044F134;
        s32 mapped = map[(u8)animation];
        if (mapped == 254) return;
        if (mapped != 255) animation = mapped;
    }
    i = 0;
    offset = 0;
    do {
        e = D_004F20B0 + offset;
        if (e[1] == 25) frame = e[0x1B8];
        i++;
        offset += 0x5B8;
    } while (i < 6);
    func_001E3D20(frame, (u8)animation, mode, -1);
}
