typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 D_0057FB70[];
extern u8 D_0057ED70[];
extern s32 D_004C28A8[2];

void func_00414F00(void)
{
    extern void func_003E94D0(u32);
    extern s32 func_003E9420(u32);
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_003DD040();
    s32 i;
    u32 *p;
    p = D_0057FB70;
    for (i = 0; i < D_004C28A8[0]; p++, i++) {
        if (*p == 0xFFFFFFFF) continue;
        if ((*p & 0xFFFF0000) >> 16 != 0xFFFF) {
            func_003E94D0((*p & 0xFFFF0000) >> 16);
            *p |= 0xFFFF0000;
        }
        if ((u16)*p != 0xFFFF) {
            if (func_003E9420((u16)*p) == 1) *p |= 0xFFFF;
        }
    }
    D_004C28A8[0] = 0;
    func_0011D8F8(D_0057ED70, -1, 0xE00);
    func_003DD040();
}
