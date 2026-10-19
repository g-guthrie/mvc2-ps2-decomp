typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0014E770(u8 *);
extern s16 D_00444360[];
extern u16 D_004CB010[];
extern s8 *D_004C2840 __attribute__((section(".sdata")));
extern u32 D_004C27FC __attribute__((section(".sdata")));

void func_001509D0(u8 *p)
{
    s16 div;
    u16 val;
    u32 q;
    u32 rem;
    u8 *par;

    div = D_00444360[(u8)p[0x23]];
    func_0014E770(p);
    par = *(u8 **)(p + 0x18);
    p[0x13C] = *(s8 *)(par + 0x13C);
    *(f32 *)(p + 0x74) = *(f32 *)(par + 0x74);
    val = *(u16 *)((u8 *)D_004CB010 + ((D_004C2840[6] + *(s16 *)(p + 0x1E)) << 2));
    q = val;
    if (div != 0)
        q = (u16)(val / (u16)div);
    rem = (u16)q % 10;
    if ((u8)p[0x23] >= 2) {
        s16 d2 = D_00444360[(u8)p[0x23] + 1];
        if ((u16)(val / (u16)d2) == 0 && rem == 0)
            p[0x13C] = 0;
    }
    *(s16 *)(p + 0xCC) = (s16)(rem + 0x25);
    *(u32 *)(p + 0x84) = D_004C27FC;
}
