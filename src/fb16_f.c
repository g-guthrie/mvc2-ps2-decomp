typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern s32 D_004F1CB8[];

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

static void func_002555E0(u8 *p) {
    if (S(p, 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}

void func_0025A820(u8 *p)
{
    extern void func_001266A0(u8 *, s32, s32);
    f32 c;
    u32 t;
    func_002555E0(p);
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    D_004F1CB8[0] = 2;
    t = p[6];
    p[6] = t + 1;
    func_001266A0(p, 1, 0xD);
    *(f32 *)(p + 0x34) = (D_004F1FC8[0] + D_004F1FCC[0]) / 2.0f;
    c = p[0x1E6] ? -133.3333282470703f : 133.3333282470703f;
    *(f32 *)(p + 0x34) += c;
}
