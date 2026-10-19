typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

typedef struct { u8 *ptr; s32 b; s32 c; } E12;
extern E12 D_004D18B8[];
extern s32 func_001E8310(u8 *, u8 *, s16, s16);

s32 func_00252C80(u8 *p)
{
    u8 *s0;
    u8 *s1;
    s16 *s3;
    s16 id;
    u16 v;

    s0 = D_004D18B8[p[2]].ptr;
    s1 = *(u8 **)(p + 0x1D4);
    s3 = *(s16 **)(s0 + 0x1D4);
    id = (s16)s1[2];
    if (func_001E8310(p, s0, id, s3[2]) != 0)
        return 1;
    id = (s16)s1[2];
    if (func_001E8310(p, s0, id, s3[3]) != 0)
        return 1;
    id = (s16)s1[2];
    if (func_001E8310(p, s0, id, s3[4]) != 0)
        return 1;
    v = *(u16 *)(s3 + 5);
    if (v != 0) {
        id = (s16)s1[2];
        if (func_001E8310(p, s0, id, (s16)(v & 0x1FFF)) != 0)
            return 1;
    }
    return 0;
}
