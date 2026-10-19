typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern u8 *func_001B3E30(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_0026A9D0(u8 *p)
{
    u8 *r;
    u32 g = 0xBF4DB6DB;
    int sixteen = 16;
    u32 vx = 0xC17D5555;
    u32 vz = 0x3EA00000;
    unsigned anim;
    p[6]++;
    *(s16 *)(p + 0x1C) = sixteen;
    *(u32 *)(p + 0x6C) = g;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x5C) = vx;
    *(u32 *)(p + 0x68) = vz;
    anim = 5;
    if (*(s16 *)(p + 0x140)) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    if (p[0x22] & 1) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        anim = 6;
    }
    func_001757E0(p, 2, anim & 0xFF);
    r = func_001B3E30(p, 0xF, 8);
    if (r) {
        *(f32 *)(r + 0x5C) = *(f32 *)(p + 0x5C);
        *(s16 *)(r + 0x140) = *(s16 *)(p + 0x140);
        r[0x22] = p[0x22];
    }
    func_001E3210(p, 0x1E);
    func_001E3210(p, 0x17);
    p[0x206] = 10;
    p[0x207] = 10;
}
