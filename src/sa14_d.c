typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 a, b, c; } E12;
extern E12 D_00633670[];
extern s32 D_00633694[], D_0063369C[], D_006336A0[], D_00633690[];

s32 func_00419730(s32 a, s32 b)
{
    extern s32 func_00110DF0(s32, s32);
    s32 i;
    if (D_00633694[0] != 0) return -1;
    if (a >= 2) return -1;
    if (b > 0) return -1;
    if (((s32 *)(D_00633670 + (a + b)))[2] == 1) return -1;
    i = 0;
    do {
        if (func_00110DF0(a, b) == 0) {
            D_0063369C[0] = a;
            D_00633694[0] = 16;
            D_006336A0[0] = b;
            if (D_00633690[0] == 0) D_00633690[0] = 5;
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
