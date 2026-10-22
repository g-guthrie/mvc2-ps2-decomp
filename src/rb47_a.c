typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G47;
extern G47 *D_004C2794;

void func_002BB680(u8 *p)
{
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s16 t;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        s16 u;
        *(s16 *)(p + 0x1C) = 1;
        { s32 a = p[0x25]; a = a * 9; a += *(s16 *)(p + 0x1E); func_00176160(p, 0, a, 1); }
        u = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = u;
        if (u < 0)
            *(s16 *)(p + 0x1E) = 8;
    }
    func_00175700(p);
    if ((*(u16 *)(p + 0x1C2) & 0x80) != 0) {
        if (*(s8 *)(p + 0x151) == 0) {
            u32 q = p[6];
            p[6] = q + 1;
            *(u16 *)(p + 0x1C2) = 0;
            func_00175C00(p, 0);
        }
        return;
    }
    func_00175C00(p, 0);
    if (p[0x1B7] != 0) {
        u32 q = p[6];
        p[6] = q + 1;
        p[0x20D] = 1;
        p[0x1B5] = 0x61;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 0x1F);
    } else {
        u32 q = p[6];
        p[6] = q + 2;
        p[0x1B5] = 0x46;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 0x17);
    }
}
