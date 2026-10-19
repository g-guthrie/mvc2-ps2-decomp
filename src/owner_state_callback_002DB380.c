typedef unsigned char u8;
typedef signed short s16;

typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* Both 00183210 and 001834A0 read only x/y. Retail passes this
 * eight-byte offset at the 16-byte-aligned stack address SP+0x20. */
typedef f32 PlanarOffset[2] __attribute__((aligned(16)));
typedef char PlanarOffsetSizeCheck[(sizeof(PlanarOffset) == 8) ? 1 : -1];
extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, void *, int);

void func_002DB380(u8 *p)
{
    PlanarOffset v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    *(u32 *)(p + 0x2F8) = 0x60;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (--*(s16 *)(p + 0x1C) == 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        ++p[6];
        *(s16 *)(p + 0x1C) = 8;
        v[0] = -86.66666412353516f;
        v[1] = 171.42855834960938f;
        func_001830D0(p, v, 1);
    }
}
