typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00633E18;
extern u8 D_00634100[];

s32 func_00423DA0(u32 v, s32 n, s32 m) {
    s32 sh;
    if (n >= m || n > 4) return -1;
    if (D_00633E18 + m >= 0x200) return -1;
    sh = 0x18;
    if (n > 0) do {
        D_00634100[D_00633E18] = v >> sh;
        n--;
        sh -= 8;
        D_00633E18++;
    } while (n > 0);
    return 0;
}
