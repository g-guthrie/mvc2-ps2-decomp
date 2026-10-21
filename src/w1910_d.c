typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_003ED000(void)
{
    extern s32 func_003DCFE0(s32, s32);
    extern s32 func_003DD030(s32);
    extern void func_003DCD40(s32, s32, s32);
    extern void func_00101218(u8 *, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00104060(s32);
    extern int func_00101540(void *, void *);
    extern void func_00100F00(s32, s32);
    extern void func_003DD020(s32);
    u8 buf[0x60];
    s32 a, b;
    u32 i = 0;
    s32 off;
    a = func_003DCFE0(0x40000, 0);
    b = func_003DD030(a);
    func_003DCD40(b, 0, 0x40000);
    off = 0;
    do {
        func_00101218(buf, 0, 0x10, 0, 0, (s16)off, 0x400, 0x40);
        func_00104060(0);
        func_00101540(buf, (void *)(u32)b);
        func_00100F00(0, 0);
        i++;
        off += 0x40;
    } while (i < 0x10);
    func_003DD020(a);
}

void func_0019EC90(u8 *p)
{
    extern s8 func_00175700(u8 *);
    u8 *g, *o;
    u32 t;
    g = *(u8 **)(p + 0x18);
    o = *(u8 **)(p + 0x14);
    if (o[4] == 1 && p[0x21] != 0 && o[0x20] == 0 && o[0x21] == 2 && *(s8 *)(g + 0x151) != 0) {
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        p[0x31] = o[0x31] - 2;
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
        p[0x13C] = 1;
        if (func_00175700(p) >= 0) return;
    }
    p[0x13C] = 0;
    t = p[4];
    p[4] = t + 1;
}

s32 func_003F3770(s32 *d, u16 *s)
{
    extern void func_003F5540(void *);
    extern u8 D_004BACB0[];
    extern u8 D_004BACF0[];
    s32 w;
    if (s[0] != 0x4D42) {
        func_003F5540(D_004BACB0);
        return 0;
    }
    d[1] = s[9] | (s[10] << 16);
    d[2] = s[11] | (s[12] << 16);
    if (s[14] != 0x18) {
        func_003F5540(D_004BACF0);
        return 0;
    }
    d[5] = 3;
    w = d[1];
    d[3] = w * 3;
    d[6] = 8;
    d[7] = 0x10;
    d[8] = 0xFF;
    d[9] = 8;
    d[10] = 8;
    d[11] = 0xFF;
    d[12] = 8;
    d[13] = 0;
    d[14] = 0xFF;
    d[15] = 0;
    d[16] = 0;
    d[17] = 0;
    d[0] = 0;
    return 1;
}
