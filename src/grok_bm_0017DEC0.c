typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } Row;
typedef struct { u8 pad[0x184]; Row *rows; } Own;

extern void func_00191430(u8 *);
extern void func_0018F730(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00158C70(u8 *, int);
extern void func_00186CE0(u8 *, int);

void func_0017DEC0(u8 *p)
{
    u8 v;
    Own *o;

    if (p[6] == 0) {
        p[6]++;
        *(s8 *)(p + 0x24E) += 2;
        func_00191430(p);
    }
    {
        u32 n = p[0x1B5];
        o = *(Own **)(p + 0x1DC);
        *(Row **)(p + 0x1D0) = o->rows + (n & 0x7F);
    }
    func_0018F730(p);
    *(u16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    func_001E3A10(p);
    v = (*(u8 **)(p + 0x1D0))[5];
    (*(u8 **)(p + 0x1DC))[0x1B4] = v;
    p[0x1B4] = v;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00158C70(p + 0x34, p[2]);
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00186CE0(p, 0x17);
}
