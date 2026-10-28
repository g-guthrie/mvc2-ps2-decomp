typedef unsigned char u8;
typedef signed int s32;

typedef struct { u8 pad[0x1C]; s32 f1c; u8 pad2[0x170 - 0x20]; } E41BB30;
extern E41BB30 D_005BF2F0[];

void func_0041BB30(s32 *p)
{
    extern s32 func_003DD030(s32, s32);
    extern void func_001046D8(s32, s32);
    extern void func_001049F8(s32);
    s32 v;
    s32 m;
    v = func_003DD030(((E41BB30 *)((s32)D_005BF2F0 + (p[0] + (m = -1)) * 0x170))->f1c, m);
    func_001046D8(v, v + p[8] - 1);
    func_001049F8(2);
    func_001049F8(1);
}
