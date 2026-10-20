typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_001E7F60(u8 *);

void func_00380E10(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    if (q[4] >= 2) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (*(s16 *)(q + 0x140) == 0)
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + -96.666664f;
    else
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - -96.666664f;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 180.0f;
    if (!*(s8 *)(q + 0x151)) {
        p[4]++;
        *(f32 *)(p + 0x50) = 1.0f;
        func_001757E0(p, 0x17, 1);
        return;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        if (p[0x20])
            *(f32 *)(p + 0x50) = 2.0f;
        else
            *(f32 *)(p + 0x50) = 1.0f;
    }
    if (p[0x20] && *(s8 *)(p + 0x150)) {
        p[0x150] = 0;
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_001E7F60(p);
}
