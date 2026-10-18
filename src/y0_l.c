typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct G {
    u8 pad[0x7C];
    s16 f7c[16];
} G;
extern G *D_004C2794;
extern s32 data_s8_004C0910;
extern s32 D_004C0914;
extern s32 D_004C0918;

void func_00286DC0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = &data_s8_004C0910;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = &D_004C0914;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(s32 **)(p + 0x408) = &D_004C0918;
        p[0x1BB] = 2;
        break;
    }
    {
        u8 t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
    }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

extern s32 D_004C1288, D_004C128C, D_004C1290;

void func_002F28C0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = &D_004C1288;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = &D_004C128C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(s32 **)(p + 0x408) = &D_004C1290;
        p[0x1BB] = 2;
        break;
    }
    {
        u8 t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
    }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
