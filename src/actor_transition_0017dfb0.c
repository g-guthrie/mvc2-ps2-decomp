typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_00191430(u8 *);
extern void func_0018F730(u8 *);
extern void func_0018EF20(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0017DFB0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        *(s8 *)(p + 0x24E) += 2;
        func_00191430(p);
    }
    *(u8 **)(p + 0x1D0) = (u8 *)((u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184) + (p[0x1B5] & 0x7F) * 28);
    func_0018F730(p);
    *(s8 *)(p + 0x24D) = *(s8 *)(p + 0x246);
    p[5] = 3;
    p[7] = 0;
    p[6] = 0;
    if (*(s16 *)(p + 0x434) != 0)
        p[0x247] = 0x17;
    else {
        p[0x248] = 1;
        p[0x247] = 2;
    }
    p[0x1E6] = *(s8 *)(p + 0x140);
    func_0018EF20(p);
    *(f32 *)(p + 0x6C) = -1.20535707f;
    p[0x20D] = 2;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430))
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x13C] = 1;
    *(f32 *)(p + 0x48) = 0.0f;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(f32 *)(p + 0x118) = 1.0f;
    func_001757E0(p, 13, 0);
}
