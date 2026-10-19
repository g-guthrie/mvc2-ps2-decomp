typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_00240A30(u8 *p)
{
    unsigned int offset;
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x60);
    f32 *c = (f32 *)(p + 0x68);
    f32 *d = (f32 *)(p + 0x6C);

    p[0x209] = 2;
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0 && *(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) = 0;
        p[0x15B] = 0;
    }
    if (*(s16 *)(p + 0x1C) == 0 && p[0x15B] != 0) {
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        p[0x15B] = 0;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        p[0x209] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183D50(p);
        func_001757E0(p, 0x15, 4);
    }
}
