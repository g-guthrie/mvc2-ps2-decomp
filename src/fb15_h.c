typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B7B40[];
extern f32 D_004B7B30[];

void func_00332920(u8 *p)
{
    extern void func_00332AB0(u8 *);
    extern void func_00332850(u8 *);
    u8 *q;
    f32 *tab;
    s32 i;
    if (p[6] < p[7] - 1) {
        q = (u8 *)D_004B7B40;
        tab = D_004B7B30;
        for (i = 0; i < p[4]; i++) {
            q = q + *(s16 *)q * 4;
        }
        q += 2;
        *(s32 *)(p + 0xD4) = *(s16 *)(q + (p[6] & 0xFF) * 2);
        q += (p[7] - 1) * 2;
        q += p[6] * 2;
        *(s32 *)(p + 0xD8) = *(s16 *)q;
        *(f32 *)(p + 0x50) = tab[*(s16 *)q];
        p[5] = 2;
        func_00332AB0(p);
    } else {
        p[4]++;
        p[4] = (u32)p[4] % 6u;
        p[5] = 0;
        p[6] = 0;
        func_00332850(p);
    }
}
