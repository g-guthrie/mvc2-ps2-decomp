/* MWCCPS2 3.0.3: -O3,p -sdatathreshold 0 */
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_0062BFE4;
extern u32 D_0062BFE0;
extern void func_003DC950();
extern void func_003ECD00(s32);

u32 func_003DD160(u32 size, s32 align)
{
    u32 p;
    p = D_0062BFE4 + align;
    p = ~(align - 1) & (p - 1);
    if (p + size > D_0062BFE0) {
        func_003DC950();
        for (;;) {
            func_003ECD00(0);
        }
    }
    D_0062BFE4 = p + size;
    return p;
}
