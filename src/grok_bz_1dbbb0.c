typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern f32 D_0044E950[];
extern s32 func_00118FA8(f32);
extern void func_001DBC80(u8 *);
extern void func_001DBCD0(u8 *);

void func_001DBBB0(u8 *p)
{
    f32 d;
    s32 a;
    f32 k = 17.142856597900390625f;
    f32 den = 2.142856597900390625f;
    d = k + *(f32 *)(*(u8 **)(p + 0x18) + 0x430) + D_0044E950[p[0x20]] - *(f32 *)(p + 0x38);
    if (d < 0.0f)
        d = -d;
    a = func_00118FA8(d / den) / 16;
    if (a < *(s16 *)(p + 0x1C))
        func_001DBC80(p);
    else {
        *(s16 *)(p + 0x1C) = (s16)a;
        func_001DBCD0(p);
    }
}
