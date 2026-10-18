typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;

s32 func_001A1F00(u8 *owner, s32 n, u8 c)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001A1FC0(u8 *);
    s32 i;
    u8 *o;
    if (D_004C27A4 <= n) return 0;
    if (n > 12) n = 12;
    i = 0;
    if (0 < n) do {
        if ((o = func_003DA750(0, 3, 1)) != 0) {
            *(s16 *)(o + 0x26) = 0xC05;
            o[0x23] = i;
            o[0x20] = c;
            *(s16 *)(o + 0x1E) = n;
            *(void (**)(u8 *))(o + 0x10) = func_001A1FC0;
            *(u8 **)(o + 0x18) = owner;
        }
        i++;
    } while (i < n);
    return i;
}


typedef struct { f32 x, y; } E8_36a;
extern E8_36a D_00463A60[];

void func_0036AFF0(u8 *p)
{
    extern void func_0036AA70();
    extern void func_001757E0();
    E8_36a *e;
    f32 k;
    u32 i;
    e = D_00463A60;
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    e += p[0x21];
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) k = e->x;
    else k = -e->x;
    *(f32 *)(p + 0x34) += k;
    *(f32 *)(p + 0x38) += e->y;
    for (i = 0; (u8)i < 8; i = (u8)(i + 1)) func_0036AA70(p, 6, i);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 5);
}
