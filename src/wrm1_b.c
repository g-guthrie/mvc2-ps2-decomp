typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;


typedef struct { f32 x, y, z; } V3;

typedef struct {
    u8 pad[0x7C];
    s16 h7c[2];
} PlayerCounts;
extern PlayerCounts *D_004C2794;
extern f32 D_004584F0[];

void func_002A2E80(u8 *p, f32 *out)
{
    extern s32 func_00175700(u8 *);
    extern s32 func_001757E0(u8 *, s32, u8);
    s32 h;

    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) != 0 && *(s8 *)(p + 0x1B2) == 0) {
        *(s8 *)(p + 0x151) = 0;
        if (p[6] != 0) {
            *(s8 *)(p + 0x1B5) = (p[0x1B7] != 0) ? 0x57 : 0x55;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        } else {
            *(s8 *)(p + 0x1B5) = (p[0x1B7] != 0) ? 0x33 : 0x31;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        }
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        p[7]++;
        *(s16 *)(p + 0x1C) = (p[6] != 0) ? 2 : 0;
        *(s16 *)(p + 0x1C) += p[0x1B7];
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? D_004584F0[*(s16 *)(p + 0x1C) * 4] : -D_004584F0[*(s16 *)(p + 0x1C) * 4];
        *(f32 *)(p + 0x68) = (p[0x1E6] != 0) ? D_004584F0[*(s16 *)(p + 0x1C) * 4 + 1] : -D_004584F0[*(s16 *)(p + 0x1C) * 4 + 1];
        *(f32 *)(p + 0x60) = D_004584F0[*(s16 *)(p + 0x1C) * 4 + 2];
        *(f32 *)(p + 0x6C) = D_004584F0[*(s16 *)(p + 0x1C) * 4 + 3];
        out[0] = (f32)(2.0 * (f64)*(f32 *)(p + 0x5C));
        out[1] = (f32)(2.0 * (f64)*(f32 *)(p + 0x60));
        p[0x22] = 0;
        if (p[6] != 0) {
            *(s8 *)(p + 0x1B5) = (p[0x1B7] != 0) ? 0x5A : 0x58;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        } else {
            *(s8 *)(p + 0x1B5) = (p[0x1B7] != 0) ? 0x36 : 0x34;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        }
        func_001757E0(p, 0x15, (p[0x1B7] != 0) ? 3 : 2);
    }
}
