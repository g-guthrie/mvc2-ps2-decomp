typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_00396FD0(s32 a, s8 *p, s8 *q) {
    extern void func_001757E0(s32, s32, s32);
    u8 t; u32 m;
    if (*p != *q) {
        *p = *q; t = 0; m = (u8)(*(volatile s8 *)p * 3); if (((u8 *)p)[6] != 0) { t = ((u8 *)p)[1]; } t += m; func_001757E0(a, 0x19, (u8)t);
    }
}
