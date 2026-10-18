typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00478DF0[];
extern void func_003EFA40(s32, s32, s32);

void func_003EF9A0(s32 n, s32 k, s32 dst, u8 *src) {
    s32 i;
    s32 step = D_00478DF0[k];
    for (i = 0; i < n; i++) {
        func_003EFA40(dst, k, src[i]);
        dst += step;
    }
}
