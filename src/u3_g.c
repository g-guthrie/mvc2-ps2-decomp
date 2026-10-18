typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_003FB1E0(s32, s32, s32);
extern s32 func_0011FFA0(s32);
extern void func_001200D8(s32, void *, s32);
extern char D_004C22A8[];

void func_003FB2E8(s32 a, s32 b, s32 c, s32 d) {
    s32 t;
    func_003FB1E0(a, c, d);
    d -= func_0011FFA0(c);
    func_001200D8(c, D_004C22A8, d - 1);
    t = func_0011FFA0(c);
    func_003FB1E0(b, c + t, 4 - func_0011FFA0(c));
}
