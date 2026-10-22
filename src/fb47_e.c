typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3E90;
extern V3E90 D_00440620[];
extern V3E90 D_00440650[];

void func_0013EE90(u8 *p)
{
    extern void func_003DAA40(u8 *);
    extern void func_00416AE0(s32);
    extern void func_00416CC0(s32);
    extern void func_003DD260(f32 *);
    extern void func_003DDB60(f32 *, f32, f32, f32);
    extern void func_003DE160(f32 *, f32 *, f32 *);
    extern void func_003DDB70(f32 *, f32);
    extern void func_003DDC30(f32 *, f32);
    extern void func_003DDD00(f32 *, f32);
    f32 a[16];
    f32 b[16];
    s16 h;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        *(s16 *)(p + 0x1C) = 0x40;
        *(V3E90 *)(p + 0x34) = D_00440620[p[0x20]];
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h == 0) {
            func_003DAA40(p);
            return;
        }
    }
    func_00416AE0(0);
    func_003DD260(a);
    func_003DD260(b);
    func_003DDB60(b, *(f32 *)(p + 0x5C), 0.0f, 0.0f);
    func_003DE160(a, a, b);
    func_003DD260(b);
    func_003DDB70(b, 0.017453292f * D_00440650[p[0x20]].x);
    func_003DDC30(b, 0.017453292f * D_00440650[p[0x20]].y);
    func_003DDD00(b, 0.017453292f * D_00440650[p[0x20]].z);
    func_003DE160(a, a, b);
    func_003DD260(b);
    func_003DDB60(b, *(f32 *)(p + 0x34), *(f32 *)(p + 0x38), *(f32 *)(p + 0x3C));
    func_003DE160(a, a, b);
    *(f32 *)(p + 0x88) = a[0];
    *(f32 *)(p + 0x8C) = a[1];
    *(f32 *)(p + 0x90) = a[2];
    *(f32 *)(p + 0x94) = a[3];
    *(f32 *)(p + 0x98) = a[4];
    *(f32 *)(p + 0x9C) = a[5];
    *(f32 *)(p + 0xA0) = a[6];
    *(f32 *)(p + 0xA4) = a[7];
    *(f32 *)(p + 0xA8) = a[8];
    *(f32 *)(p + 0xAC) = a[9];
    *(f32 *)(p + 0xB0) = a[10];
    *(f32 *)(p + 0xB4) = a[11];
    *(f32 *)(p + 0xB8) = a[12];
    *(f32 *)(p + 0xBC) = a[13];
    *(f32 *)(p + 0xC0) = a[14];
    *(f32 *)(p + 0xC4) = a[15];
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0xB8);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0xBC);
    *(f32 *)(p + 0x3C) = *(f32 *)(p + 0xC0);
    func_00416CC0(1);
}
