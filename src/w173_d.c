typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G24B2F0;
extern G24B2F0 *D_004C2794;

void func_0024B2F0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_0024BA20(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_0024BA20(p);
    if (*(s16 *)(p + 0x1C) == 2) {
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[7]++;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x68) = 0x40555555;
        } else {
            *(u32 *)(p + 0x68) = 0xC0555555;
        }
        func_001757E0(p, 0x15, 4);
    }
}

void func_0024B7C0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_0024BA20(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_0024BA20(p);
    if (*(s16 *)(p + 0x1C) == 2) {
        p[0x1B5] = 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[7]++;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x68) = 0x3F555555;
        } else {
            *(u32 *)(p + 0x68) = 0xBF555555;
        }
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 6);
    }
}
