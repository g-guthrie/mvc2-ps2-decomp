typedef unsigned char u8;
typedef float f32;

extern f32 D_004F1FC8 __attribute__((section(".data")));
extern f32 D_004F1FCC __attribute__((section(".data")));
extern void func_003DAA40(u8 *);

void func_003288F0(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    if (o[0x1fd] != 1 || o[0x1e4] != 21 || o[0x169] != 21) {
        func_003DAA40(p);
        return;
    }
    if (o[0x168] != 20)
        return;
    if (o[0x1e6] == 0)
        *(f32 *)(o + 0x34) = 40.0f + D_004F1FC8;
    else
        *(f32 *)(o + 0x34) = -40.0f + D_004F1FCC;
}
