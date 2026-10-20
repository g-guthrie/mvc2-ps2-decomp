typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[8]; } G;
extern G *D_004C2794;
extern void func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002C8230(u8 *p, u8 *q)
{
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x60);
    f32 *c = (f32 *)(p + 0x68);
    f32 *d = (f32 *)(p + 0x6C);

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (q[2] == 0 && *(s8 *)(p + 0x1B2)) {
        q[2] = 1;
        func_001E3210(p, 3);
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[0x1B5] = p[0x1B7] ? 0x2B : 0x29;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183D50(p);
        func_001757E0(p, 0x15, 4);
    }
}
