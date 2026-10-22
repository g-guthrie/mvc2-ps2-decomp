typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } GC;

extern GC *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_00324330(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00324A30(u8 *);
    extern void func_00324A00(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00158C70(f32 *, s32);
    f32 v[4];
    s32 m;
    u32 a;
    if (func_00175700(p) < 0) {
        func_00324A30(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0 && *(s32 *)(p + 0x2D8) > 0) {
        if ((*(s8 *)(p + 0x539) != 0 && *(s8 *)(p + 0x1B2) != 0) || (*(u16 *)(p + 0x362) & 0x360) || (*(u16 *)(p + 0x366) & 0x360)) {
            p[0x151] = 0;
            *(u16 *)(p + 0x366) = 0;
            *(s32 *)(p + 0x2D8) = *(s32 *)(p + 0x2D8) - 30;
            func_00324A00(p);
            a = *(u16 *)(p + 0x354);
            m = *(s16 *)(p + 0x140);
            if (a & 0x800) {
                m = 0;
            }
            if (a & 0x400) {
                m = 1;
            }
            p[0x1E6] = m;
            *(s16 *)(p + 0x140) = (u8)m;
            p[0x1B5] = 0x7D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            { u32 t = *(u16 *)(p + 0x1C0); *(u16 *)(p + 0x1C0) = t | 0x800; }
            func_001757E0(p, 0x16, 0xD);
        }
    }
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        D_004F1F45[0] = 1;
        D_004F1F46[0] = 1;
        v[0] = -300.0f;
        if (*(s16 *)(p + 0x140) != 0) {
            v[0] = -v[0];
        }
        v[0] += *(f32 *)(p + 0x34);
        v[1] = *(f32 *)(p + 0x38);
        func_00158C70(v, -1);
    }
}
