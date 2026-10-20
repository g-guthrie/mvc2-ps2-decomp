typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C29AC __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_003859F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_00384C40(u8 *p)
{
    u8 *q;
    if (*(u16 *)D_004C29AC != *(u16 *)((q = *(u8 **)(p + 0x18)) + 0x168)) {
        func_003859F0(p);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (p[0x1B7]) {
        *(s8 *)(p + 0x1B3) = 0;
        if (*(s8 *)(p + 0x1B2) && ((*(s8 *)(p + 0x1B2) & 1) == 0) && p[0x15B]) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(unsigned short *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
            p[0x15B] = 0;
        }
    }
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        (*(u8 **)(p + 0x18))[7] = 2;
    } else if (!*(s8 *)(p + 0x1B3))
        func_001E7F60(p);
}
