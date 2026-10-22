typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G32e;
extern G32e *D_004C2794;
extern u8 D_0045A5E0[];

void func_002D66B0(u8 *p) {
    extern void func_001861B0(u8 *);
    extern void func_001757E0(u8 *, u8, u8), func_001D0500(u8 *, s32), func_001E3710(u8 *, u8);
    u8 idx;
    func_001861B0(p);
    *(u8 **)(p + 0x408) = D_0045A5E0 + (p[0x1FC] * 4 + p[0x212] * 12);
    p[0x1BB] = p[0x1FC];
    idx = p[0x20D] * 6 + p[0x212] * 3 + p[0x1FC];
    if ((*(u16 *)(p + 0x20E) & 0x800) != 0 && p[0x212] == 0 && p[0x1FC] == 2 && p[0x20D] == 0) {
        p[0x1B5] = 0x12;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x14, 3);
        func_001D0500(p, 1);
    } else {
        p[0x1B5] = idx;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, (p[0x20D] << 1) + 7 + p[0x212], p[0x1FC]);
    }
    func_001E3710(p, p[0x1FC] + 0x14);
}
