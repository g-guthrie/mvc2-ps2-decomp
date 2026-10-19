typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00448BC0[];
extern void func_00175C00(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0017C7F0(u8 *);
extern void func_00191210(u8 *);

void func_0017C4C0(u8 *p)
{
    p[0x201] = 2;
    p[0x208] = 2;
    p[0x209] = 2;
    jtbl_00448BC0[p[6]](p);
}

void func_0017C4F0(u8 *p)
{
    p[0x215] = 0;
    p[7] = 0;
    *(s32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(s32 *)(p + 0x118) = 0x3F800000;
    func_00175C00(p, 1);
    func_001E3210(p, 0x2B);
    if (p[0x20D] == 2) {
        p[6] = 1;
        func_001757E0(p, 13, 30);
        if (p[0x1E5] == 0x15 || p[0x1E5] == 0x1D) {
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
    } else {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[6] = 3;
        func_0017C7F0(p);
    }
    func_00191210(p);
}
