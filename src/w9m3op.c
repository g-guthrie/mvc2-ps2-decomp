typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_00633E18;
extern u8 D_00634100[];
s32 func_00423D00(u32 v, s32 n)
{
    s32 sh;
    if (n > 4) {
        return -1;
    }
    if (D_00633E18 + n >= 0x200) {
        return -1;
    }
    sh = 24;
    if (n > 0) {
        do {
            D_00634100[D_00633E18] = v >> sh;
            sh -= 8;
            n--;
            D_00633E18++;
        } while (n > 0);
    }
    D_00634100[D_00633E18] = 0xFF;
    return 0;
}
