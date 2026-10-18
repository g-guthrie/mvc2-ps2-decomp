typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern u32 D_00439920[];
extern u8 D_004AB388;
extern void func_0011FE88(u8 *, u32);

void func_0010DA08(u32 a, u8 *b) {
    if (a < 8) {
        func_0011FE88(b, D_00439920[a]);
    } else {
        *b = D_004AB388;
    }
}
