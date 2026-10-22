typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 *D_004C2840;
extern u32 *D_004C2794;
extern u8 D_004D18EA[];
extern s8 D_004D1914[];
extern s8 D_004D1928[];
extern void func_0011D8F8(void *, s32, s32);

void func_00186A60(u8 *p, u8 n)
{
    u8 old;
    s8 *a2;

    p[0x1E5] = p[0x1E4];
    p[0x1E4] = n;
    if (n != 0x15 && n != 0x1D) {
        old = p[0x1E5];
        if (old == 0x15 || old == 0x1D || old == 0x1E) {
            if (n != 0x1E) {
                if (p[0x269] != 8) p[0x269] = 0;
            }
        }
        if (n == 0x20 || n == 0x1F) p[0x269] = 0;
    } else {
        if (n == 0x15 || n == 0x1D) {
            if (n == 0x15) *(s8 *)(p + 0x28E) = -1;
            if (n == 0x1D) {
                if (p[0x1E5] == 0x15) p[0x269] = 0;
                if (p[0x269] != 6) {
                    if (D_004C2840[0xB0] == 0) {
                        D_004D18EA[p[2]] = 0x10 + (1 << (p[0x1B8] / 2));
                    } else {
                        D_004D18EA[p[2]] = 0x10;
                    }
                    D_004D1914[p[2]] = 1;
                    D_004D1928[p[2]] = 1;
                } else {
                    a2 = &D_004C2840[0xB0];
                    if (D_004C2840[0xB0] == 0) {
                        D_004D18EA[p[2]] |= (1 << (p[0x1B8] / 2));
                    }
                    D_004D1914[p[2]]++;
                    if (*a2 != 0) {
                        if (D_004D1914[p[2]] > 3) D_004D1914[p[2]] = 1;
                    }
                    if (++D_004D1928[p[2]] > 3) D_004D1928[p[2]] = 3;
                }
                func_0011D8F8((u8 *)D_004C2794[p[2] * 3 + 7] + 0x378, 0, 0x68);
            }
        }
    }
}
