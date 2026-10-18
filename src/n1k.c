typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_0011C458();

s32 func_001208B8(void *a, u32 *p) {
    if (p[2] == 0) {
        p[1] = 0;
        return 0;
    }
    {
        s32 r = func_0011C458();
        p[2] = 0;
        p[1] = 0;
        return r;
    }
}
