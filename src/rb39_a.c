typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 D_00633E18;
extern u8 D_00634100[];

s32 func_00423B70(u32 v, s32 n, u8 b0, u8 b1, u8 b2, u8 b3)
{
    s32 sh;
    s32 cnt;

    if (n > 8) return -1;
    if (D_00633E18 + n >= 0x200) return -1;
    sh = 0x18;
    cnt = 4;
    while (cnt > 0 && n > 0) {
        D_00634100[D_00633E18] = v >> sh;
        sh -= 8;
        cnt--;
        n--;
        D_00633E18 = D_00633E18 + 1;
    }
    if (n-- > 0) {
        D_00634100[D_00633E18] = b0;
        D_00633E18 = D_00633E18 + 1;
    }
    if (n-- > 0) {
        D_00634100[D_00633E18] = b1;
        D_00633E18 = D_00633E18 + 1;
    }
    if (n-- > 0) {
        D_00634100[D_00633E18] = b2;
        D_00633E18 = D_00633E18 + 1;
    }
    if (n > 0) {
        D_00634100[D_00633E18] = b3;
        D_00633E18 = D_00633E18 + 1;
    }
    D_00634100[D_00633E18] = 0xFF;
    return 0;
}
